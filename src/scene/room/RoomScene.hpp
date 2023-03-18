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

namespace jam {

    class RoomScene : public IScene {
        public:
            RoomScene();
            virtual ~RoomScene() override;
            virtual void handleEvent(sf::Event& event, sf::RenderWindow& window) override;
            virtual void update(float dt) override;
            virtual void render(sf::RenderTarget& target) override;
        protected:
            std::unordered_map<std::string, std::shared_ptr<ui::Widget>> m_uiElements;
            sf::RectangleShape m_background;
            sf::RectangleShape m_backgroundColor;
    };

}
