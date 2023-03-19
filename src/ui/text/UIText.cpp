/*
** EPITECH PROJECT, 2023
** Jam
** File description:
** UIText
*/

#include "UIText.hpp"

namespace jam {

namespace ui {

Text::Text()
{
}

Text::Text(const std::string& text)
{
    setString(text);
}

Text::~Text()
{
}

void Text::render(sf::RenderTarget& target)
{
    target.draw(*this);
}

void Text::handleEvent(sf::Event e, const sf::RenderWindow& window)
{

}

void Text::setPosition(const sf::Vector2f& pos)
{
    sf::Text::setPosition(pos);
}

sf::Vector2f Text::getSize() const
{
    return {getGlobalBounds().width, getGlobalBounds().height};
}

}
}