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

namespace jam {

RoomScene::RoomScene()
{
    m_uiElements["Title"] = std::make_shared<ui::UIText>();

    sf::Vector2f wSize(info::getWindowSize());

    ui::UIText* title = ((ui::UIText*)m_uiElements.at("Title").get());
    title->setString("NerdSimulator");
    title->setFont(getResource().getFont("nathanFont"));
    title->setPosition({wSize.x * 0.5, wSize.y * 0.1});
    title->setOrigin(title->getGlobalBounds().width / 2, title->getGlobalBounds().height / 2);

    m_background.setTexture(&getResource().getTexture("harry_potter"));
    m_background.setSize(sf::Vector2f(m_background.getTexture()->getSize()));
    m_background.setOrigin(m_background.getSize() / 2.0f);
    m_background.setPosition(wSize / 2.0f);

    m_backgroundColor.setSize({1920, 1080});
    m_backgroundColor.setFillColor(sf::Color(74, 141, 132,255));
}

RoomScene::~RoomScene()
{
}

void RoomScene::handleEvent(sf::Event& event, sf::RenderWindow& window)
{
    for (auto& [key, element] : m_uiElements) {
        element->handleEvent(event, window);
    }
}

void RoomScene::update(float dt)
{

}

void RoomScene::render(sf::RenderTarget& target)
{
    target.draw(m_backgroundColor);
    target.draw(m_background);
    for (auto& [key, element] : m_uiElements) {
        element->render(target);
    }
}

}
