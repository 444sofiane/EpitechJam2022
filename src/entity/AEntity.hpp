/*
** EPITECH PROJECT, 2023
** Jam
** File description:
** AEntity
*/

#ifndef AENTITY_HPP_
    #define AENTITY_HPP_

    #include "IEntity.hpp"
    #include "Rectangle.hpp"

    namespace jam {
        class AEntity : public IEntity {
            public:
                virtual ~AEntity() override = default;
                virtual sf::Vector2f getPosition() const override;
                virtual void setRotation(float angle) override;
                virtual void rotate(float angle) override;
                virtual float getRotation() const;
                virtual void setPosition(const sf::Vector2f &pos) override;
                virtual void setPosition(float x, float y) override;
                virtual void setScale(const sf::Vector2f &scale) override;
                virtual void setScale(float x, float y) override;
                virtual void setScale(float scale) override;
                virtual sf::Vector2f getScale() const override;
                virtual void setSpeed(float speed) override;
                virtual float getSpeed() const override;
                virtual void setHitboxSize(const sf::Vector2f &size) override;
                virtual void setHitboxSize(float x, float y) override;
                virtual sf::Vector2f getHitboxSize() const override;
                virtual void setHitboxOffset(const sf::Vector2f &offset) override;
                virtual void setHitboxOffset(float x, float y) override;
                virtual sf::Vector2f getHitboxOffset() const override;
                virtual sf::FloatRect getBoundingBox() const override;
                virtual void move(sf::Vector2f &pos) override;
                virtual void move(float x, float y) override;
                virtual void enableDebug(bool enable) override;
                virtual bool isDebugEnabled() const override;
                virtual void render(sf::RenderTarget& target) = 0;
                virtual void update(float dt) override;
                virtual void handleEvent(sf::Event& event, sf::RenderWindow& window) override;

            protected:
                AEntity();
                float m_speed = 1;
                bool m_debug = false;
                Rectangle m_hitbox;
                float m_rotation = 0;
                sf::Vector2f m_hitBoxOffset = {0.f, 0.f};
                sf::Vector2f m_position = {0.f, 0.f};
        };
    }

#endif /* !AENTITY_HPP_ */
