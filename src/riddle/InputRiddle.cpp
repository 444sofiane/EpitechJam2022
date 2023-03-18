/*
** EPITECH PROJECT, 2023
** EpitechJam2022
** File description:
** InputRiddle
*/

#include "InputRiddle.hpp"
#include "ResourceManager.hpp"
#include "info.hpp"
#include "Clock.hpp"

namespace jam {

    InputRiddle::InputRiddle(const std::string& question, const std::string& answer)
    : ARiddle(question)
    {
        m_answer = answer;
        m_lastBlink = Clock::getInstance().getElapsedTime().asSeconds();

        sf::Vector2u pos = info::getWindowSize();

        m_background.setFillColor(sf::Color(0, 100, 0, 220));

        m_inputText.setFont(getResource().getFont("nathanFont"));
        m_inputText.setCharacterSize(40);
        m_inputText.setFillColor(sf::Color::White);
        m_inputText.setPosition(sf::Vector2f(pos.x * 0.5, pos.y * 0.8));
        m_inputText.setOutlineColor(sf::Color::Black);
        m_inputText.setOutlineThickness(1);
        m_inputText.setString(m_input);

        m_inputHint.setFont(getResource().getFont("nathanFont"));
        m_inputHint.setCharacterSize(40);
        m_inputHint.setFillColor(sf::Color::White);
        m_inputHint.setPosition({m_inputText.getPosition().x + m_inputText.getGlobalBounds().width * 0.5,
            m_inputText.getPosition().y});
        m_inputHint.setOutlineColor(sf::Color::Black);
        m_inputHint.setOutlineThickness(1);
        m_inputHint.setOrigin(m_inputHint.getGlobalBounds().width / 2,
            m_inputHint.getGlobalBounds().height / 2);
        m_inputHint.setString("|");

        m_inputBox.setPosition(sf::Vector2f(pos.x * 0.5, pos.y * 0.8));
        m_inputBox.setFillColor(sf::Color(255, 255, 255, 150));
        m_inputBox.setOutlineColor(sf::Color::Black);
        m_inputBox.setOutlineThickness(2);
    }

    bool InputRiddle::compareAnswer()
    {
        std::string input = m_input;
        std::string answer = m_answer;

        input.erase(remove(input.begin(), input.end(), ' '), input.end());
        input.erase(remove(input.begin(), input.end(), '\t'), input.end());
        input.erase(remove(input.begin(), input.end(), '\n'), input.end());
        answer.erase(remove(answer.begin(), answer.end(), ' '), answer.end());
        answer.erase(remove(answer.begin(), answer.end(), '\t'), answer.end());
        answer.erase(remove(answer.begin(), answer.end(), '\n'), answer.end());

        unsigned int sz = answer.size();
        if (input.size() != sz)
            return false;
        for (unsigned int i = 0; i < sz; ++i)
            if (tolower(answer[i]) != tolower(input[i]))
                return false;
        return true;
    }

    void InputRiddle::handleEvent(const sf::Event& event, sf::RenderWindow& window)
    {
        if (isDisplaying())
            return;
        if (event.type == sf::Event::TextEntered) {
            if (event.text.unicode == 8) {
                if (m_input.size() > 0)
                    m_input.pop_back();
            } else if (event.text.unicode == 13) {
                if (compareAnswer()) {
                    m_isFinished = true;
                }
            } else if (event.text.unicode < 128 && event.text.unicode > 31) {
                m_input += static_cast<char>(event.text.unicode);
            }
            m_inputText.setString(m_input);
            m_inputText.setOrigin(m_inputText.getGlobalBounds().width / 2,
                m_inputText.getGlobalBounds().height / 2);
        }
    }

    void InputRiddle::update()
    {
        ARiddle::update();

        m_inputBox.setSize(sf::Vector2f(m_inputText.getGlobalBounds().width + 100,
            m_inputText.getGlobalBounds().height + 50));

        m_inputBox.setOrigin(m_inputBox.getSize().x / 2, m_inputBox.getSize().y / 2);

        m_inputBox.setPosition(sf::Vector2f(m_inputText.getPosition().x,
            m_inputText.getPosition().y + m_inputText.getGlobalBounds().height * 0.3));

        m_inputHint.setPosition({m_inputText.getPosition().x + m_inputText.getGlobalBounds().width * 0.5, m_inputBox.getPosition().y - m_inputBox.getSize().y * 0.3});

        if (Clock::getInstance().getElapsedTime().asSeconds() - m_lastBlink > 0.5) {
            m_inputHint.setString(m_inputHint.getString() == "|" ? " " : "|");
            m_lastBlink = Clock::getInstance().getElapsedTime().asSeconds();
        }
    }

    void InputRiddle::render(sf::RenderTarget& target)
    {
        ARiddle::render(target);
        if (isDisplaying())
            return;
        target.draw(m_inputBox);
        target.draw(m_inputHint);
        target.draw(m_inputText);
    }

}