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

    m_background.setTexture(&getResource().getTexture("harry_potter"));
    m_background.setSize(sf::Vector2f(m_background.getTexture()->getSize()));
    m_background.setOrigin(m_background.getSize() / 2.0f);
    m_background.setPosition(wSize / 2.0f);

    m_scoreValue = 0;

    m_score.setFont(getResource().getFont("nathanFont"));
    m_score.setCharacterSize(50);
    m_score.setPosition({wSize.x * 0.8, wSize.y * 0.1});

    m_timer.setString("Timer : n/a");
    m_timer.setFont(getResource().getFont("nathanFont"));
    m_timer.setCharacterSize(50);
    m_timer.setPosition({wSize.x * 0.1, wSize.y * 0.1});

    m_backgroundColor.setSize({1920, 1080});
    m_backgroundColor.setFillColor(sf::Color(74, 141, 132,255));
}

void RoomScene::restart()
{
    sf::Vector2f wSize(info::getWindowSize());

    m_riddles.clear();

    m_riddles.push_back(std::make_unique<ClickRiddle>("What is the name of the main character of Harry Potter?", sf::IntRect(0, 0, 100, 100)));
    m_riddles.push_back(std::make_unique<ClickRiddle>("What dinosaur has 500 teeth", sf::IntRect(0, 0, 100, 100)));

    for (auto& riddle : m_riddles)
        riddle->setPosition({wSize.x * 0.5, wSize.y * 0.95});

    m_currentRiddleIndex = 0;
    m_currentRiddle = std::move(m_riddles[m_currentRiddleIndex]);

    m_score.setString("Score : " + std::to_string(m_scoreValue) + " / " + std::to_string(m_riddles.size()));
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

void RoomScene::update(float dt)
{
    m_currentRiddle->update();
    if (!m_currentRiddle->isDisplaying()) {
        m_timer.setString("Timer : " + std::to_string((int)m_currentRiddle->getRemainingTime()));
    }
    if (m_currentRiddle->isFinished()) {
        m_scoreValue++;
        m_currentRiddleIndex++;
        m_score.setString("Score : " + std::to_string(m_scoreValue) + " / " + std::to_string(m_riddles.size()));
        if (m_riddles.size() >= m_currentRiddleIndex) {
            m_currentRiddle = std::move(m_riddles[m_currentRiddleIndex]);
            m_riddles.erase(m_riddles.begin());
        } else if (RoomScene* nextScene = dynamic_cast<RoomScene*>(SceneManager::getInstance().getNextScene().get())) {
            SceneManager::getInstance().nextScene();
        } else {
            SceneManager::getInstance().setCurrentScene("Main Menu");
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
