/*
** EPITECH PROJECT, 2023
** EpitechJam2022
** File description:
** audio
*/

#pragma once

#include "common.hpp"

namespace jam {
    namespace audio {
        extern void modulatePitch(sf::Sound& sound, float min, float max);
        extern void playMusic(const std::string& name);
        extern void stopMusic(const std::string& name);
    }
}