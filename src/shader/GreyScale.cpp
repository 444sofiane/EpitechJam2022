/*
** EPITECH PROJECT, 2023
** EpitechJam2022
** File description:
** GreyScale
*/

#include "GreyScale.hpp"

namespace jam {
    namespace shader {
        GreyScale::GreyScale() {
            loadFromMemory(
                    "uniform sampler2D texture;"

                    "void main() {"
                    "   vec4 color = texture2D(texture, gl_TexCoord[0].xy);"
                    "   float grey = dot(color.rgb, vec3(0.299, 0.587, 0.114));"
                    "   gl_FragColor = vec4(grey, grey, grey, color.a);"
                    "}"
            , sf::Shader::Fragment);
        }

        GreyScale::~GreyScale() = default;

        sf::Sprite& GreyScale::apply(sf::RenderTexture &target)
        {
            setUniform("texture", sf::Shader::CurrentTexture);
            sf::RenderStates states;
            states = sf::RenderStates::Default;
            states.shader = this;
            m_sprite.setTexture(target.getTexture());
            target.draw(m_sprite, states);
            m_sprite.setTexture(target.getTexture());
            return m_sprite;
        }
    }
}