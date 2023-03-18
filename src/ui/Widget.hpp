/*
** EPITECH PROJECT, 2023
** Jam
** File description:
** Widget
*/

#ifndef IWidget_HPP_
    #define IWidget_HPP_

    #include "common.hpp"

    namespace jam {

    namespace ui
    {
        class Widget
        {
        public:
            virtual ~Widget() = default;
            virtual void handleEvent(sf::Event e, const sf::RenderWindow &window) = 0;
            virtual void setPosition(const sf::Vector2f &pos) = 0;
            virtual sf::Vector2f getSize() const = 0;
            virtual void render(sf::RenderTarget &target) = 0;

            class Text : public sf::Text
            {
            public:
                Text();
            };
        };
    }

    }

#endif /* !IWidget_HPP_ */
