/*
** EPITECH PROJECT, 2023
** EpitechJam2022
** File description:
** ClickRiddle
*/

#pragma once

#include "ARiddle.hpp"

namespace jam {

    class ClickRiddle : public ARiddle
    {
        public:
            ClickRiddle() = default;
            ClickRiddle(const std::string& question, const sf::IntRect& rect);
            ~ClickRiddle() override = default;

            void setClickRect(const sf::IntRect& rect);
            void handleEvent(const sf::Event& event, sf::RenderWindow& window) override;

            void render(sf::RenderTarget &window) override;
            void update() override;
        private:
            sf::RectangleShape m_clickRect;
    };
}