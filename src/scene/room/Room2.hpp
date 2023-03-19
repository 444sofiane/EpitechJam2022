/*
** EPITECH PROJECT, 2023
** EpitechJam2023
** File description:
** Room2
*/


#pragma once

#include "RoomScene.hpp"

namespace jam {

    class Room2 : public RoomScene {
        public:
            Room2();
            virtual ~Room2() override;
            virtual void handleEvent(sf::Event& event, sf::RenderWindow& window) override;
            virtual void update(float dt) override;
            virtual void render(sf::RenderTarget& target) override;
            virtual void restart() override;
    };

}
