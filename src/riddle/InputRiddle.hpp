/*
** EPITECH PROJECT, 2023
** EpitechJam2022
** File description:
** InputRiddle
*/

#pragma once

#include "ARiddle.hpp"
#include "Rectangle.hpp"

namespace jam {

    class InputRiddle : public ARiddle {
        public:
            InputRiddle() = default;
            InputRiddle(const std::string& question, const std::string& answer);
            ~InputRiddle() override = default;

            void handleEvent(const sf::Event& event, sf::RenderWindow& window) override;

            void render(sf::RenderTarget &window) override;
            void update() override;

        private:
            bool compareAnswer();

        protected:
            std::string m_question;
            std::string m_answer;
            std::string m_input;
            ui::Text m_inputText;
            ui::Text m_inputHint;
            Rectangle m_inputBox;
            float m_lastBlink;
    };

}