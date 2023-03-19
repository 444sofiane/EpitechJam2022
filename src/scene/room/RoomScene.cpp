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
{
    m_uiElements["Title"] = std::make_shared<ui::Text>();

    m_transition = trans::Curtains(getResource().getTexture("curtains"), sf::Vector2f(1, 0), 1.5f);

    sf::Vector2f wSize(info::getWindowSize());

    ui::Text* title = ((ui::Text*)m_uiElements.at("Title").get());
    title->setString("Room 1");
    title->setFont(getResource().getFont("nathanFont"));
    title->setCharacterSize(100);
    title->setPosition({wSize.x * 0.5, wSize.y * 0.02});
    title->setOrigin(title->getGlobalBounds().width / 2, title->getGlobalBounds().height / 2);
    title->setOutlineColor(sf::Color::Black);
    title->setOutlineThickness(2);

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
    m_score.setOutlineColor(sf::Color::Black);
    m_score.setOutlineThickness(2);

    m_timer.setString("Timer : n/a");
    m_timer.setFont(getResource().getFont("nathanFont"));
    m_timer.setCharacterSize(50);
    m_timer.setPosition({wSize.x * 0.1, wSize.y * 0.1});
    m_timer.setOutlineColor(sf::Color::Black);
    m_timer.setOutlineThickness(2);

    m_backgroundColor.setSize(wSize);
    m_backgroundColor.setFillColor(sf::Color(74, 141, 132, 255));
}

void RoomScene::restart()
{
    m_scoreValue = 0;
    m_totalTime = 0;
    m_showSummary = false;
    m_riddles.clear();
    m_transition.restart();
    m_summaryScene.restart();
    m_pauseScene.restart();
}

RoomScene::~RoomScene()
{
}

void RoomScene::handleEvent(sf::Event& event, sf::RenderWindow& window)
{
    if (!m_transition.isDone())
        return;

    if (m_pauseScene.isOpen()) {
        m_pauseScene.handleEvent(event, window);
        return;
    }

    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
        if (m_currentRiddle != nullptr)
            m_currentRiddle->stopSound();
        m_pauseScene.open();
        return;
    }

    for (auto& [key, element] : m_uiElements) {
        element->handleEvent(event, window);
    }

    if (m_showSummary) {
        m_summaryScene.handleEvent(event, window);
        return;
    }

    m_currentRiddle->handleEvent(event, window);
}

void RoomScene::stop()
{
    if (m_music != nullptr) {
        m_music->stop();
    }
    m_summaryScene.stop();
    m_pauseScene.stop();

    m_tickSound.stop();
    if (m_currentRiddle != nullptr)
        m_currentRiddle->stopSound();
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

    if (m_pauseScene.isOpen()) {
        m_pauseScene.update(dt);
        return;
    }

    if (m_music != nullptr && m_music->getStatus() != sf::SoundSource::Status::Playing) {
        m_music->play();
    }

    if (m_currentRiddleIndex >= m_nbRiddles) {
        if (Clock::getInstance().getElapsedTime().asSeconds() - m_summaryTimer > 1) {
            if (!m_showSummary) {
                m_showSummary = true;
                m_timer.setString("Timer : n/a");
                playEndSound();
                m_summaryScene.setNbRiddles(m_nbRiddles);
                m_summaryScene.setScore(m_scoreValue);
                m_summaryScene.setTotalTime(m_totalTime);
            }
            m_summaryScene.update(dt);
        }
        return;
    }

    m_currentRiddle->update();
    if (!m_currentRiddle->isDisplaying()) {
        m_timer.setString("Timer : " + std::to_string((int)remainingTime));
    } else if (!m_currentRiddle->isSoundPlaying()) {
        m_currentRiddle->resumeSound();
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

    if (m_showSummary)
        m_summaryScene.render(target);

    if (m_pauseScene.isOpen()) {
        m_pauseScene.render(target);
    }

    if (!m_transition.isDone())
        m_transition.render(target);
}

}
