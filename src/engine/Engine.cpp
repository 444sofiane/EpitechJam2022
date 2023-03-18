/*
** EPITECH PROJECT, 2023
** Jam
** File description:
** Engine
*/

#include "Engine.hpp"
#include "MenuScene.hpp"
#include "SettingsScene.hpp"
#include "RoomScene.hpp"
#include "ResourceManager.hpp"
#include "Clock.hpp"
#include "info.hpp"
#include "Cursor.hpp"

namespace jam {

Engine::Engine()
: m_sceneManager(SceneManager::getInstance())
{
    Clock::getInstance().setTickRate(60);
}

Engine::~Engine()
{
}

void Engine::init()
{
    m_window = std::unique_ptr<sf::RenderWindow>(new sf::RenderWindow(sf::VideoMode(WINDOW_SIZE.x, WINDOW_SIZE.y),
        std::string("Game"), sf::Style::Default));

    m_window->setMouseCursorVisible(false);

    Cursor::getInstance()->setTexture(ResourceManager::getInstance().getTexture("cursor loupe"));

    m_window->setVerticalSyncEnabled(true);
    //m_window->setFramerateLimit(5);

    m_fpsHint.setString("Fps: " + std::to_string(0));
    m_fpsHint.setOutlineColor(sf::Color::Black);
    m_fpsHint.setOutlineThickness(1);

    m_sceneManager.addScene("Main Menu", std::make_shared<MenuScene>());
    m_sceneManager.addScene("Settings", std::make_shared<SettingsScene>());
    m_sceneManager.addScene("Harry Potter", std::make_shared<RoomScene>());
    m_sceneManager.setCurrentScene("Main Menu");
}

void Engine::handleEvents()
{
    while (m_window->pollEvent(m_event)) {
        switch (m_event.type) {
            case sf::Event::Closed:
                m_window->close();
                break;
        }
        m_sceneManager.getCurrentScene()->handleEvent(m_event, *m_window);
    }
}

void Engine::render()
{
    m_window->clear();
    m_sceneManager.getCurrentScene()->render(*m_window.get());
    m_window->draw(m_fpsHint);
    Cursor::getInstance()->render(*m_window);
    m_window->display();
}

void Engine::updateFpsHint()
{
    static float tick = -0.01f;

    if (getTime().asSeconds() > tick + 0.1) {
        tick = getTime().asSeconds();
        m_fpsHint.setString("Fps: " + std::to_string(getClock().getFps()));
    }
}

void Engine::update()
{
    getClock().update();
    info::gatherWindowInfo(*m_window.get());
    updateFpsHint();
    Cursor::getInstance()->setPosition(info::getMousePosition(*m_window));
    m_sceneManager.getCurrentScene()->update(getClock().getFrameDt());
}

void Engine::run()
{
    while (m_window->isOpen()) {
        update();
        render();
        handleEvents();
    }
}

}