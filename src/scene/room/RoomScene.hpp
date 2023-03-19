/*
** EPITECH PROJECT, 2023
** EpitechJam2022
** File description:
** RoomScene
*/

#pragma once

#include "IScene.hpp"
#include "Widget.hpp"
#include "SatBox.hpp"
#include "IRiddle.hpp"
#include "Curtains.hpp"
#include "Button.hpp"

namespace jam {

    class RoomScene : public IScene {
        public:
            RoomScene();
            virtual ~RoomScene() override;
            virtual void handleEvent(sf::Event& event, sf::RenderWindow& window) override;
            virtual void update(float dt) override;
            virtual void render(sf::RenderTarget& target) override;
            virtual void restart() override;
            virtual void stop() override;

        private:
            void playEndSound();

        protected:
            std::unordered_map<std::string, std::shared_ptr<ui::Widget>> m_uiElements;
            sf::RectangleShape m_background;
            sf::RectangleShape m_backgroundColor;

            trans::Curtains m_transition;

            sf::Music* m_music = nullptr;

            sf::Sound m_tickSound;
            sf::Sound m_validateSound;
            sf::Sound m_invalidSound;
            sf::Sound m_successSound;
            sf::Sound m_mehSound;
            sf::Sound m_failSound;
            float m_tickSoundTimer;
            int m_nbRiddles;

            bool m_showSummary = false;
            sf::RectangleShape m_summaryBackground;
            ui::Text m_summaryScore;
            ui::Text m_summaryComment;
            ui::Button m_summaryNextButton;
            ui::Button m_summaryRetryButton;
            ui::Button m_summaryMenuButton;
            float m_summaryTimer;

            std::vector<std::shared_ptr<IRiddle>> m_riddles;
            std::shared_ptr<IRiddle> m_currentRiddle;
            ui::Text m_timer;
            ui::Text m_score;
            int m_scoreValue;
            int m_currentRiddleIndex;
            float m_totalTime = 0;
    };

}
