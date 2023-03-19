/*
** EPITECH PROJECT, 2023
** Jam
** File description:
** Box
*/

#ifndef RECTANGLE_HPP_
    #define RECTANGLE_HPP_

    #include "common.hpp"

    namespace jam {
        class Box : public sf::RectangleShape
        {
        public:
            bool isHovered(const sf::RenderWindow &window) const;
            bool isClicked(sf::Event, const sf::RenderWindow &window);
            void setBaseScale(sf::Vector2f scale);
            void setBaseScale(float x, float y);
            sf::Vector2f getBaseScale() const;
        protected:
            sf::Vector2f m_baseScale = {1, 1};
        };
    }

#endif /* !RECTANGLE_HPP_ */
