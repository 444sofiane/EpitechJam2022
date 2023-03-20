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

            void setCurrentScene(const std::string& identifier, bool stopPrevious = true);
            std::shared_ptr<IScene> getCurrentScene();

            void nextScene(bool stopPrevious = true);
            std::shared_ptr<IScene> getNextScene();

            std::map<std::string, std::shared_ptr<IScene>>& getScenes();

            void setCurrentSceneIndex(int index);
            int getCurrentSceneIndex() const;

        private:
            std::map<std::string, std::shared_ptr<IScene>> m_scenes;
            std::shared_ptr<IScene> m_currentScene;
            int m_currentSceneIndex;
            std::vector<std::shared_ptr<IScene>> m_scenesVector;
    };

    }

#endif /* !SCENEMANAGER_HPP_ */
