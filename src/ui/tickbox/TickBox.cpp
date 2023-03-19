/*
** EPITECH PROJECT, 2023
** EpitechJam2022
** File description:
** TickBox
*/

#include "TickBox.hpp"

namespace jam {
    namespace ui {

        TickBox::TickBox(sf::Texture& texture)
        : m_animation(texture.getSize().x / 2, texture.getSize().y)
        {
            sf::Vector2f size;

            setTexture(&texture);
            m_animation.addFrame(0, sf::seconds(0.5));
            m_animation.addFrame(1, sf::seconds(0.5));
            setTextureRect(m_animation.getFrame(0));

            m_texture = &texture;
            size = sf::Vector2f(m_texture->getSize());
            setSize({size.x / 2.0f, size.y});
            setOrigin(getGlobalBounds().width * 0.5f, getGlobalBounds().height * 0.5f);

            m_callback = [](bool) {};

            m_checked = false;
        }

        void TickBox::setCallback(std::function<void(bool)> callback)
        {
            m_callback = callback;
        }

        void TickBox::handleEvent(sf::Event e, const sf::RenderWindow& window)
        {
            if (isHovered(window)) {
                if (m_state == PRESSED && !isClicked(e, window)) {
                    reset();
                    setChecked(!isChecked());
                    m_callback(m_checked);
                    return;
                } else if (isClicked(e, window)) {
                    setScale(m_baseScale * 0.95f);
                    m_state = PRESSED;
                } else {
                    m_state = HOVERED;
                    setScale(m_baseScale * 1.05f);
                }
            } else {
                reset();
            }
        }

        void TickBox::setPosition(const sf::Vector2f& pos)
        {
            Box::setPosition(pos);
        }

        sf::Vector2f TickBox::getSize() const
        {
            return {m_texture->getSize().x / 2.0f, m_texture->getSize().y};
        }

        void TickBox::render(sf::RenderTarget& target)
        {
            target.draw(*this);
        }

        void TickBox::reset()
        {
            m_state = IDLE;
            setScale(m_baseScale);
        }

        void TickBox::setChecked(bool checked)
        {
            m_checked = checked;
            if (m_checked)
                setTextureRect(m_animation.getFrame(1));
            else
                setTextureRect(m_animation.getFrame(0));
        }

        bool TickBox::isChecked() const
        {
            return m_checked;
        }
    }
}