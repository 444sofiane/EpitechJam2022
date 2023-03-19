/*
** EPITECH PROJECT, 2023
** EpitechJam2022
** File description:
** Room4
*/

#pragma once

#include "RoomScene.hpp"

namespace jam {

    class Room4 : public RoomScene {
        public:
            Room4();
            virtual ~Room4() override;
            virtual void handleEvent(sf::Event& event, sf::RenderWindow& window) override;
            virtual void update(float dt) override;
            virtual void render(sf::RenderTarget& target) override;
            virtual void restart() override;
    };

}