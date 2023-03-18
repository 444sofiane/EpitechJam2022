/*
** EPITECH PROJECT, 2023
** Jam
** File description:
** ResourceManager
*/

#ifndef RESOURCEMANAGER_HPP_
    #define RESOURCEMANAGER_HPP_

    #include "common.hpp"

    #define getResource() ResourceManager::getInstance()

    namespace jam {

    class ResourceManager {
    public:
        static ResourceManager& getInstance();
        void loadAssets();
        sf::Texture& getTexture(const std::string &name);
        sf::Font& getFont(const std::string& name);
        sf::SoundBuffer& getSoundBuffer(const std::string& name);
        sf::Image& getTextureImage(const std::string& name);
        sf::Music& getMusic(const std::string& name);
    private:
        void loadMusic(const std::string& name, const std::string& filePath);
        void loadTexture(const std::string &name, const std::string &filename);
        void loadTexturesFromFolder(const std::string &folder);
        void loadFont(const std::string& name, const std::string& filePath);
        void loadSoundBuffer(const std::string& name, const std::string& filePath);
        std::map<std::string, std::unique_ptr<sf::Music>> m_musics;
        std::map<std::string, sf::Texture> m_textures;
        std::map<std::string, sf::Font> m_fonts;
        std::map<std::string, sf::SoundBuffer> m_soundBuffers;
        std::map<std::string, sf::Image> m_images;
        ResourceManager();
        ResourceManager(const ResourceManager&) = delete;
        ResourceManager& operator=(const ResourceManager&) = delete;
    };

    }

#endif /* !RESOURCEMANAGER_HPP_ */
