/*
** EPITECH PROJECT, 2023
** EpitechJam2022
** File description:
** GreyScale
*/

#pragma once

#include "common.hpp"

namespace jam {
    namespace shader {
        class GreyScale : public sf::Shader {
            public:
                GreyScale();

                virtual ~GreyScale();
                sf::Sprite& apply(sf::RenderTexture& target);

            private:
                sf::Sprite m_sprite;
        };
    }
}