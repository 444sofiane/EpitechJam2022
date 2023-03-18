/*
** EPITECH PROJECT, 2023
** EpitechJam2022
** File description:
** IRiddle
*/

#pragma once

#include "common.hpp"
#include "UIText.hpp"
#include <string>
#include <vector>

namespace jam {
    class IRiddle {
        public:
            virtual ~IRiddle() = default;

            virtual sf::RectangleShape &getBackground() = 0;
            virtual ui::UIText &getQuestion() = 0;

            virtual void setPosition(const sf::Vector2f& position) = 0;
            virtual void setPosition(float x, float y) = 0;
            virtual void setDisplaySpeed(float speed) = 0;

            virtual void handleEvent(const sf::Event& event, sf::RenderWindow& window) = 0;

            virtual float getTotalTime() const = 0;
            virtual float getRemainingTime() const = 0;

            virtual bool isDisplaying() const = 0;
            virtual int isFinished() const = 0;

            virtual void render(sf::RenderTarget &window) = 0;
            virtual void update() = 0;
    };
}