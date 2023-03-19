/*
** EPITECH PROJECT, 2023
** EpitechJam2022
** File description:
** Settings
*/

#include "Settings.hpp"

namespace jam {

        Settings& Settings::getInstance()
        {
            static Settings instance;
            return instance;
        }

        float &Settings::getMusicVolume()
        {
            return m_musicVolume;
        }

        float &Settings::getSfxVolume()
        {
            return m_sfxVolume;
        }

        bool &Settings::getFullscreen()
        {
            return m_fullscreen;
        }

        bool &Settings::getRetro()
        {
            return m_blackAndWhite;
        }

        Settings::Settings()
        {
            m_musicVolume = 100;
            m_sfxVolume = 100;
            m_fullscreen = false;
            m_blackAndWhite = false;
        }
}
