/*
** EPITECH PROJECT, 2023
** Jam
** File description:
** ERectangle
*/

#include "Rectangle.hpp"

bool jam::Rectangle::isHovered(const sf::RenderWindow& window) const
{
    sf::Vector2i mouse_pos0 = sf::Mouse::getPosition(window);
    sf::Vector2f mouse_pos;

    mouse_pos = window.mapPixelToCoords(mouse_pos0, window.getView());
    return getGlobalBounds().contains((float)mouse_pos.x, (float)mouse_pos.y);
}

bool jam::Rectangle::isClicked(sf::Event e, const sf::RenderWindow& window)
{
    if (isHovered(window)) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            return true;
        }
    }
    return false;
}

void jam::Rectangle::setBaseScale(sf::Vector2f scale)
{
    this->setScale(scale);
    m_baseScale = scale;
}

void jam::Rectangle::setBaseScale(float x, float y)
{
    this->setScale(x, y);
    m_baseScale = {x, y};
}

sf::Vector2f jam::Rectangle::getBaseScale() const
{
    return m_baseScale;
}
