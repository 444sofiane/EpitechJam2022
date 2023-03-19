/*
** EPITECH PROJECT, 2023
** Jam
** File description:
** Engine
*/

#ifndef ENGINE_HPP_
    #define ENGINE_HPP_

    #include "common.hpp"
    #include "UIText.hpp"
    #include "SceneManager.hpp"
    #include "GreyScale.hpp"

    namespace jam {
        class Engine {
            public:
                void init();
                void run();
                void switchFullscreen();
                static Engine& getInstance();

            private:
                std::unique_ptr<sf::RenderWindow> m_window;
                sf::RenderTexture m_renderTexture;
                sf::Event m_event;
                SceneManager& m_sceneManager;
                ui::Text m_fpsHint;
                shader::GreyScale m_shader;

            private:
                Engine();
                void handleEvents();
                void render();
                void update();
                void updateFpsHint();
        };
    }

#endif /* !ENGINE_HPP_ */
