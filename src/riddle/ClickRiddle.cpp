/*
** EPITECH PROJECT, 2023
** EpitechJam2022
** File description:
** ClickRiddle
*/

#include "ClickRiddle.hpp"
#include "info.hpp"
#include "Cursor.hpp"
#include "Clock.hpp"

namespace jam {

    ClickRiddle::ClickRiddle(const std::string &question, const sf::IntRect &rect)
    : ARiddle(question)
    {
        m_background.setFillColor(sf::Color(0, 0, 0, 200));

        m_clickRect.setSize(sf::Vector2f(rect.width, rect.height));
        m_clickRect.setPosition(sf::Vector2f(rect.left, rect.top));
        m_clickRect.setFillColor(sf::Color(255, 0, 0, 50));
        m_clickRect.setOutlineColor(sf::Color::Red);
        m_clickRect.setOutlineThickness(1);
    }

    void ClickRiddle::setClickRect(const sf::IntRect &rect)
    {
        m_clickRect.setSize(sf::Vector2f(rect.width, rect.height));
        m_clickRect.setPosition(sf::Vector2f(rect.left, rect.top));
    }

    void ClickRiddle::render(sf::RenderTarget &window)
    {
        ARiddle::render(window);
        window.draw(m_clickRect);
    }

    void ClickRiddle::update()
    {
        ARiddle::update();

        sf::Vector2f mousePos = info::getMousePosition();

        if (m_clickRect.getGlobalBounds().contains(mousePos.x, mousePos.y))
            bounceCursor();
        else
            Cursor::getInstance()->setScale(1, 1);
    }

    void ClickRiddle::bounceCursor()
    {
        float scale = std::cos(Clock::getInstance().getElapsedTime().asSeconds() * 6);

        scale *= 0.2;
        scale += 1;

        Cursor::getInstance()->setScale(scale, scale);
    }

    void ClickRiddle::handleEvent(const sf::Event &event, sf::RenderWindow &window)
    {
        sf::Vector2f mousePos = info::getMousePosition();

        if (event.type == sf::Event::MouseButtonPressed) {
            if (m_clickRect.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                m_isFinished = 1;
            }
        }
    }
}
