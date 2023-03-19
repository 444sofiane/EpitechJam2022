/*
** EPITECH PROJECT, 2023
** EpitechJam2022
** File description:
** Curtains
*/

#pragma once

#include "ITransition.hpp"

namespace jam {
    namespace trans {
        class Curtains : public ITransition
        {
        public:
            Curtains() = default;
            Curtains(sf::Texture &texture, sf::Vector2f direction, float duration);
            virtual ~Curtains() override;
            virtual void update(float dt) override;
            virtual void render(sf::RenderTarget &target) override;
            virtual bool isDone() override;
            virtual void restart() override;

        private:
            sf::RectangleShape _left;
            sf::RectangleShape _right;
            sf::Sound _sound;
            sf::Vector2f _direction;
            bool _playSound;
            float _duration;
            float _elapsed;
        };
    }
}