/*
** EPITECH PROJECT, 2023
** EpitechJam2022
** File description:
** LevelSelector
*/

#pragma once

#include "IScene.hpp"
#include "Widget.hpp"
#include "Curtains.hpp"

namespace jam {
    class LevelSelector : public IScene {
        public:
            LevelSelector();
            ~LevelSelector() override;
            void handleEvent(sf::Event& event, sf::RenderWindow& window) override;
            void update(float dt) override;
            void render(sf::RenderTarget& target) override;
            void restart() override;
            void stop() override;

        protected:
            std::map<std::string, std::shared_ptr<ui::Widget>> m_uiElements;
            std::map<std::string, std::shared_ptr<IScene>>& m_scenesRef;
            sf::RectangleShape m_background;
            trans::Curtains m_transition;
            sf::Music* m_music = nullptr;
    };
}
