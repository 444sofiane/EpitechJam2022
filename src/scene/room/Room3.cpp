/*
** EPITECH PROJECT, 2023
** EpitechJam2022
** File description:
** Room3
*/

#include "Room3.hpp"

#include "UIText.hpp"
#include "Button.hpp"
#include "ResourceManager.hpp"
#include "SceneManager.hpp"
#include "info.hpp"
#include "ClickRiddle.hpp"
#include "InputRiddle.hpp"

namespace jam {

Room3::Room3()
{
    ui::Text* title = ((ui::Text*)m_uiElements.at("Title").get());
    title->setString("Room 3");

    m_music = &ResourceManager::getInstance().getMusic("toy_story");
    m_music->setVolume(80);

    sf::Vector2f wSize(info::getWindowSize());

    m_background.setTexture(&getResource().getTexture("toy_story"));
    m_background.setSize(sf::Vector2f(m_background.getTexture()->getSize()));
    m_background.setOrigin(m_background.getSize() / 2.0f);
    m_background.setPosition(wSize / 2.0f);
}

void Room3::restart()
{
    sf::Vector2f wSize(info::getWindowSize());

    RoomScene::restart();

    m_riddles.push_back(std::make_unique<ClickRiddle>("Where is the bravest Space Ranger?", sf::IntRect(620, 440, 30, 40)));
    m_riddles.push_back(std::make_unique<InputRiddle>("How many cars are there in this room?", "7"));
    m_riddles.push_back(std::make_unique<ClickRiddle>("Find Bayonne", sf::IntRect(1020, 810, 50, 60)));
    m_riddles.push_back(std::make_unique<InputRiddle>("What is the name of the game console used by the pig?", "NES"));
    m_riddles.push_back(std::make_unique<InputRiddle>("In which country Buzz was built?", "Taiwan"));
    m_riddles.push_back(std::make_unique<ClickRiddle>("\" a visitor ... from elsewhere ooooh \"", sf::IntRect(1171, 623, 50, 40)));
    m_riddles.push_back(std::make_unique<InputRiddle>("Which American actor dubbed Woody in the VO?", "Tom Hanks"));


    for (auto& riddle : m_riddles)
        riddle->setPosition({wSize.x * 0.5, wSize.y * 0.95});

    m_nbRiddles = m_riddles.size();
    m_currentRiddleIndex = 0;
    m_currentRiddle = std::move(m_riddles[m_currentRiddleIndex]);

    m_score.setString("Score : " + std::to_string(m_scoreValue) + " / " + std::to_string(m_nbRiddles));
}

Room3::~Room3()
{
}

void Room3::handleEvent(sf::Event& event, sf::RenderWindow& window)
{
    RoomScene::handleEvent(event, window);
}

void Room3::update(float dt)
{
    RoomScene::update(dt);
}

void Room3::render(sf::RenderTarget& target)
{
    RoomScene::render(target);
}

}
