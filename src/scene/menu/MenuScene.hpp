/*
** EPITECH PROJECT, 2023
** Jam
** File description:
** MenuScene
*/

#ifndef MENUSCENE_HPP_
    #define MENUSCENE_HPP_

    #include "IScene.hpp"
    #include "Widget.hpp"

    namespace jam {

    class MenuScene : public IScene {
        public:
            MenuScene();
            virtual ~MenuScene() override;
            virtual void handleEvent(sf::Event& event, sf::RenderWindow& window) override;
            virtual void update(float dt) override;
            virtual void render(sf::RenderTarget& target) override;
            virtual void restart() override {};
            virtual void stop() override;
        protected:
            std::unordered_map<std::string, std::shared_ptr<ui::Widget>> m_uiElements;
            sf::RectangleShape m_background;
            sf::Music* m_music = nullptr;
    };

    }

#endif /* !MENUSCENE_HPP_ */
