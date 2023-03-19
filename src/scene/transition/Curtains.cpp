/*
** EPITECH PROJECT, 2023
** EpitechJam2022
** File description:
** Curtains
*/

#include "Curtains.hpp"
#include "info.hpp"
#include "ResourceManager.hpp"

namespace jam {
    namespace trans {

        Curtains::Curtains(sf::Texture &texture, sf::Vector2f direction, float duration) :
            _left({info::getWindowSize().x * 0.5f, info::getWindowSize().y}), _right({info::getWindowSize().x * 0.5f, info::getWindowSize().y}),
            _direction(direction), _duration(duration), _elapsed(0)
        {
            _left.setTexture(&texture);
            _left.setTextureRect(sf::IntRect(0, 0, texture.getSize().x * 0.5,
                texture.getSize().y * 0.5));
            _right.setTexture(&texture);
            _right.setTextureRect(sf::IntRect(texture.getSize().x * 0.5, 0,
                texture.getSize().x * 0.5, texture.getSize().y * 0.5));

            _sound.setBuffer(getResource().getSoundBuffer("curtain_slide"));
        }

        Curtains::~Curtains() = default;

        void Curtains::update(float dt)
        {
            sf::Vector2u wSize = info::getWindowSize();

            if (_playSound && _sound.getStatus() != sf::Sound::Playing) {
                _playSound = false;
                _sound.play();
            }

            _elapsed += dt;
            if (_elapsed > _duration)
                _elapsed = _duration;
            float progress = _elapsed / _duration;

            progress = std::pow(progress, 2);

            _left.setPosition(0, 0);
            _right.setPosition(info::getWindowSize().x * 0.5, 0);

            _left.move(-_direction.x * wSize.x * progress, 0);
            _right.move(_direction.x * wSize.x * progress, 0);
        }

        void Curtains::render(sf::RenderTarget &target)
        {
            target.draw(_left);
            target.draw(_right);
        }

        bool Curtains::isDone()
        {
            return _elapsed >= _duration;
        }

        void Curtains::restart()
        {
            _playSound = true;
            _elapsed = 0;
        }

    }
}