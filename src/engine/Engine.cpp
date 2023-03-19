/*
** EPITECH PROJECT, 2023
** Jam
** File description:
** Engine
*/

#include "Engine.hpp"
#include "MenuScene.hpp"
#include "SettingsScene.hpp"
#include "ResourceManager.hpp"
#include "Clock.hpp"
#include "info.hpp"
#include "Cursor.hpp"
#include "Room1.hpp"
#include "Room2.hpp"
#include "Room3.hpp"
#include "Settings.hpp"

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

    m_renderTexture.create(WINDOW_SIZE.x, WINDOW_SIZE.y);

    Cursor::getInstance()->setTexture(ResourceManager::getInstance().getTexture("cursor loupe"));

    m_window->setVerticalSyncEnabled(true);
    //m_window->setFramerateLimit(5);

    m_fpsHint.setString("Fps: " + std::to_string(0));
    m_fpsHint.setOutlineColor(sf::Color::Black);
    m_fpsHint.setOutlineThickness(1);

    m_sceneManager.addScene("Main Menu", std::make_shared<MenuScene>());
    m_sceneManager.addScene("Harry Potter", std::make_shared<Room1>());
    m_sceneManager.addScene("Pokemon", std::make_shared<Room2>());
    m_sceneManager.addScene("Toy Story", std::make_shared<Room3>());
    m_sceneManager.addScene("Settings", std::make_shared<SettingsScene>());
    m_sceneManager.setCurrentScene("Main Menu");
    m_sceneManager.getCurrentScene()->restart();
}

void Engine::switchFullscreen()
{
    m_window->close();
    if (SETTINGS.getFullscreen()) {
        m_window->create(sf::VideoMode(WINDOW_SIZE.x, WINDOW_SIZE.y), "Game", sf::Style::Default);
        SETTINGS.getFullscreen() = false;
    } else {
        m_window->create(sf::VideoMode(WINDOW_SIZE.x, WINDOW_SIZE.y), "Game", sf::Style::Fullscreen);
        SETTINGS.getFullscreen() = true;
    }
    m_window->setMouseCursorVisible(false);
    m_window->setVerticalSyncEnabled(true);
}

void Engine::handleEvents()
{
    while (m_window->pollEvent(m_event)) {
        switch (m_event.type) {
            case sf::Event::Closed:
                m_window->close();
                break;
            case sf::Event::MouseButtonPressed:
                info::printMousePosition(*m_window.get());
                break;
            case sf::Event::KeyPressed:
                if (m_event.key.code == sf::Keyboard::F11) {
                    switchFullscreen();
                }
                break;
        }
        m_sceneManager.getCurrentScene()->handleEvent(m_event, *m_window);
    }
}

void Engine::render()
{
    m_window->clear();
    m_renderTexture.clear();
    m_sceneManager.getCurrentScene()->render(m_renderTexture);
    //m_window->draw(m_fpsHint);
    Cursor::getInstance()->render(m_renderTexture);
    m_renderTexture.display();

    if (SETTINGS.getRetro())
        m_window->draw(m_shader.apply(m_renderTexture));
    else
        m_window->draw(sf::Sprite(m_renderTexture.getTexture()));
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
    Cursor::getInstance()->setPosition(info::getMousePosition());
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