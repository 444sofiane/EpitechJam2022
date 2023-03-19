/*
** EPITECH PROJECT, 2023
** EpitechJam2022
** File description:
** ITransition
*/

#pragma once

#include "common.hpp"

namespace jam {
    namespace trans {
        class ITransition
        {
        public:
            virtual ~ITransition() = default;
            virtual void update(float dt) = 0;
            virtual void render(sf::RenderTarget &target) = 0;
            virtual bool isDone() = 0;
            virtual void restart() = 0;
        };
    }
}
