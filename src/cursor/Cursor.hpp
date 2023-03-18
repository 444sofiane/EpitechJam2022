/*
** EPITECH PROJECT, 2023
** EpitechJam2022
** File description:
** Cursor
*/

#pragma once

#include "common.hpp"

namespace jam {
    class Cursor
    {
        public:
            void render(sf::RenderTarget& target);
            void setTexture(const sf::Texture& texture);
            void setPosition(const sf::Vector2f& pos);
            void setScale(const sf::Vector2f& scale);
            void setScale(float x, float y);
            static Cursor* getInstance();
            Cursor();

        private:
            sf::RectangleShape m_shape;
    };
}
