/*
** EPITECH PROJECT, 2023
** EpitechJam2022
** File description:
** RoomSummary
*/

#include "RoomSummary.hpp"
#include "info.hpp"
#include "ResourceManager.hpp"
#include "SceneManager.hpp"
#include "RoomScene.hpp"
#include "Clock.hpp"
#include <sstream>
#include <iomanip>

namespace jam {

    RoomSummary::RoomSummary()
    : m_summaryMenuButton(getResource().getTexture("generic_button"), "To Menu")
    , m_summaryNextButton(getResource().getTexture("generic_button"), "Next Level")
    , m_summaryRetryButton(getResource().getTexture("generic_button"), "Retry")
    {
        sf::Vector2f wSize = sf::Vector2f(info::getWindowSize());

        m_summaryMenuButton.setPosition({info::getWindowSize().x * 0.5, info::getWindowSize().y * 0.5});
        m_summaryMenuButton.setBaseScale(3.0f, 3.0f);
        m_summaryMenuButton.getLabel().setFont(getResource().getFont("nathanFont"));
        m_summaryMenuButton.getLabel().setCharacterSize(50);
        m_summaryMenuButton.setFunction([] { SceneManager::getInstance().setCurrentScene("Main Menu"); });

        m_summaryNextButton.setPosition({info::getWindowSize().x * 0.5, info::getWindowSize().y * 0.6});
        m_summaryNextButton.setBaseScale(3.0f, 3.0f);
        m_summaryNextButton.getLabel().setFont(getResource().getFont("nathanFont"));
        m_summaryNextButton.getLabel().setCharacterSize(50);
        m_summaryNextButton.setFunction([] {
            if (RoomScene* nextScene = dynamic_cast<RoomScene*>(SceneManager::getInstance().getNextScene().get())) {
                SceneManager::getInstance().nextScene();
            } else {
                SceneManager::getInstance().setCurrentScene("Credits");
            }
        });

        m_summaryRetryButton.setPosition({info::getWindowSize().x * 0.5, info::getWindowSize().y * 0.7});
        m_summaryRetryButton.setBaseScale(3.0f, 3.0f);
        m_summaryRetryButton.getLabel().setFont(getResource().getFont("nathanFont"));
        m_summaryRetryButton.getLabel().setCharacterSize(50);
        m_summaryRetryButton.setFunction([] { SceneManager::getInstance().getCurrentScene()->restart(); });

        m_summaryBackground.setSize({800.f, 600.f});
        m_summaryBackground.setFillColor(sf::Color(0, 0, 0, 230));
        m_summaryBackground.setPosition({wSize.x * 0.5f, wSize.y * 0.5f});
        m_summaryBackground.setOrigin(m_summaryBackground.getSize().x / 2, m_summaryBackground.getSize().y / 2);
        m_summaryBackground.setOutlineColor(sf::Color::Black);
        m_summaryBackground.setOutlineThickness(4);

        m_summaryScore.setFont(getResource().getFont("nathanFont"));
        m_summaryScore.setCharacterSize(50);
        m_summaryScore.setPosition({wSize.x * 0.5, wSize.y * 0.4});

        m_summaryComment.setFont(getResource().getFont("nathanFont"));
        m_summaryComment.setCharacterSize(50);
        m_summaryComment.setPosition({wSize.x * 0.5, wSize.y * 0.3});
    }

    void RoomSummary::restart()
    {
    }

    void RoomSummary::handleEvent(sf::Event &event, sf::RenderWindow &window)
    {
        m_summaryMenuButton.handleEvent(event, window);
        m_summaryNextButton.handleEvent(event, window);
        m_summaryRetryButton.handleEvent(event, window);
    }

    void RoomSummary::update(float dt)
    {
        std::stringstream stream;
        stream << std::fixed << std::setprecision(2) << m_totalTime;
        std::string time = stream.str();

        m_summaryComment.setString("You have finished the room in " + time + " seconds");
        m_summaryComment.setOrigin(m_summaryComment.getGlobalBounds().width / 2,
            m_summaryComment.getGlobalBounds().height / 2);

        m_summaryScore.setString("Score : " + std::to_string(m_scoreValue) + " / " + std::to_string(m_nbRiddles));
        m_summaryScore.setOrigin(m_summaryScore.getGlobalBounds().width / 2,
            m_summaryScore.getGlobalBounds().height / 2);

    }

    void RoomSummary::render(sf::RenderTarget &target)
    {
        target.draw(m_summaryBackground);
        m_summaryMenuButton.render(target);
        m_summaryNextButton.render(target);
        m_summaryRetryButton.render(target);
        target.draw(m_summaryComment);
        target.draw(m_summaryScore);
    }

    void RoomSummary::stop()
    {
    }

    void RoomSummary::setScore(int score)
    {
        m_scoreValue = score;
    }

    void RoomSummary::setNbRiddles(int nbRiddles)
    {
        m_nbRiddles = nbRiddles;
    }

    void RoomSummary::setTotalTime(float totalTime)
    {
        m_totalTime = totalTime;
    }

    RoomSummary::~RoomSummary()
    {
    }
}