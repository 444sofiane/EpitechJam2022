/*
** EPITECH PROJECT, 2023
** Jam
** File description:
** Widget
*/

#include "Widget.hpp"
#include "ResourceManager.hpp"

namespace jam {

namespace ui {

Widget::Text::Text()
{
    setOutlineColor(sf::Color::Black);
    setFillColor(sf::Color::White);
    setFont(getResource().getFont("debugFont"));
}

}
}