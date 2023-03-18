/*
** EPITECH PROJECT, 2023
** Jam
** File description:
** SettingsScene
*/

#include "SettingsScene.hpp"
#include "UIText.hpp"
#include "Button.hpp"
#include "Slider.hpp"
#include "ResourceManager.hpp"
#include "SceneManager.hpp"
#include "info.hpp"

namespace jam {

SettingsScene::SettingsScene()
{
    m_uiElements["Title"] = std::make_shared<ui::UIText>();
    m_uiElements["Back"] = std::make_shared<ui::Button>(getResource().getTexture("generic_button"), "Back");

    sf::Vector2u wSize = info::getWindowSize();

    ui::Button* exitButton = ((ui::Button*)m_uiElements.at("Back").get());
    exitButton->setPosition({wSize.x * 0.5, wSize.y * 0.55});
    exitButton->setBaseScale(3.0f, 3.0f);
    exitButton->getLabel().setFont(getResource().getFont("nathanFont"));
    exitButton->getLabel().setCharacterSize(50);
    exitButton->setFunction([] { SceneManager::getInstance().setCurrentScene("Main Menu"); });

    ui::UIText* title = ((ui::UIText*)m_uiElements.at("Title").get());
    title->setString("Settings");
    title->setFont(getResource().getFont("nathanFont"));
    title->setCharacterSize(100);
    title->setPosition({wSize.x * 0.5, wSize.y * 0.1});
    title->setOrigin(title->getGlobalBounds().width / 2, title->getGlobalBounds().height / 2);

    m_background.setSize({1920, 1080});
    m_background.setTexture(&getResource().getTexture("menu_bg"));
}

SettingsScene::~SettingsScene()
{
}

void SettingsScene::stop()
{
}

void SettingsScene::handleEvent(sf::Event& event, sf::RenderWindow& window)
{
    for (auto& [key, element] : m_uiElements) {
        element->handleEvent(event, window);
    }
}

void SettingsScene::update(float dt)
{
}

void SettingsScene::render(sf::RenderTarget& target)
{
    target.draw(m_background);
    for (auto& [key, element] : m_uiElements) {
        element->render(target);
    }
}

}
