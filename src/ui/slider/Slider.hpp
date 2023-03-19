/*
** EPITECH PROJECT, 2023
** Jam
** File description:
** Slider
*/

#ifndef SLIDER_HPP_
    #define SLIDER_HPP_

    #include "Widget.hpp"
    #include "Animation.hpp"
    #include "Box.hpp"

    namespace jam {

    namespace ui {
        class Slider : public Widget {
            public:
                enum State { IDLE, HOVERED, GRABBED };
                enum Orientation { VERTICAL, HORIZONTAL };
                Slider(const sf::Texture& wagonTexture, const sf::Texture& railTexture, Orientation orientation);
                virtual void handleEvent(sf::Event e, const sf::RenderWindow& window) override;
                virtual void setPosition(const sf::Vector2f& pos) override;
                virtual sf::Vector2f getSize() const override;
                virtual void render(sf::RenderTarget& target) override;
                void setScale(const sf::Vector2f& scale);
                void setScale(float x, float y);
                float getProgress() const;

            protected:
                bool isOnTrack() const;
                void fixWagonPosition();

            protected:
                float m_progress = 0.5f;
                bool m_mouseDown = false;
                sf::Vector2f m_lastPosition;
                Orientation m_orientation;
                Animation m_animation;
                State m_state;
                Box m_internRail;
                Box m_outerRail;
                Box m_wagon;
        };
    }

    }

#endif /* !SLIDER_HPP_ */
