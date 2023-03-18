/*
** EPITECH PROJECT, 2023
** Jam
** File description:
** windowInfo
*/

#ifndef WINDOWINFO_HPP_
    #define WINDOWINFO_HPP_

    #include "common.hpp"

    namespace jam {
        namespace info {
            extern sf::Vector2f getMousePosition();
            extern sf::Vector2u getWindowSize();
            extern void gatherWindowInfo(const sf::RenderWindow& window);
            extern void printMousePosition(const sf::RenderWindow &window);
        }
    }

#endif /* !WINDOWINFO_HPP_ */
