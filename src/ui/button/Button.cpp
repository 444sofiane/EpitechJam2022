/*
** EPITECH PROJECT, 2023
** Jam
** File description:
** Button
*/

#include "Button.hpp"
#include "ResourceManager.hpp"

namespace jam {

namespace ui {

Button::Button(const Button& other)
: Widget(other), Box(other), m_label(other.m_label),
m_animation(other.m_animation), m_state(other.m_state), m_function(other.m_function)
{
}

Button::Button(const sf::Texture& texture, const std::string& label)
: m_animation(texture.getSize().x / 3, texture.getSize().y)
{
    setTexture(&texture);

    m_animation.addFrame(0, sf::seconds(0.5));
    m_animation.addFrame(1, sf::seconds(0.5));
    m_animation.addFrame(2, sf::seconds(0.5));
    setTextureRect(m_animation.getFrame(0));

    Box::setSize(sf::Vector2f(texture.getSize().x / 3, texture.getSize().y));
    setOrigin(getGlobalBounds().width * 0.5f, getGlobalBounds().height * 0.5f);
    m_label.setString(label);
    m_label.setFont(getResource().getFont("gameFont"));
    m_label.setOrigin(m_label.getGlobalBounds().width / 2, m_label.getGlobalBounds().height / 2);
    m_label.setPosition(this->getPosition());
    m_label.setFillColor(sf::Color(150, 150, 150, 255));
}

Widget::Text& Button::getLabel()
{
    return m_label;
}

void Button::setFunction(std::function<void(void)> func)
{
    m_function = func;
}

void Button::reset()
{
    m_state = IDLE;
    setTextureRect(m_animation.getFrame(0));
    setScale(m_baseScale);
    m_label.setFillColor(sf::Color(150, 150, 150, 255));
}

void Button::handleEvent(sf::Event e, const sf::RenderWindow& window)
{
    if (isHovered(window)) {
        if (m_state == PRESSED && !isClicked(e, window)) {
            reset();
            m_function();
            return;
        } else if (isClicked(e, window)) {
            m_state = PRESSED;
            setTextureRect(m_animation.getFrame(2));
            setScale(m_baseScale - sf::Vector2f(0.1f, 0.1f));
            m_label.setFillColor(sf::Color::White);
        }
        if (m_state == IDLE) {
            m_state = HOVERED;
            setTextureRect(m_animation.getFrame(1));
            setScale(m_baseScale + sf::Vector2f(0.1f, 0.1f));
            m_label.setFillColor(sf::Color::White);
        }
    } else if (m_state != IDLE) {
        reset();
    }
}

void Button::setPosition(const sf::Vector2f& pos)
{
    Box::setPosition(pos);
    m_label.setPosition(pos);
}

sf::Vector2f Button::getSize() const
{
    return Box::getSize();
}

void Button::render(sf::RenderTarget& target)
{
    //target.draw(*this);
    m_label.setOrigin(m_label.getGlobalBounds().width / 2,
    m_label.getGlobalBounds().height / 2);
    m_label.setPosition({getPosition().x, getPosition().y - m_label.getGlobalBounds().height / 2});
    target.draw(m_label);
}

}
}
