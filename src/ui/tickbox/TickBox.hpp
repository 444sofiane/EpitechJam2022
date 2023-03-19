/*
** EPITECH PROJECT, 2023
** EpitechJam2022
** File description:
** TickBox
*/

#pragma once

#include "common.hpp"
#include "Widget.hpp"
#include "Box.hpp"
#include "Animation.hpp"
#include <functional>

namespace jam {
    namespace ui {
        class TickBox : public Widget, public Box {
            public:
                enum State { IDLE, HOVERED, PRESSED };
                TickBox() = default;
                TickBox(sf::Texture& texture);
                virtual void handleEvent(sf::Event e, const sf::RenderWindow& window) override;
                virtual void setPosition(const sf::Vector2f& pos) override;
                virtual sf::Vector2f getSize() const override;
                virtual void render(sf::RenderTarget& target) override;
                void setCallback(std::function<void(bool)> callback);

            private:
                void reset();
                void setChecked(bool checked);
                bool isChecked() const;

            private:
                bool m_checked = false;
                State m_state = IDLE;
                Animation m_animation;
                sf::Texture* m_texture = nullptr;
                std::function<void(bool)> m_callback;
        };
    }
}