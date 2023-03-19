/*
** EPITECH PROJECT, 2023
** EpitechJam2022
** File description:
** RoomSummary
*/

#pragma once

#include "IScene.hpp"
#include "Button.hpp"
#include "UIText.hpp"

namespace jam {
    class RoomSummary : public IScene {
        public:
            RoomSummary();
            ~RoomSummary() override;
            void handleEvent(sf::Event& event, sf::RenderWindow& window) override;
            void update(float dt) override;
            void render(sf::RenderTarget& target) override;
            void restart() override;
            void stop() override;
            void setScore(int score);
            void setNbRiddles(int nbRiddles);
            void setTotalTime(float totalTime);

        private:
            sf::RectangleShape m_summaryBackground;
            ui::Text m_summaryScore;
            ui::Text m_summaryComment;
            ui::Button m_summaryNextButton;
            ui::Button m_summaryRetryButton;
            ui::Button m_summaryMenuButton;
            int m_nbRiddles;
            int m_scoreValue;
            float m_totalTime;
    };
}