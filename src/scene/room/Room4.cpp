/*
** EPITECH PROJECT, 2023
** EpitechJam2022
** File description:
** Room4
*/

#include "Room4.hpp"

#include "UIText.hpp"
#include "Button.hpp"
#include "ResourceManager.hpp"
#include "SceneManager.hpp"
#include "info.hpp"
#include "ClickRiddle.hpp"
#include "InputRiddle.hpp"

namespace jam {

Room4::Room4()
{
    ui::Text* title = ((ui::Text*)m_uiElements.at("Title").get());
    title->setString("Room 4");

    m_music = &ResourceManager::getInstance().getMusic("stranger_things");
    m_music->setVolume(80);

    sf::Vector2f wSize(info::getWindowSize());

    m_background.setTexture(&getResource().getTexture("stranger_things"));
    m_background.setSize(sf::Vector2f(m_background.getTexture()->getSize()));
    m_background.setOrigin(m_background.getSize() / 2.0f);
    m_background.setPosition(wSize / 2.0f);
}

void Room4::restart()
{
    sf::Vector2f wSize(info::getWindowSize());

    RoomScene::restart();

    m_riddles.push_back(std::make_unique<ClickRiddle>("Click on what is use to communicate with the upside down ?", sf::IntRect(650, 240, 240, 240)));
    m_riddles.push_back(std::make_unique<InputRiddle>("What the name of the character who is stuck in the upside down ?", "Will"));
    m_riddles.push_back(std::make_unique<InputRiddle>("Who is the main character ?", "Eleven"));
    m_riddles.push_back(std::make_unique<InputRiddle>("Why is Eleven chase for ?", "Super-Powers"));
    m_riddles.push_back(std::make_unique<InputRiddle>("what is the name of the Waffle brand ?", "Eggo"));
    m_riddles.push_back(std::make_unique<InputRiddle>("What is the name of the creature from the upside down ??", "Demogorgon"));
    m_riddles.push_back(std::make_unique<InputRiddle>("Which famous game is played by the kids ?", "Dungeons and Dragons"));


    for (auto& riddle : m_riddles)
        riddle->setPosition({wSize.x * 0.5, wSize.y * 0.95});

    m_nbRiddles = m_riddles.size();
    m_currentRiddleIndex = 0;
    m_currentRiddle = std::move(m_riddles[m_currentRiddleIndex]);

    m_score.setString("Score : " + std::to_string(m_scoreValue) + " / " + std::to_string(m_nbRiddles));
}

Room4::~Room4()
{
}

void Room4::handleEvent(sf::Event& event, sf::RenderWindow& window)
{
    RoomScene::handleEvent(event, window);
}

void Room4::update(float dt)
{
    RoomScene::update(dt);
}

void Room4::render(sf::RenderTarget& target)
{
    RoomScene::render(target);
}

}
