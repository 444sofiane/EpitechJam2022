/*
** EPITECH PROJECT, 2023
** EpitechJam2022
** File description:
** Room3
*/

#pragma once

#include "RoomScene.hpp"

namespace jam {

    class Room3 : public RoomScene {
        public:
            Room3();
            virtual ~Room3() override;
            virtual void handleEvent(sf::Event& event, sf::RenderWindow& window) override;
            virtual void update(float dt) override;
            virtual void render(sf::RenderTarget& target) override;
            virtual void restart() override;
    };

}