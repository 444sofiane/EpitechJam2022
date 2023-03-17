/*
** EPITECH PROJECT, 2023
** Jam
** File description:
** math
*/

#ifndef MATH_HPP_
    #define MATH_HPP_

    #include "common.hpp"

    namespace jam {
        namespace math {

            #define PI 3.14159265358979323
            #define RD 0.01745329251994329

            float dist(sf::Vector2f p1, sf::Vector2f p2);
            float distSquared(sf::Vector2f p1, sf::Vector2f p2);
            sf::FloatRect multRect(sf::FloatRect rect, sf::Vector2f n);
            sf::Vector2f normalize(sf::Vector2f v);
            float dot(sf::Vector2f v1, sf::Vector2f v2);
            float cross(sf::Vector2f v1, sf::Vector2f v2);
            float angle(sf::Vector2f v1, sf::Vector2f v2);
            float length(sf::Vector2f v);
            sf::Vector2f unit(sf::Vector2f v);
            sf::Vector2f lerp(sf::Vector2f v1, sf::Vector2f v2, float t);
            float lerp(float v1, float v2, float t);
            float toDeg(float rad);
            float toRad(float deg);
        }
    }

#endif /* !MATH_HPP_ */
