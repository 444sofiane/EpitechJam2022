/*
** EPITECH PROJECT, 2023
** Jam
** File description:
** UIText
*/

#include "UIText.hpp"

namespace jam {

namespace ui {

UIText::UIText()
{
}

UIText::~UIText()
{
}

void UIText::render(sf::RenderTarget& target)
{
    target.draw(*this);
}

void UIText::handleEvent(sf::Event e, const sf::RenderWindow& window)
{

}

void UIText::setPosition(const sf::Vector2f& pos)
{
    sf::Text::setPosition(pos);
}

sf::Vector2f UIText::getSize() const
{
    return {getGlobalBounds().width, getGlobalBounds().height};
}

}
}