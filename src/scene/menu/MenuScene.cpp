/*
** EPITECH PROJECT, 2023
** Jam
** File description:
** MenuScene
*/

#include "MenuScene.hpp"
#include "UIText.hpp"
#include "Button.hpp"
#include "Slider.hpp"
#include "ResourceManager.hpp"
#include "SceneManager.hpp"
#include "info.hpp"

namespace jam {

MenuScene::MenuScene()
{
    m_uiElements["Title"] = std::make_shared<ui::UIText>();
    m_uiElements["Play"] = std::make_shared<ui::Button>(getResource().getTexture("generic_button"), "Play");
    m_uiElements["Settings"] = std::make_shared<ui::Button>(getResource().getTexture("generic_button"), "Settings");
    m_uiElements["Exit"] = std::make_shared<ui::Button>(getResource().getTexture("generic_button"), "Exit");

    sf::Vector2f wSize(info::getWindowSize());

    ui::Button* playButton = ((ui::Button*)m_uiElements.at("Play").get());
    playButton->setPosition({wSize.x * 0.5, wSize.y * 0.25});
    playButton->getLabel().setFont((getResource().getFont("nathanFont")));
    playButton->setBaseScale(3.0f, 3.0f);
    playButton->getLabel().setCharacterSize(50);
    playButton->setFunction([] { SceneManager::getInstance().setCurrentScene("Harry Potter"); });

    ui::Button* settingsButton = ((ui::Button*)m_uiElements.at("Settings").get());
    settingsButton->setPosition({wSize.x * 0.5, wSize.y * 0.40});
    settingsButton->getLabel().setFont((getResource().getFont("nathanFont")));
    settingsButton->setBaseScale(3.0f, 3.0f);
    settingsButton->getLabel().setCharacterSize(50);
    settingsButton->setFunction([] { SceneManager::getInstance().setCurrentScene("Settings"); });

    ui::Button* exitButton = ((ui::Button*)m_uiElements.at("Exit").get());
    exitButton->getLabel().setFont(getResource().getFont("nathanFont"));
    exitButton->getLabel().setCharacterSize(50);
    exitButton->setPosition({wSize.x * 0.5, wSize.y * 0.55});
    exitButton->setBaseScale(3.0f, 3.0f);
    exitButton->setFunction([] { exit(0); });

    ui::UIText* title = ((ui::UIText*)m_uiElements.at("Title").get());
    title->setString("NerdSimulator");
    title->setFont(getResource().getFont("nathanFont"));
    title->setCharacterSize(100);
    title->setPosition({wSize.x * 0.5, wSize.y * 0.1});
    title->setOrigin(title->getGlobalBounds().width / 2, title->getGlobalBounds().height / 2);

    m_background.setSize({1920, 1080});
    m_background.setTexture(&getResource().getTexture("menu_bg"));
}

MenuScene::~MenuScene()
{
}

void MenuScene::stop()
{
    if (m_music != nullptr) {
        m_music->stop();
    }
}

void MenuScene::handleEvent(sf::Event& event, sf::RenderWindow& window)
{
    for (auto& [key, element] : m_uiElements) {
        element->handleEvent(event, window);
    }
}

void MenuScene::update(float dt)
{
}

void MenuScene::render(sf::RenderTarget& target)
{
    target.draw(m_background);
    for (auto& [key, element] : m_uiElements) {
        element->render(target);
    }
}

}
