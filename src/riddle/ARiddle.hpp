/*
** EPITECH PROJECT, 2023
** EpitechJam2022
** File description:
** ARiddle
*/

#pragma once

#include "IRiddle.hpp"

namespace jam {
    class ARiddle : public IRiddle {
        public:
            ARiddle() = default;
            ARiddle(const std::string& question);
            virtual ~ARiddle() = default;

            virtual sf::RectangleShape &getBackground();
            virtual ui::Text &getQuestion();

            virtual void setPosition(const sf::Vector2f& position);
            virtual void setPosition(float x, float y);
            virtual void setDisplaySpeed(float speed);

            virtual void handleEvent(const sf::Event& event, sf::RenderWindow& window) = 0;

            virtual float getTotalTime() const;
            virtual float getRemainingTime() const;

            virtual bool isDisplaying() const;
            virtual int isFinished() const;

            virtual void render(sf::RenderTarget &window);
            virtual void update();

        protected:
            sf::RectangleShape m_background;
            ui::Text m_question;
            sf::Sound m_typingSound;
            std::string m_text;
            bool m_isDisplaying;
            int m_isFinished = 0;
            float m_remainingTime;
            float m_totalTime;
            float m_displaySpeed;
            float m_displayTime;
    };
}