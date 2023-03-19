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
#include "InputRiddle.hpp"

namespace jam {

Room1::Room1()
{
    ui::Text* title = ((ui::Text*)m_uiElements.at("Title").get());
    title->setString("Room 1");

    m_music = &ResourceManager::getInstance().getMusic("harry_potter");
    m_music->setVolume(80);

    sf::Vector2f wSize(info::getWindowSize());

    m_background.setTexture(&getResource().getTexture("harry_potter"));
    m_background.setSize(sf::Vector2f(m_background.getTexture()->getSize()));
    m_background.setOrigin(m_background.getSize() / 2.0f);
    m_background.setPosition(wSize / 2.0f);
}

void Room1::restart()
{
    sf::Vector2f wSize(info::getWindowSize());

    RoomScene::restart();

    m_riddles.push_back(std::make_unique<ClickRiddle>("Where is the object that wizards use to fly?", sf::IntRect(730, 713, 120, 40)));
    m_riddles.push_back(std::make_unique<InputRiddle>("Which house could this room belong to?", "Slytherin"));
    m_riddles.push_back(std::make_unique<InputRiddle>("What is the name of the strongest unforgivable spell?", "Avada Kedavra"));
    m_riddles.push_back(std::make_unique<InputRiddle>("What is the name of the sport most practiced by wizards?", "Quidditch"));
    m_riddles.push_back(std::make_unique<InputRiddle>("What is the name of the train used to get to Hogwarts?", "Hogwarts Express"));
    m_riddles.push_back(std::make_unique<InputRiddle>("What is the name of the owl belonging to Harry?", "Hedwig"));
    m_riddles.push_back(std::make_unique<InputRiddle>("What animal is used to send letters in the wizarding world?", "Owl"));
    m_riddles.push_back(std::make_unique<InputRiddle>("What is the name of the famous spell used to levitate an object/person?", "Wingardium Leviosa"));
    m_riddles.push_back(std::make_unique<InputRiddle>("What is the name of the most famous prison in the wizarding world located on an island?", "Azkaban"));


    for (auto& riddle : m_riddles)
        riddle->setPosition({wSize.x * 0.5, wSize.y * 0.95});

    m_nbRiddles = m_riddles.size();
    m_currentRiddleIndex = 0;
    m_currentRiddle = std::move(m_riddles[m_currentRiddleIndex]);

    m_score.setString("Score : " + std::to_string(m_scoreValue) + " / " + std::to_string(m_nbRiddles));
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
