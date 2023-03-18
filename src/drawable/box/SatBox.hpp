/*
** EPITECH PROJECT, 2023
** EpitechJam2022
** File description:
** SatBox
*/

#ifndef SATBOX_HPP_
#define SATBOX_HPP_

#include "common.hpp"

namespace jam {
    class SatBox {
        public:
            SatBox();
            ~SatBox();
            void setVertexPosition(int index, const sf::Vector2f& pos);
            void setVertexColor(int index, const sf::Color& color);
            void setColor(const sf::Color& color);
            void setTexture(const sf::Texture& texture);
            void setTextRect(const sf::IntRect& rect);
            bool contains(const sf::Vector2f& point);
            void render(sf::RenderTarget& target);

        private:
            void updateVerticesTexCoords();

        private:
            sf::RenderStates m_states;
            sf::Vertex m_vertices[4];
            sf::Texture* m_texture;
            sf::IntRect m_textRect;
    };
}

#endif /* !SATBOX_HPP_ */
