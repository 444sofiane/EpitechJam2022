/*
** EPITECH PROJECT, 2023
** Jam
** File description:
** AEntity
*/

#include "AEntity.hpp"


namespace jam {

AEntity::AEntity()
{
    m_hitbox.setSize(sf::Vector2f(32, 32));
    m_hitbox.setFillColor(sf::Color(255, 0, 0, 50));
    m_hitbox.setOutlineColor(sf::Color::Red);
    m_hitbox.setOutlineThickness(1);
    m_hitbox.setPosition(sf::Vector2f(100, 100));
    m_position = sf::Vector2f(100, 100);
    m_rotation = 0;
}

void AEntity::setPosition(const sf::Vector2f &pos)
{
    m_hitbox.setPosition(pos);
    m_position = pos;
}

void AEntity::setPosition(float x, float y)
{
    m_hitbox.setPosition(x, y);
    m_position = sf::Vector2f(x, y);
}

void AEntity::move(sf::Vector2f &pos)
{
    m_hitbox.move(pos);
    m_position += pos;
}

void AEntity::move(float x, float y)
{
    m_hitbox.move(x, y);
    m_position += sf::Vector2f(x, y);
}

void AEntity::setRotation(float angle)
{
    m_hitbox.setRotation(angle);
    m_rotation = angle;
    while (m_rotation > 360)
        m_rotation -= 360;
}

void AEntity::rotate(float angle)
{
    m_hitbox.rotate(angle);
    m_rotation += angle;
    while (m_rotation > 360)
        m_rotation -= 360;
}

sf::Vector2f AEntity::getPosition() const
{
    return m_position;
}

void AEntity::setScale(const sf::Vector2f &scale)
{
    m_hitbox.setScale(scale);
}

void AEntity::setScale(float x, float y)
{
    m_hitbox.setScale(x, y);
}

void AEntity::setScale(float scale)
{
    m_hitbox.setScale({scale, scale});
}

sf::Vector2f AEntity::getScale() const
{
    return m_hitbox.getScale();
}

void AEntity::setHitboxSize(const sf::Vector2f &size)
{
    m_hitbox.setSize(size);
}

void AEntity::setHitboxSize(float x, float y)
{
    m_hitbox.setSize({x, y});
}

sf::Vector2f AEntity::getHitboxSize() const
{
    return m_hitbox.getSize();
}

void AEntity::setHitboxOffset(const sf::Vector2f &offset)
{
    m_hitBoxOffset = offset;
}

void AEntity::setHitboxOffset(float x, float y)
{
    m_hitBoxOffset = sf::Vector2f(x, y);
}

sf::Vector2f AEntity::getHitboxOffset() const
{
    return m_hitBoxOffset;
}

sf::FloatRect AEntity::getBoundingBox() const
{
    return m_hitbox.getGlobalBounds();
}

void AEntity::update(float dt)
{
}

void AEntity::handleEvent(sf::Event &event, sf::RenderWindow &window)
{
}

void AEntity::enableDebug(bool enable)
{
    m_debug = enable;
}

bool AEntity::isDebugEnabled() const
{
    return m_debug;
}

float AEntity::getRotation() const
{
    return m_rotation;
}

void AEntity::setSpeed(float speed)
{
    m_speed = speed;
}

float AEntity::getSpeed() const
{
    return m_speed;
}

}

