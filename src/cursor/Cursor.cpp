/*
** EPITECH PROJECT, 2023
** EpitechJam2022
** File description:
** Cursor
*/

#include "Cursor.hpp"
#include "ResourceManager.hpp"

namespace jam {

    Cursor::Cursor()
    {
        m_shape.setSize({32, 32});
        m_shape.setOrigin(m_shape.getGlobalBounds().width / 2,
            m_shape.getGlobalBounds().height / 2);
    }

    Cursor* Cursor::getInstance()
    {
        static std::unique_ptr<Cursor> instance = nullptr;

        if (instance == nullptr)
            instance = std::make_unique<Cursor>();
        return instance.get();
    }

    void Cursor::render(sf::RenderTarget& target)
    {
        target.draw(m_shape);
    }

    void Cursor::setScale(const sf::Vector2f& scale)
    {
        m_shape.setScale(scale);
    }

    void Cursor::setScale(float x, float y)
    {
        m_shape.setScale(x, y);
    }

    void Cursor::setTexture(const sf::Texture& texture)
    {
        m_shape.setTexture(&texture);
    }

    void Cursor::setPosition(const sf::Vector2f& pos)
    {
        m_shape.setPosition(pos);
    }

}