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
                Engine();
                ~Engine();
                void init();
                void run();

            private:
                std::unique_ptr<sf::RenderWindow> m_window;
                sf::RenderTexture m_renderTexture;
                sf::Event m_event;
                SceneManager& m_sceneManager;
                ui::Text m_fpsHint;
                shader::GreyScale m_shader;

            private:
                void switchFullscreen();
                void handleEvents();
                void render();
                void update();
                void updateFpsHint();
        };
    }

#endif /* !ENGINE_HPP_ */
