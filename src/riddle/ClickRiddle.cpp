/*
** EPITECH PROJECT, 2023
** EpitechJam2022
** File description:
** ClickRiddle
*/

#include "ClickRiddle.hpp"
#include "info.hpp"

namespace jam {

    ClickRiddle::ClickRiddle(const std::string &question, const sf::IntRect &rect)
    : ARiddle(question)
    {
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
    }

    void ClickRiddle::handleEvent(const sf::Event &event, sf::RenderWindow &window)
    {
        sf::Vector2f mousePos = info::getMousePosition(window);
        if (event.type == sf::Event::MouseButtonPressed) {
            if (m_clickRect.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                m_isFinished = true;
            }
        }
    }
}
