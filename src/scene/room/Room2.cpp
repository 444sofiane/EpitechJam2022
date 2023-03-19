/*
** EPITECH PROJECT, 2023
** EpitechJam2023
** File description:
** Room2
*/

#include "Room2.hpp"

#include "UIText.hpp"
#include "Button.hpp"
#include "ResourceManager.hpp"
#include "SceneManager.hpp"
#include "info.hpp"
#include "ClickRiddle.hpp"
#include "InputRiddle.hpp"

namespace jam {

Room2::Room2()
{
    ui::Text* title = ((ui::Text*)m_uiElements.at("Title").get());
    title->setString("Room 2");

    m_music = &ResourceManager::getInstance().getMusic("pokemon");
    m_music->setVolume(80);

    sf::Vector2f wSize(info::getWindowSize());

    m_background.setTexture(&getResource().getTexture("pokemon"));
    m_background.setSize(sf::Vector2f(m_background.getTexture()->getSize()));
    m_background.setOrigin(m_background.getSize() / 2.0f);
    m_background.setPosition(wSize / 2.0f);
}

void Room2::restart()
{
    sf::Vector2f wSize(info::getWindowSize());

    RoomScene::restart();

    m_riddles.push_back(std::make_unique<InputRiddle>("What is the name of the Pokemon on the tv?", "Pikachu"));
    m_riddles.push_back(std::make_unique<InputRiddle>("Which pokemon type doesn't exist ? Fire, Water, Glass", "Glass"));
    m_riddles.push_back(std::make_unique<InputRiddle>("What is the name of the most powerful pokeball", "Master Ball"));
    m_riddles.push_back(std::make_unique<InputRiddle>("What is the name of the main character in Pokemon?", "Ash"));
    m_riddles.push_back(std::make_unique<InputRiddle>("What is the pokemon number 001 in the pokedex?", "Bulbasaur"));
    m_riddles.push_back(std::make_unique<InputRiddle>("What is the name of the team trying to get Pikachu?", "Team Rocket"));
    m_riddles.push_back(std::make_unique<InputRiddle>("In what does Magikarp evolve ?", "Gyarados"));
    m_riddles.push_back(std::make_unique<InputRiddle>("In his most evolved form, how many heads does Diglett have ?", "3"));
    m_riddles.push_back(std::make_unique<InputRiddle>("What is the slogan of the Pokemon franchise?", "Gotta catch 'em all"));
    m_riddles.push_back(std::make_unique<ClickRiddle>("Where is the basic pokeball on the screen", sf::IntRect(1040, 305, 70, 60)));


    for (auto& riddle : m_riddles)
        riddle->setPosition({wSize.x * 0.5, wSize.y * 0.95});

    m_nbRiddles = m_riddles.size();
    m_currentRiddleIndex = 0;
    m_currentRiddle = std::move(m_riddles[m_currentRiddleIndex]);

    m_score.setString("Score : " + std::to_string(m_scoreValue) + " / " + std::to_string(m_nbRiddles));
}

Room2::~Room2()
{
}

void Room2::handleEvent(sf::Event& event, sf::RenderWindow& window)
{
    RoomScene::handleEvent(event, window);
}

void Room2::update(float dt)
{
    RoomScene::update(dt);
}

void Room2::render(sf::RenderTarget& target)
{
    RoomScene::render(target);
}

}

