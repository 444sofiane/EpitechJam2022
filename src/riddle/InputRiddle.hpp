/*
** EPITECH PROJECT, 2023
** EpitechJam2022
** File description:
** InputRiddle
*/

#pragma once

#include "ARiddle.hpp"

namespace jam {

    class InputRiddle : public ARiddle {
        public:
            InputRiddle() = default;
            InputRiddle(const std::string& question, const std::string& answer);
            ~InputRiddle() override = default;

            void setClickRect(const sf::IntRect& rect);
            void handleEvent(const sf::Event& event, sf::RenderWindow& window) override;

            void render(sf::RenderTarget &window) override;
            void update() override;
        protected:
            std::string m_question;
            std::string m_answer;
            std::string m_input;
            ui::UIText m_inputText;
    };

}