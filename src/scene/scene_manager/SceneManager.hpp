/*
** EPITECH PROJECT, 2023
** Jam
** File description:
** SceneManager
*/

#ifndef SCENEMANAGER_HPP_
    #define SCENEMANAGER_HPP_

    #include "common.hpp"
    #include "IScene.hpp"

    namespace jam {

    class SceneManager {
        public:
            SceneManager();
            static SceneManager& getInstance();

            void addScene(const std::string& identifier, std::shared_ptr<IScene> scene);
            std::shared_ptr<IScene> at(const std::string& identifier);

            void setCurrentScene(const std::string& identifier);
            std::shared_ptr<IScene> getCurrentScene();

            void nextScene();
            std::shared_ptr<IScene> getNextScene();

        private:
            std::map<std::string, std::shared_ptr<IScene>> m_scenes;
            std::shared_ptr<IScene> m_currentScene;
            int m_currentSceneIndex;
            std::vector<std::shared_ptr<IScene>> m_scenesVector;
    };

    }

#endif /* !SCENEMANAGER_HPP_ */
