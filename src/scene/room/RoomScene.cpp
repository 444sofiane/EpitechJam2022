/*
** EPITECH PROJECT, 2023
** EpitechJam2022
** File description:
** RoomScene
*/

#include "RoomScene.hpp"

#include "UIText.hpp"
#include "Button.hpp"
#include "ResourceManager.hpp"
#include "SceneManager.hpp"
#include "info.hpp"
#include "ClickRiddle.hpp"
#include "audio.hpp"
#include "Clock.hpp"
#include <sstream>
#include <iomanip>

namespace jam {

RoomScene::RoomScene()
: m_summaryMenuButton(getResource().getTexture("generic_button"), "To Menu")
, m_summaryNextButton(getResource().getTexture("generic_button"), "Next Level")
, m_summaryRetryButton(getResource().getTexture("generic_button"), "Retry")
{
    m_uiElements["Title"] = std::make_shared<ui::Text>();

    m_summaryMenuButton.setPosition({info::getWindowSize().x * 0.5, info::getWindowSize().y * 0.5});
    m_summaryMenuButton.setBaseScale(3.0f, 3.0f);
    m_summaryMenuButton.getLabel().setFont(getResource().getFont("nathanFont"));
    m_summaryMenuButton.getLabel().setCharacterSize(50);
    m_summaryMenuButton.setFunction([] { SceneManager::getInstance().setCurrentScene("Main Menu"); });

    m_summaryNextButton.setPosition({info::getWindowSize().x * 0.5, info::getWindowSize().y * 0.6});
    m_summaryNextButton.setBaseScale(3.0f, 3.0f);
    m_summaryNextButton.getLabel().setFont(getResource().getFont("nathanFont"));
    m_summaryNextButton.getLabel().setCharacterSize(50);
    m_summaryNextButton.setFunction([] {
        if (RoomScene* nextScene = dynamic_cast<RoomScene*>(SceneManager::getInstance().getNextScene().get())) {
            SceneManager::getInstance().nextScene();
        } else {
            SceneManager::getInstance().setCurrentScene("Main Menu");
        }
    });

    m_summaryRetryButton.setPosition({info::getWindowSize().x * 0.5, info::getWindowSize().y * 0.7});
    m_summaryRetryButton.setBaseScale(3.0f, 3.0f);
    m_summaryRetryButton.getLabel().setFont(getResource().getFont("nathanFont"));
    m_summaryRetryButton.getLabel().setCharacterSize(50);
    m_summaryRetryButton.setFunction([] { SceneManager::getInstance().getCurrentScene()->restart(); });

    m_transition = trans::Curtains(getResource().getTexture("curtains"), sf::Vector2f(1, 0), 1.5f);

    sf::Vector2f wSize(info::getWindowSize());

    ui::Text* title = ((ui::Text*)m_uiElements.at("Title").get());
    title->setString("Room 1");
    title->setFont(getResource().getFont("nathanFont"));
    title->setCharacterSize(100);
    title->setPosition({wSize.x * 0.5, wSize.y * 0.02});
    title->setOrigin(title->getGlobalBounds().width / 2, title->getGlobalBounds().height / 2);

    m_mehSound.setBuffer(getResource().getSoundBuffer("meh"));
    m_mehSound.setVolume(100);

    m_failSound.setBuffer(getResource().getSoundBuffer("lose"));
    m_failSound.setVolume(100);

    m_successSound.setBuffer(getResource().getSoundBuffer("clapping"));
    m_successSound.setVolume(50);

    m_tickSound.setBuffer(getResource().getSoundBuffer("tick"));
    m_tickSound.setVolume(100);

    m_validateSound.setBuffer(getResource().getSoundBuffer("valid"));
    m_validateSound.setVolume(100);

    m_invalidSound.setBuffer(getResource().getSoundBuffer("invalid"));
    m_invalidSound.setVolume(100);

    m_tickSoundTimer = Clock::getInstance().getElapsedTime().asSeconds();

    m_scoreValue = 0;
    m_nbRiddles = 0;

    m_score.setFont(getResource().getFont("nathanFont"));
    m_score.setCharacterSize(50);
    m_score.setPosition({wSize.x * 0.8, wSize.y * 0.1});

    m_timer.setString("Timer : n/a");
    m_timer.setFont(getResource().getFont("nathanFont"));
    m_timer.setCharacterSize(50);
    m_timer.setPosition({wSize.x * 0.1, wSize.y * 0.1});

    m_backgroundColor.setSize(wSize);
    m_backgroundColor.setFillColor(sf::Color(74, 141, 132, 255));

    m_summaryBackground.setSize({800.f, 600.f});
    m_summaryBackground.setFillColor(sf::Color(0, 0, 0, 230));
    m_summaryBackground.setPosition({wSize.x * 0.5f, wSize.y * 0.5f});
    m_summaryBackground.setOrigin(m_summaryBackground.getSize().x / 2, m_summaryBackground.getSize().y / 2);
    m_summaryBackground.setOutlineColor(sf::Color::Black);
    m_summaryBackground.setOutlineThickness(4);

    m_summaryScore.setFont(getResource().getFont("nathanFont"));
    m_summaryScore.setCharacterSize(50);
    m_summaryScore.setPosition({wSize.x * 0.5, wSize.y * 0.4});

    m_summaryComment.setFont(getResource().getFont("nathanFont"));
    m_summaryComment.setCharacterSize(50);
    m_summaryComment.setPosition({wSize.x * 0.5, wSize.y * 0.3});
}

void RoomScene::restart()
{
    m_scoreValue = 0;
    m_totalTime = 0;
    m_showSummary = false;
    m_riddles.clear();
    m_transition.restart();
    m_summaryTimer = Clock::getInstance().getElapsedTime().asSeconds();
}

RoomScene::~RoomScene()
{
}

void RoomScene::handleEvent(sf::Event& event, sf::RenderWindow& window)
{
    if (!m_transition.isDone())
        return;

    for (auto& [key, element] : m_uiElements) {
        element->handleEvent(event, window);
    }

    if (m_showSummary) {
        m_summaryMenuButton.handleEvent(event, window);
        m_summaryNextButton.handleEvent(event, window);
        m_summaryRetryButton.handleEvent(event, window);
        return;
    }

    m_currentRiddle->handleEvent(event, window);
}

void RoomScene::stop()
{
    if (m_music != nullptr) {
        m_music->stop();
    }
}

void RoomScene::playEndSound()
{
    float scorePercent = (float)m_scoreValue / (float)m_nbRiddles;

    if (scorePercent >= 0.7) {
        m_successSound.play();
    } else if (scorePercent > 0.4) {
        m_mehSound.play();
    } else {
        m_failSound.play();
    }
}

void RoomScene::update(float dt)
{
    float remainingTime = m_currentRiddle->getRemainingTime();

    if (!m_transition.isDone()) {
        m_transition.update(dt);
        return;
    }

    if (m_music != nullptr && m_music->getStatus() != sf::SoundSource::Status::Playing) {
        m_music->play();
    }

    if (m_currentRiddleIndex >= m_nbRiddles) {
        if (Clock::getInstance().getElapsedTime().asSeconds() - m_summaryTimer > 1 && !m_showSummary) {

            playEndSound();

            m_timer.setString("Timer : n/a");

            std::stringstream stream;
            stream << std::fixed << std::setprecision(2) << m_totalTime;
            std::string time = stream.str();

            m_summaryComment.setString("You have finished the room in " + time + " seconds");
            m_summaryComment.setOrigin(m_summaryComment.getGlobalBounds().width / 2,
                m_summaryComment.getGlobalBounds().height / 2);

            m_summaryScore.setString("Score : " + std::to_string(m_scoreValue) + " / " + std::to_string(m_nbRiddles));
            m_summaryScore.setOrigin(m_summaryScore.getGlobalBounds().width / 2,
                m_summaryScore.getGlobalBounds().height / 2);

            m_showSummary = true;
            m_summaryTimer = Clock::getInstance().getElapsedTime().asSeconds();
        }
        return;
    }

    m_currentRiddle->update();
    if (!m_currentRiddle->isDisplaying()) {
        m_timer.setString("Timer : " + std::to_string((int)remainingTime));
    }
    if (m_currentRiddle->isFinished() != 0) {
        if (m_currentRiddle->isFinished() == 1) {
            audio::modulatePitch(m_validateSound, 0.95, 1.05);
            m_validateSound.play();
            m_scoreValue++;
        } else {
            audio::modulatePitch(m_invalidSound, 0.95, 1.05);
            m_invalidSound.play();
        }
        m_currentRiddleIndex++;
        m_score.setString("Score : " + std::to_string(m_scoreValue) + " / " + std::to_string(m_nbRiddles));
        if (m_nbRiddles > m_currentRiddleIndex) {
            m_timer.setString("Timer : n/a");
            m_currentRiddle = std::move(m_riddles[m_currentRiddleIndex]);
            if (m_currentRiddle == nullptr) {
                std::cout << "nullptr" << std::endl;
                std::cout << m_currentRiddleIndex << std::endl;
            }
            remainingTime = m_currentRiddle->getRemainingTime();
        } else {
            m_summaryTimer = Clock::getInstance().getElapsedTime().asSeconds();
        }
    }

    m_totalTime += dt;

    if (remainingTime > 0 && !m_currentRiddle->isDisplaying()) {
        if (Clock::getInstance().getElapsedTime().asSeconds() - m_tickSoundTimer > 1) {
            m_tickSoundTimer = Clock::getInstance().getElapsedTime().asSeconds();
            audio::modulatePitch(m_tickSound, 0.95, 1.05);
            m_tickSound.play();
        }
    }
}

void RoomScene::render(sf::RenderTarget& target)
{
    target.draw(m_backgroundColor);
    target.draw(m_background);
    m_currentRiddle->render(target);
    for (auto& [key, element] : m_uiElements) {
        element->render(target);
    }
    target.draw(m_timer);
    target.draw(m_score);

    if (m_showSummary) {
        target.draw(m_summaryBackground);
        m_summaryMenuButton.render(target);
        m_summaryNextButton.render(target);
        m_summaryRetryButton.render(target);
        target.draw(m_summaryComment);
        target.draw(m_summaryScore);
    }

    if (!m_transition.isDone())
        m_transition.render(target);
}

}
