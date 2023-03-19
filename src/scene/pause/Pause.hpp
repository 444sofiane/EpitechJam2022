/*
** EPITECH PROJECT, 2023
** EpitechJam2022
** File description:
** Pause
*/

#pragma once

#include "IScene.hpp"
#include "Button.hpp"
#include "UIText.hpp"

namespace jam {

    class Pause : public IScene {
        public:
            Pause();
            ~Pause() override;
            void handleEvent(sf::Event& event, sf::RenderWindow& window) override;
            void update(float dt) override;
            void render(sf::RenderTarget& target) override;
            void restart() override;
            void stop() override;
            bool isOpen() const;
            void open();
            void close();

        private:
            std::unordered_map<std::string, std::shared_ptr<ui::Widget>> m_uiElements;
            sf::RectangleShape m_background;
            ui::Text m_title;
            bool m_open;
    };

}