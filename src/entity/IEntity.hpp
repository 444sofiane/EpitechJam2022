/*
** EPITECH PROJECT, 2023
** Jam
** File description:
** IEntity
*/

#ifndef IENTITY_HPP_
    #define IENTITY_HPP_

    #include "common.hpp"

    namespace jam {
        class IEntity {
            public:
                virtual ~IEntity() = default;
                virtual sf::Vector2f getPosition() const = 0;
                virtual void setRotation(float angle) = 0;
                virtual void rotate(float angle) = 0;
                virtual float getRotation() const = 0;
                virtual void setPosition(const sf::Vector2f &pos) = 0;
                virtual void setPosition(float x, float y) = 0;
                virtual void setScale(const sf::Vector2f &scale) = 0;
                virtual void setScale(float x, float y) = 0;
                virtual void setScale(float scale) = 0;
                virtual sf::Vector2f getScale() const = 0;
                virtual void setSpeed(float speed) = 0;
                virtual float getSpeed() const = 0;
                virtual void setHitboxSize(const sf::Vector2f &size) = 0;
                virtual void setHitboxSize(float x, float y) = 0;
                virtual sf::Vector2f getHitboxSize() const = 0;
                virtual void setHitboxOffset(const sf::Vector2f &offset) = 0;
                virtual void setHitboxOffset(float x, float y) = 0;
                virtual sf::Vector2f getHitboxOffset() const = 0;
                virtual sf::FloatRect getBoundingBox() const = 0;
                virtual void enableDebug(bool enable) = 0;
                virtual bool isDebugEnabled() const = 0;
                virtual void move(sf::Vector2f &pos) = 0;
                virtual void move(float x, float y) = 0;
                virtual void render(sf::RenderTarget& target) = 0;
                virtual void update(float dt) = 0;
                virtual void handleEvent(sf::Event& event, sf::RenderWindow& window) = 0;
        };
    }

#endif /* !IENTITY_HPP_ */
