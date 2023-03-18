/*
** EPITECH PROJECT, 2023
** EpitechJam2022
** File description:
** SatBox
*/

#include "SatBox.hpp"

namespace jam {

    SatBox::SatBox()
    {
        m_texture = nullptr;
        m_textRect = sf::IntRect(0, 0, 0, 0);
        m_states = sf::RenderStates::Default;
    }

    SatBox::~SatBox()
    {
    }

    void SatBox::setVertexPosition(int index, const sf::Vector2f &pos)
    {
        m_vertices[index].position = pos;
    }

    void SatBox::setVertexColor(int index, const sf::Color &color)
    {
        m_vertices[index].color = color;
    }

    void SatBox::setColor(const sf::Color &color)
    {
        for (int i = 0; i < 4; i++)
            m_vertices[i].color = color;
    }

    void SatBox::setTexture(const sf::Texture &texture)
    {
        m_texture = const_cast<sf::Texture *>(&texture);
        m_states.texture = m_texture;
        updateVerticesTexCoords();
    }

    void SatBox::setTextRect(const sf::IntRect &rect)
    {
        m_textRect = rect;
        updateVerticesTexCoords();
    }

    bool SatBox::contains(const sf::Vector2f &point)
    {
        sf::Vector2f p1 = m_vertices[0].position;
        sf::Vector2f p2 = m_vertices[1].position;
        sf::Vector2f p3 = m_vertices[2].position;
        sf::Vector2f p4 = m_vertices[3].position;

        float d1, d2, d3, d4;
        bool has_neg, has_pos;

        d1 = ((point.x - p3.x) * (p4.y - p3.y)) - ((p4.x - p3.x) * (point.y - p3.y));
        d2 = ((point.x - p4.x) * (p1.y - p4.y)) - ((p1.x - p4.x) * (point.y - p4.y));
        d3 = ((point.x - p1.x) * (p2.y - p1.y)) - ((p2.x - p1.x) * (point.y - p1.y));
        d4 = ((point.x - p2.x) * (p3.y - p2.y)) - ((p3.x - p2.x) * (point.y - p2.y));

        has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0) || (d4 < 0);
        has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0) || (d4 > 0);

        return !(has_neg && has_pos);
    }

    void SatBox::render(sf::RenderTarget &target)
    {
        updateVerticesTexCoords();
        target.draw(m_vertices, 4, sf::Quads, m_states);
    }

    void SatBox::updateVerticesTexCoords()
    {
        sf::Vector2f size(m_textRect.width, m_textRect.height);
        sf::Vector2f half = size / 2.f;

        m_vertices[0].texCoords = sf::Vector2f(m_textRect.left, m_textRect.top);
        m_vertices[1].texCoords = sf::Vector2f(m_textRect.left + size.x, m_textRect.top);
        m_vertices[2].texCoords = sf::Vector2f(m_textRect.left + size.x, m_textRect.top + size.y);
        m_vertices[3].texCoords = sf::Vector2f(m_textRect.left, m_textRect.top + size.y);
    }

}