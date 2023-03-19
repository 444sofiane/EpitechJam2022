/*
** EPITECH PROJECT, 2023
** EpitechJam2022
** File description:
** Settings
*/

#pragma once

#include "common.hpp"

#define SETTINGS jam::Settings::getInstance()

namespace jam {

    class Settings {
        public:

            static Settings& getInstance();

            float &getMusicVolume();
            float &getSfxVolume();
            bool &getFullscreen();
            bool &getRetro();

        private:
            Settings();
            float m_musicVolume;
            float m_sfxVolume;
            bool m_fullscreen;
            bool m_blackAndWhite;
    };

}