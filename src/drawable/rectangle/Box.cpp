/*
** EPITECH PROJECT, 2023
** Jam
** File description:
** Box
*/

#include "Box.hpp"

bool jam::Box::isHovered(const sf::RenderWindow& window) const
{
    sf::Vector2i mouse_pos0 = sf::Mouse::getPosition(window);
    sf::Vector2f mouse_pos;

    mouse_pos = window.mapPixelToCoords(mouse_pos0, window.getView());
    return getGlobalBounds().contains((float)mouse_pos.x, (float)mouse_pos.y);
}

bool jam::Box::isClicked(sf::Event e, const sf::RenderWindow& window)
{
    if (isHovered(window)) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            return true;
        }
    }
    return false;
}

void jam::Box::setBaseScale(sf::Vector2f scale)
{
    this->setScale(scale);
    m_baseScale = scale;
}

void jam::Box::setBaseScale(float x, float y)
{
    this->setScale(x, y);
    m_baseScale = {x, y};
}

sf::Vector2f jam::Box::getBaseScale() const
{
    return m_baseScale;
}
