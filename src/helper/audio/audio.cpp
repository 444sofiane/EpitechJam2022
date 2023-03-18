/*
** EPITECH PROJECT, 2023
** EpitechJam2022
** File description:
** audio
*/

#include "audio.hpp"
#include "numberGenerator.hpp"
#include "ResourceManager.hpp"

namespace jam {
    namespace audio {
        void modulatePitch(sf::Sound& sound, float min, float max) {
            sound.setPitch(nbgen::between(min, max));
        }

        void playMusic(const std::string& name) {
            auto& music = getResource().getMusic(name);
            music.setLoop(true);
            music.play();
        }

        void stopMusic(const std::string& name) {
            auto& music = getResource().getMusic(name);
            music.stop();
        }
    }
}