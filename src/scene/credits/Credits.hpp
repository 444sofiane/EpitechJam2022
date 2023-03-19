/*
** EPITECH PROJECT, 2023
** EpitechJam2022
** File description:
** Credits
*/

#pragma once

#include "IScene.hpp"
#include "Widget.hpp"
#include "Curtains.hpp"
#include "UIText.hpp"

namespace jam {

    class Credits : public IScene {
        public:
            Credits();
            ~Credits() override = default;
            void handleEvent(sf::Event& event, sf::RenderWindow& window) override;
            void update(float dt) override;
            void render(sf::RenderTarget& target) override;
            void restart() override;
            void stop() override;
        private:
            std::map<std::string, std::shared_ptr<ui::Widget>> m_uiElements;
            sf::RectangleShape m_backgroundColor;
            sf::RectangleShape m_background;
            std::vector<std::unique_ptr<sf::Text>> m_credits;
            sf::Music* m_music = nullptr;
            trans::Curtains m_transition;
    };
}