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
        static sf::Vector2f mousePosition = {0.f, 0.f};

        sf::Vector2f getMousePosition()
        {
            return mousePosition;
        }

        void printMousePosition(const sf::RenderWindow &window)
        {
            sf::Vector2f mouse_pos = getMousePosition();
            std::cout << "Mouse position: " << mouse_pos.x << "x, " << mouse_pos.y << "y\n";
        }

        sf::Vector2u getWindowSize()
        {
            return windowSize;
        }

        void gatherWindowInfo(const sf::RenderWindow &window)
        {
            windowSize = window.getSize();

            sf::Vector2i mouse_pos0 = sf::Mouse::getPosition(window);
            mousePosition = window.mapPixelToCoords(mouse_pos0, window.getView());
        }
    }
}
