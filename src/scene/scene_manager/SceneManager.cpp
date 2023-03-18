/*
** EPITECH PROJECT, 2023
** Jam
** File description:
** SceneManager
*/

#include "SceneManager.hpp"

namespace jam {

    SceneManager::SceneManager()
    {
        m_currentScene = nullptr;
        m_currentSceneIndex = 0;
    }

    SceneManager& SceneManager::getInstance()
    {
        static SceneManager instance;
        return instance;
    }

    std::shared_ptr<IScene> SceneManager::at(const std::string& identifier)
    {
        return m_scenes.at(identifier);
    }

    void SceneManager::addScene(const std::string& identifier, std::shared_ptr<IScene> scene)
    {
        m_scenes.insert(std::make_pair(identifier, scene));
        m_scenesVector.push_back(scene);
    }

    void SceneManager::setCurrentScene(const std::string& identifier)
    {
        m_currentScene = m_scenes.at(identifier);
        m_currentScene->restart();
    }

    std::shared_ptr<IScene> SceneManager::getCurrentScene()
    {
        return m_currentScene;
    }

    std::shared_ptr<IScene> SceneManager::getNextScene()
    {
        int nextSceneIndex = m_currentSceneIndex + 1;
        if (nextSceneIndex >= m_scenesVector.size())
            nextSceneIndex = 0;
        return m_scenesVector.at(nextSceneIndex);
    }

    void SceneManager::nextScene()
    {
        m_currentSceneIndex++;
        if (m_currentSceneIndex >= m_scenesVector.size())
            m_currentSceneIndex = 0;
        m_currentScene = m_scenesVector.at(m_currentSceneIndex);
        m_currentScene->restart();
    }
}
