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

namespace jam {

RoomScene::RoomScene()
{
    m_uiElements["Title"] = std::make_shared<ui::UIText>();

    sf::Vector2f wSize(info::getWindowSize());

    ui::UIText* title = ((ui::UIText*)m_uiElements.at("Title").get());
    title->setString("Room 1");
    title->setFont(getResource().getFont("nathanFont"));
    title->setCharacterSize(100);
    title->setPosition({wSize.x * 0.5, wSize.y * 0.02});
    title->setOrigin(title->getGlobalBounds().width / 2, title->getGlobalBounds().height / 2);

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
    m_backgroundColor.setFillColor(sf::Color(74, 141, 132,255));
}

void RoomScene::restart()
{
    m_scoreValue = 0;
    m_riddles.clear();
}

RoomScene::~RoomScene()
{
}

void RoomScene::handleEvent(sf::Event& event, sf::RenderWindow& window)
{
    for (auto& [key, element] : m_uiElements) {
        element->handleEvent(event, window);
    }
    m_currentRiddle->handleEvent(event, window);
}

void RoomScene::stop()
{
    if (m_music != nullptr) {
        m_music->stop();
    }
}

void RoomScene::update(float dt)
{
    float remainingTime = m_currentRiddle->getRemainingTime();

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
        } else if (RoomScene* nextScene = dynamic_cast<RoomScene*>(SceneManager::getInstance().getNextScene().get())) {
            SceneManager::getInstance().nextScene();
        } else {
            SceneManager::getInstance().setCurrentScene("Main Menu");
        }
    }

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
}

}
