/*
** EPITECH PROJECT, 2023
** EpitechJam2022
** File description:
** InputRiddle
*/

#include "InputRiddle.hpp"
#include "ResourceManager.hpp"
#include "info.hpp"

namespace jam {

    InputRiddle::InputRiddle(const std::string& question, const std::string& answer)
    : ARiddle(question)
    {
        m_answer = answer;

        m_inputText.setFont(getResource().getFont("nathanFont"));
        m_inputText.setCharacterSize(30);
        m_inputText.setFillColor(sf::Color::White);
        m_inputText.setPosition({0.f, 0.f});
        m_inputText.setOutlineColor(sf::Color::Black);
        m_inputText.setOutlineThickness(2);
        m_inputText.setString(m_input);
    }

}