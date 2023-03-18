/*
** EPITECH PROJECT, 2023
** EpitechJam2022
** File description:
** Room1
*/

#include "Room1.hpp"

#include "UIText.hpp"
#include "Button.hpp"
#include "ResourceManager.hpp"
#include "SceneManager.hpp"
#include "info.hpp"
#include "ClickRiddle.hpp"

namespace jam {

Room1::Room1()
{
    ui::UIText* title = ((ui::UIText*)m_uiElements.at("Title").get());
    title->setString("Room 1");

    sf::Vector2f wSize(info::getWindowSize());

    m_background.setTexture(&getResource().getTexture("harry_potter"));
    m_background.setSize(sf::Vector2f(m_background.getTexture()->getSize()));
    m_background.setOrigin(m_background.getSize() / 2.0f);
    m_background.setPosition(wSize / 2.0f);
}

void Room1::restart()
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

Room1::~Room1()
{
}

void Room1::handleEvent(sf::Event& event, sf::RenderWindow& window)
{
    RoomScene::handleEvent(event, window);
}

void Room1::update(float dt)
{
    RoomScene::update(dt);
}

void Room1::render(sf::RenderTarget& target)
{
    RoomScene::render(target);
}

}
