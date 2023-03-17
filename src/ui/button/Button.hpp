/*
** EPITECH PROJECT, 2023
** Jam
** File description:
** Button
*/

#ifndef BUTTON_HPP_
    #define BUTTON_HPP_

    #include "Widget.hpp"
    #include "Animation.hpp"
    #include "Rectangle.hpp"
    #include <functional>

    namespace jam {

    namespace ui {
        class Button : public Widget, public Rectangle {
            public:
                enum State { IDLE, HOVERED, PRESSED };
                Button(const sf::Texture& texture, const std::string& label);
                void setFunction(std::function<void(void)> func);
                void setLabel(const std::string& label);
                virtual void handleEvent(sf::Event e, const sf::RenderWindow& window) override;
                virtual void setPosition(const sf::Vector2f& pos) override;
                virtual sf::Vector2f getSize() const override;
                virtual void render(sf::RenderTarget& target) override;

            protected:
                Text m_label;
                Animation m_animation;
                State m_state;
                std::function<void(void)> m_function = []() {};
        };
    }

    }

#endif /* !BUTTON_HPP_ */