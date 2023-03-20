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
#include "TickBox.hpp"
#include "Settings.hpp"
#include "Engine.hpp"

namespace jam {

SettingsScene::SettingsScene()
{
    m_uiElements["Title"] = std::make_shared<ui::Text>();
    m_uiElements["Fullscreen"] = std::make_shared<ui::TickBox>(getResource().getTexture("tick_box"));
    m_uiElements["RetroMode"] = std::make_shared<ui::TickBox>(getResource().getTexture("tick_box"));
    m_uiElements["Back"] = std::make_shared<ui::Button>(getResource().getTexture("generic_button"), "Back");
    m_uiElements["FullscreenText"] = std::make_shared<ui::Text>();
    m_uiElements["RetroModeText"] = std::make_shared<ui::Text>();

    m_transition = trans::Curtains(getResource().getTexture("curtains"), sf::Vector2f(1, 0), 1.5f);

    sf::Vector2u wSize = info::getWindowSize();

    ui::Text* fullscreenText = ((ui::Text*)m_uiElements.at("FullscreenText").get());
    fullscreenText->setString("Toggle Fullscreen");
    fullscreenText->setFont(getResource().getFont("nathanFont"));
    fullscreenText->setCharacterSize(50);
    fullscreenText->setPosition({wSize.x * 0.5, wSize.y * 0.29});
    fullscreenText->setOrigin(fullscreenText->getGlobalBounds().width / 2, fullscreenText->getGlobalBounds().height / 2);

    ui::Text* retroModeText = ((ui::Text*)m_uiElements.at("RetroModeText").get());
    retroModeText->setString("Retro Mode");
    retroModeText->setFont(getResource().getFont("nathanFont"));
    retroModeText->setCharacterSize(50);
    retroModeText->setPosition({wSize.x * 0.5, wSize.y * 0.39});
    retroModeText->setOrigin(retroModeText->getGlobalBounds().width / 2, retroModeText->getGlobalBounds().height / 2);

    ui::Button* exitButton = ((ui::Button*)m_uiElements.at("Back").get());
    exitButton->setPosition({wSize.x * 0.5, wSize.y * 0.55});
    exitButton->setBaseScale(3.0f, 3.0f);
    exitButton->getLabel().setFont(getResource().getFont("nathanFont"));
    exitButton->getLabel().setCharacterSize(50);
    exitButton->setFunction([] { SceneManager::getInstance().setCurrentScene("Main Menu"); });

    ui::TickBox* fullscreen = ((ui::TickBox*)m_uiElements.at("Fullscreen").get());
    fullscreen->setPosition({wSize.x * 0.4, wSize.y * 0.3});
    fullscreen->setBaseScale(0.2f, 0.2f);
    fullscreen->setCallback([](bool state) {
        SETTINGS.getFullscreen() = state;
        std::cout << "Fullscreen: " << state << std::endl;
        Engine::getInstance().switchFullscreen();
    });

    ui::TickBox* retroMode = ((ui::TickBox*)m_uiElements.at("RetroMode").get());
    retroMode->setPosition({wSize.x * 0.4, wSize.y * 0.4});
    retroMode->setBaseScale(0.2f, 0.2f);
    retroMode->setCallback([](bool state) { SETTINGS.getRetro() = state; });

    ui::Text* title = ((ui::Text*)m_uiElements.at("Title").get());
    title->setString("Settings");
    title->setFont(getResource().getFont("nathanFont"));
    title->setCharacterSize(100);
    title->setPosition({wSize.x * 0.5, wSize.y * 0.1});
    title->setOrigin(title->getGlobalBounds().width / 2, title->getGlobalBounds().height / 2);

    m_background.setSize({1920, 1080});
    m_background.setTexture(&getResource().getTexture("menu_bg"));

    m_poster.setTexture(&getResource().getTexture("monty_python"));
    m_poster.setSize(sf::Vector2f(m_poster.getTexture()->getSize()));
    m_poster.setOrigin(m_poster.getSize() * 0.5f);
    m_poster.setPosition({wSize.x * 0.08, wSize.y * 0.45});
    m_poster.setScale(0.4f, 0.4f);
    m_poster.setRotation(-5);
    m_poster.setFillColor(sf::Color(100, 100, 100, 255));
}

SettingsScene::~SettingsScene()
{
}

void SettingsScene::stop()
{
}

void SettingsScene::restart()
{
    m_transition.restart();
}

void SettingsScene::handleEvent(sf::Event& event, sf::RenderWindow& window)
{
    if (!m_transition.isDone())
        return;
    for (auto& [key, element] : m_uiElements) {
        element->handleEvent(event, window);
    }
}

void SettingsScene::update(float dt)
{
    if (!m_transition.isDone()) {
        m_transition.update(dt);
        return;
    }
}

void SettingsScene::render(sf::RenderTarget& target)
{
    target.draw(m_background);
    target.draw(m_poster);
    for (auto& [key, element] : m_uiElements) {
        element->render(target);
    }
    if (!m_transition.isDone()) {
        m_transition.render(target);
    }
}

}
