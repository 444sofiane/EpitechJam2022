/*
** EPITECH PROJECT, 2023
** EpitechJam2022
** File description:
** ARiddle
*/

#include "ARiddle.hpp"
#include "Clock.hpp"
#include "ResourceManager.hpp"

namespace jam {

    ARiddle::ARiddle(const std::string &question)
    {
        m_displaySpeed = 0.065f;
        m_displayTime = 0.0f;
        m_totalTime = 30.0f;
        m_remainingTime = m_totalTime;
        m_text = question;

        m_isDisplaying = true;

        m_typingSound.setBuffer(getResource().getSoundBuffer("typing"));

        m_question.setFont(getResource().getFont("nathanFont"));
        m_question.setString("");
        m_question.setCharacterSize(50);

        m_background.setOutlineColor(sf::Color::Black);
        m_background.setOutlineThickness(2);
    }

    sf::RectangleShape &ARiddle::getBackground()
    {
        return m_background;
    }

    ui::UIText &ARiddle::getQuestion()
    {
        return m_question;
    }

    void ARiddle::setPosition(const sf::Vector2f &position)
    {
        m_background.setPosition(position);
        m_question.setPosition(position);
    }

    void ARiddle::setPosition(float x, float y)
    {
        m_background.setPosition(x, y);
        m_question.setPosition({x, y});
    }

    void ARiddle::setDisplaySpeed(float speed)
    {
        m_displaySpeed = speed;
    }

    void ARiddle::render(sf::RenderTarget& window)
    {
        window.draw(m_background);
        window.draw(m_question);
    }

    void ARiddle::update()
    {
        std::string str = m_question.getString();

        if (m_isDisplaying && m_typingSound.getStatus() != sf::Sound::Playing) {
            m_typingSound.play();
        }

        if (!m_isDisplaying)
            m_typingSound.stop();

        m_displayTime += getClock().getFrameDt();
        if (m_displayTime >= m_displaySpeed && str.size() < m_text.size()) {
            m_isDisplaying = true;
            m_displayTime = 0.0f;
            str += m_text[str.size()];
            m_question.setString(str);
        } else if (str.size() >= m_text.size()) {
            m_isDisplaying = false;
            m_remainingTime -= getClock().getFrameDt();
        }
        m_question.setOrigin(m_question.getGlobalBounds().width / 2.0f, m_question.getGlobalBounds().height / 2.0f);
        m_background.setSize({m_question.getGlobalBounds().width + m_question.getCharacterSize(),
        m_question.getGlobalBounds().height + m_question.getCharacterSize()});
        m_background.setOrigin(m_background.getSize() / 2.0f);
        m_question.setPosition({m_background.getPosition().x,
            m_background.getPosition().y - m_question.getCharacterSize() / 4.0f});

        if (m_remainingTime <= 0.0f) {
            m_isFinished = -1;
        }
    }

    bool ARiddle::isDisplaying() const
    {
        return m_isDisplaying;
    }

    int ARiddle::isFinished() const
    {
        return m_isFinished;
    }

    float ARiddle::getTotalTime() const
    {
        return m_totalTime;
    }

    float ARiddle::getRemainingTime() const
    {
        return m_remainingTime;
    }
}