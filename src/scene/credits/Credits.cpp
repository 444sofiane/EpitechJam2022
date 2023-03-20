/*
** EPITECH PROJECT, 2023
** EpitechJam2022
** File description:
** Credits
*/

#include "Credits.hpp"
#include "info.hpp"
#include "ResourceManager.hpp"
#include "SceneManager.hpp"
#include "Button.hpp"
#include "RoomScene.hpp"

namespace jam {

    Credits::Credits()
    {
        sf::Vector2u windowSize = info::getWindowSize();

        m_transition = trans::Curtains(getResource().getTexture("curtains"), sf::Vector2f(1, 0), 1.5f);

        m_backgroundColor.setSize(sf::Vector2f(windowSize));
        m_backgroundColor.setFillColor(sf::Color(0, 0, 0, 255));

        m_background.setSize(sf::Vector2f(windowSize));
        m_background.setTexture(&getResource().getTexture("credits_bg"));

        m_uiElements["Skip"] = std::make_shared<ui::Button>(getResource().getTexture("generic_button"), "Skip");

        ui::Button* skipButton = ((ui::Button*)m_uiElements.at("Skip").get());
        skipButton->setPosition({windowSize.x * 0.5, windowSize.y * 0.9});
        skipButton->getLabel().setFont((getResource().getFont("nathanFont")));
        skipButton->setBaseScale(3.0f, 3.0f);
        skipButton->getLabel().setCharacterSize(50);
        skipButton->setFunction([] { SceneManager::getInstance().setCurrentScene("Main Menu"); });

        m_credits.push_back(std::make_unique<ui::Text>("Credits"));
        m_credits.push_back(std::make_unique<ui::Text>(""));
        m_credits.push_back(std::make_unique<ui::Text>(""));
        m_credits.push_back(std::make_unique<ui::Text>(""));
        m_credits.push_back(std::make_unique<ui::Text>(""));
        m_credits.push_back(std::make_unique<ui::Text>("Thanks for playing our game!"));
        m_credits.push_back(std::make_unique<ui::Text>(""));
        m_credits.push_back(std::make_unique<ui::Text>(""));
        m_credits.push_back(std::make_unique<ui::Text>("-Programmers-"));
        m_credits.push_back(std::make_unique<ui::Text>("Aurelien Lamberger"));
        m_credits.push_back(std::make_unique<ui::Text>("Hugo Moine"));
        m_credits.push_back(std::make_unique<ui::Text>("Tochi Borchashvili"));
        m_credits.push_back(std::make_unique<ui::Text>("Sofiane Saou"));
        m_credits.push_back(std::make_unique<ui::Text>("Lucas Hoch"));
        m_credits.push_back(std::make_unique<ui::Text>("Basile Trebus"));
        m_credits.push_back(std::make_unique<ui::Text>(""));
        m_credits.push_back(std::make_unique<ui::Text>("-Game Design-"));
        m_credits.push_back(std::make_unique<ui::Text>("Sofiane Saou"));
        m_credits.push_back(std::make_unique<ui::Text>(""));
        m_credits.push_back(std::make_unique<ui::Text>("-Lead Programmer-"));
        m_credits.push_back(std::make_unique<ui::Text>("Basile Trebus"));
        m_credits.push_back(std::make_unique<ui::Text>(""));
        m_credits.push_back(std::make_unique<ui::Text>("-Bingle dongler-"));
        m_credits.push_back(std::make_unique<ui::Text>("Lucas Hoch"));
        m_credits.push_back(std::make_unique<ui::Text>(""));
        m_credits.push_back(std::make_unique<ui::Text>("-Music-"));
        m_credits.push_back(std::make_unique<ui::Text>("Aurelien Lamberger"));
        m_credits.push_back(std::make_unique<ui::Text>(""));
        m_credits.push_back(std::make_unique<ui::Text>("-Sound Effects-"));
        m_credits.push_back(std::make_unique<ui::Text>("Hugo Moine"));
        m_credits.push_back(std::make_unique<ui::Text>(""));
        m_credits.push_back(std::make_unique<ui::Text>("-Caca master-"));
        m_credits.push_back(std::make_unique<ui::Text>("Tochi Borchashvili"));
        m_credits.push_back(std::make_unique<ui::Text>(""));
        m_credits.push_back(std::make_unique<ui::Text>("-Lead Director-"));
        m_credits.push_back(std::make_unique<ui::Text>("Hideo Kojima"));
        m_credits.push_back(std::make_unique<ui::Text>(""));
        m_credits.push_back(std::make_unique<ui::Text>("-Executive Producer-"));
        m_credits.push_back(std::make_unique<ui::Text>("Hideo Kojima"));
        m_credits.push_back(std::make_unique<ui::Text>(""));
        m_credits.push_back(std::make_unique<ui::Text>("-Producer-"));
        m_credits.push_back(std::make_unique<ui::Text>("Hideo Kojima"));
        m_credits.push_back(std::make_unique<ui::Text>(""));
        m_credits.push_back(std::make_unique<ui::Text>("-Director-"));
        m_credits.push_back(std::make_unique<ui::Text>("Hideo Kojima"));
        m_credits.push_back(std::make_unique<ui::Text>(""));
        m_credits.push_back(std::make_unique<ui::Text>("-Lead Designer-"));
        m_credits.push_back(std::make_unique<ui::Text>("Hideo Kojima"));
        m_credits.push_back(std::make_unique<ui::Text>(""));
        m_credits.push_back(std::make_unique<ui::Text>("-Game Designer-"));
        m_credits.push_back(std::make_unique<ui::Text>("Hideo Kojima"));
        m_credits.push_back(std::make_unique<ui::Text>(""));
        m_credits.push_back(std::make_unique<ui::Text>(""));
        m_credits.push_back(std::make_unique<ui::Text>("-Special Thanks To-"));
        m_credits.push_back(std::make_unique<ui::Text>("Hideo Kojima"));
        m_credits.push_back(std::make_unique<ui::Text>("Hideo Kojima"));
        m_credits.push_back(std::make_unique<ui::Text>("Hideo Kojima"));
        m_credits.push_back(std::make_unique<ui::Text>("Kevin Spegt"));
        m_credits.push_back(std::make_unique<ui::Text>("Hideo Kojima"));
        m_credits.push_back(std::make_unique<ui::Text>("Leo Fornes"));
        m_credits.push_back(std::make_unique<ui::Text>("Hideo Kojima"));
        m_credits.push_back(std::make_unique<ui::Text>("Hideo Kojima"));
        m_credits.push_back(std::make_unique<ui::Text>("Alexis Walter"));
        m_credits.push_back(std::make_unique<ui::Text>("Luc Besson"));
        m_credits.push_back(std::make_unique<ui::Text>("George Lucas"));
        m_credits.push_back(std::make_unique<ui::Text>("Hideo Kojima"));
        m_credits.push_back(std::make_unique<ui::Text>(""));
        m_credits.push_back(std::make_unique<ui::Text>(""));
        m_credits.push_back(std::make_unique<ui::Text>("In memory of Julian Lambert"));
        m_credits.push_back(std::make_unique<ui::Text>(""));
        m_credits.push_back(std::make_unique<ui::Text>(""));
        m_credits.push_back(std::make_unique<ui::Text>("Copyleft 2020"));
        m_credits.push_back(std::make_unique<ui::Text>(""));
        m_credits.push_back(std::make_unique<ui::Text>("Game made for the 2023 Game Jam"));
        m_credits.push_back(std::make_unique<ui::Text>(""));
        m_credits.push_back(std::make_unique<ui::Text>("All rights reserved"));
        m_credits.push_back(std::make_unique<ui::Text>("Trademark of Hideo Kojima"));
        m_credits.push_back(std::make_unique<ui::Text>(""));
        m_credits.push_back(std::make_unique<ui::Text>(""));
        m_credits.push_back(std::make_unique<ui::Text>(""));
        m_credits.push_back(std::make_unique<ui::Text>(""));
        m_credits.push_back(std::make_unique<ui::Text>(""));
        m_credits.push_back(std::make_unique<ui::Text>(""));
        m_credits.push_back(std::make_unique<ui::Text>(""));
        m_credits.push_back(std::make_unique<ui::Text>(""));
        m_credits.push_back(std::make_unique<ui::Text>(""));
        m_credits.push_back(std::make_unique<ui::Text>(""));
        m_credits.push_back(std::make_unique<ui::Text>(""));
        m_credits.push_back(std::make_unique<ui::Text>(""));
        m_credits.push_back(std::make_unique<ui::Text>(""));
        m_credits.push_back(std::make_unique<ui::Text>(""));
        m_credits.push_back(std::make_unique<ui::Text>(""));
        m_credits.push_back(std::make_unique<ui::Text>(""));
        m_credits.push_back(std::make_unique<ui::Text>(""));
        m_credits.push_back(std::make_unique<ui::Text>(""));
        m_credits.push_back(std::make_unique<ui::Text>(""));
        m_credits.push_back(std::make_unique<ui::Text>(""));
        m_credits.push_back(std::make_unique<ui::Text>(""));
        m_credits.push_back(std::make_unique<ui::Text>(""));
        m_credits.push_back(std::make_unique<ui::Text>(""));
        m_credits.push_back(std::make_unique<ui::Text>(""));
        m_credits.push_back(std::make_unique<ui::Text>(""));
        m_credits.push_back(std::make_unique<ui::Text>(""));
        m_credits.push_back(std::make_unique<ui::Text>(""));
        m_credits.push_back(std::make_unique<ui::Text>("Please its time to skip now"));
        m_credits.push_back(std::make_unique<ui::Text>(""));
        m_credits.push_back(std::make_unique<ui::Text>(""));
        m_credits.push_back(std::make_unique<ui::Text>(""));
        m_credits.push_back(std::make_unique<ui::Text>(""));
        m_credits.push_back(std::make_unique<ui::Text>(""));
        m_credits.push_back(std::make_unique<ui::Text>(""));
        m_credits.push_back(std::make_unique<ui::Text>(""));
        m_credits.push_back(std::make_unique<ui::Text>(""));
        m_credits.push_back(std::make_unique<ui::Text>(""));
        m_credits.push_back(std::make_unique<ui::Text>(""));
        m_credits.push_back(std::make_unique<ui::Text>(""));
        m_credits.push_back(std::make_unique<ui::Text>(""));
        m_credits.push_back(std::make_unique<ui::Text>(""));
        m_credits.push_back(std::make_unique<ui::Text>(""));
        m_credits.push_back(std::make_unique<ui::Text>(""));
        m_credits.push_back(std::make_unique<ui::Text>(""));
        m_credits.push_back(std::make_unique<ui::Text>(""));
        m_credits.push_back(std::make_unique<ui::Text>(""));
        m_credits.push_back(std::make_unique<ui::Text>(""));
        m_credits.push_back(std::make_unique<ui::Text>(""));
        m_credits.push_back(std::make_unique<ui::Text>(""));
        m_credits.push_back(std::make_unique<ui::Text>(""));
        m_credits.push_back(std::make_unique<ui::Text>(""));
        m_credits.push_back(std::make_unique<ui::Text>("Really, its time to skip now"));
        m_credits.push_back(std::make_unique<ui::Text>(""));
        m_credits.push_back(std::make_unique<ui::Text>(""));
        m_credits.push_back(std::make_unique<ui::Text>(""));
        m_credits.push_back(std::make_unique<ui::Text>(""));
        m_credits.push_back(std::make_unique<ui::Text>(""));
        m_credits.push_back(std::make_unique<ui::Text>(""));
        m_credits.push_back(std::make_unique<ui::Text>(""));
        m_credits.push_back(std::make_unique<ui::Text>(""));
        m_credits.push_back(std::make_unique<ui::Text>(""));
        m_credits.push_back(std::make_unique<ui::Text>(""));
        m_credits.push_back(std::make_unique<ui::Text>(""));
        m_credits.push_back(std::make_unique<ui::Text>(""));
        m_credits.push_back(std::make_unique<ui::Text>(""));
        m_credits.push_back(std::make_unique<ui::Text>("Please, its time to skip now"));
        m_credits.push_back(std::make_unique<ui::Text>(""));
        m_credits.push_back(std::make_unique<ui::Text>(""));
        m_credits.push_back(std::make_unique<ui::Text>(""));
        m_credits.push_back(std::make_unique<ui::Text>(""));
        m_credits.push_back(std::make_unique<ui::Text>(""));
        m_credits.push_back(std::make_unique<ui::Text>(""));
        m_credits.push_back(std::make_unique<ui::Text>(""));
        m_credits.push_back(std::make_unique<ui::Text>(""));
        m_credits.push_back(std::make_unique<ui::Text>(""));
        m_credits.push_back(std::make_unique<ui::Text>("Ok, fuck you then"));
        m_credits.push_back(std::make_unique<ui::Text>(""));


        int i = 0;
        for (auto& line : m_credits) {
            line->setCharacterSize(50);
            line->setFont(getResource().getFont("nathanFont"));
            line->setFillColor(sf::Color::White);
            i++;
        }

        m_credits.at(0)->setCharacterSize(100);

        i = 0;
        for (auto& line : m_credits) {
            line->setPosition({windowSize.x * 0.5, windowSize.y * 0.9 + (i * line->getCharacterSize() * 1.5)});
            line->setOrigin(line->getGlobalBounds().width / 2, line->getGlobalBounds().height / 2);
            i++;
        }

        m_music = &getResource().getMusic("credits");
    }

    int Credits::getTotalBest()
    {
        int total = 0;
        for (auto& [key, scene] : SceneManager::getInstance().getScenes()) {
            if (dynamic_cast<RoomScene*>(scene.get()) == nullptr) {
                continue;
            }
            total += dynamic_cast<RoomScene*>(scene.get())->getBest();
        }
        return total;
    }

    void Credits::handleEvent(sf::Event& event, sf::RenderWindow& window)
    {
        if (!m_transition.isDone())
            return;

        for (auto& [key, element] : m_uiElements) {
            element->handleEvent(event, window);
        }
    }

    void Credits::update(float dt)
    {
        if (!m_transition.isDone()) {
            m_transition.update(dt);
            return;
        }

        for (auto& line : m_credits) {
            line->move(0, -dt * 100);
        }

        if (m_credits.back()->getPosition().y < 0) {
            SceneManager::getInstance().setCurrentScene("Main Menu");
        }
    }

    void Credits::render(sf::RenderTarget& target)
    {
        target.draw(m_backgroundColor);
        for (auto& line : m_credits) {
            target.draw(*line);
        }
        target.draw(m_background);

        for (auto& [key, element] : m_uiElements) {
            element->render(target);
        }

        if (!m_transition.isDone()) {
            m_transition.render(target);
        }
    }

    void Credits::restart()
    {
        m_transition.restart();
        m_music->play();
        int i = 0;
        for (auto& line : m_credits) {
            line->setPosition({info::getWindowSize().x * 0.5, info::getWindowSize().y * 0.9 + i * line->getCharacterSize() * 1.5});
            i++;
        }
        m_credits.at(3)->setString("Total best score: " + std::to_string(getTotalBest()));
        m_credits.at(3)->setOrigin(m_credits.at(3)->getGlobalBounds().width / 2, m_credits.at(3)->getGlobalBounds().height / 2);
    }
    void Credits::stop()
    {
        m_music->stop();
    }
}