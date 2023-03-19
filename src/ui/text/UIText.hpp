/*
** EPITECH PROJECT, 2023
** Jam
** File description:
** UIText
*/

#ifndef UITEXT_HPP_
    #define UITEXT_HPP_

    #include "Widget.hpp"

    namespace jam {

    namespace ui {
        class Text : public Widget, public Widget::Text {
            public:
                Text();
                Text(const std::string& text);
                ~Text() override;
                void handleEvent(sf::Event e, const sf::RenderWindow& window) override;
                void setPosition(const sf::Vector2f& pos) override;
                sf::Vector2f getSize() const override;
                void render(sf::RenderTarget& target) override;
        };
    }

    }

#endif /* !UITEXT_HPP_ */
