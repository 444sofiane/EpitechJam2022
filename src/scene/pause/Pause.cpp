/*
** EPITECH PROJECT, 2023
** EpitechJam2022
** File description:
** Pause
*/

#include "Pause.hpp"
#include "ResourceManager.hpp"
#include "SceneManager.hpp"
#include "info.hpp"

namespace jam {

    Pause::Pause()
    {
        sf::Vector2u wSize = info::getWindowSize();

        m_uiElements["resume"] = std::make_shared<ui::Button>(getResource().getTexture("generic_button"), "Resume");
        m_uiElements["menu"] = std::make_shared<ui::Button>(getResource().getTexture("generic_button"), "To Menu");

        m_open = false;

        m_background.setSize({800.f, 600.f});
        m_background.setFillColor(sf::Color(0, 0, 0, 230));
        m_background.setPosition({wSize.x * 0.5f, wSize.y * 0.5f});
        m_background.setOrigin(m_background.getSize().x / 2, m_background.getSize().y / 2);
        m_background.setOutlineColor(sf::Color::Black);
        m_background.setOutlineThickness(4);

        m_title.setFont(getResource().getFont("nathanFont"));
        m_title.setCharacterSize(50);
        m_title.setString("Pause");
        m_title.setPosition({wSize.x * 0.5, wSize.y * 0.3});
        m_title.setOrigin(m_title.getGlobalBounds().width / 2, m_title.getGlobalBounds().height / 2);

        auto& resumeB = dynamic_cast<ui::Button&>(*m_uiElements["resume"]);
        resumeB.setPosition({wSize.x * 0.5, wSize.y * 0.5});
        resumeB.setBaseScale(3.0f, 3.0f);
        resumeB.getLabel().setFont(getResource().getFont("nathanFont"));
        resumeB.getLabel().setCharacterSize(50);
        resumeB.setFunction([this] { m_open = false; });

        auto& menuB = dynamic_cast<ui::Button&>(*m_uiElements["menu"]);
        menuB.setPosition({wSize.x * 0.5, wSize.y * 0.6});
        menuB.setBaseScale(3.0f, 3.0f);
        menuB.getLabel().setFont(getResource().getFont("nathanFont"));
        menuB.getLabel().setCharacterSize(50);
        menuB.setFunction([] { SceneManager::getInstance().setCurrentScene("Main Menu"); });
    }

    Pause::~Pause() = default;

    void Pause::handleEvent(sf::Event& event, sf::RenderWindow& window)
    {
        for (auto& [name, element] : m_uiElements) {
            element->handleEvent(event, window);
        }

        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
            m_open = false;
        }
    }

    void Pause::update(float dt)
    {
    }

    void Pause::render(sf::RenderTarget& target) {
        target.draw(m_background);
        target.draw(m_title);
        for (auto& [name, element] : m_uiElements) {
            element->render(target);
        }
    }

    void Pause::restart()
    {
        m_open = false;
    }

    void Pause::stop()
    {
    }

    bool Pause::isOpen() const
    {
        return m_open;
    }

    void Pause::open()
    {
        m_open = true;
    }

    void Pause::close()
    {
        m_open = false;
    }

}