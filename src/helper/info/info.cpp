/*
** EPITECH PROJECT, 2023
** Jam
** File description:
** info
*/

#include "info.hpp"

namespace jam {
    namespace info {

        static sf::Vector2u windowSize = WINDOW_SIZE;

        sf::Vector2f getMousePosition(const sf::RenderWindow &window)
        {
            sf::Vector2i mouse_pos0 = sf::Mouse::getPosition(window);
            return window.mapPixelToCoords(mouse_pos0, window.getView());
        }

        void printMousePosition(const sf::RenderWindow &window)
        {
            sf::Vector2f mouse_pos = getMousePosition(window);
            std::cout << "Mouse position: " << mouse_pos.x << "x, " << mouse_pos.y << "y\n";
        }

        sf::Vector2u getWindowSize()
        {
            return windowSize;
        }

        void gatherWindowInfo(const sf::RenderWindow &window)
        {
            windowSize = window.getSize();
        }
    }
}
