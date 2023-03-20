/*
** EPITECH PROJECT, 2023
** EpitechJam2022
** File description:
** LevelSelector
*/

#include "LevelSelector.hpp"
#include "ResourceManager.hpp"
#include "Widget.hpp"
#include "Button.hpp"
#include "SceneManager.hpp"
#include "info.hpp"
#include "UIText.hpp"
#include "RoomScene.hpp"

namespace jam {

    LevelSelector::LevelSelector()
    : m_scenesRef(SceneManager::getInstance().getScenes())
    {
        sf::Vector2u wSize = info::getWindowSize();

        m_music = &getResource().getMusic("menu");

        m_uiElements["Title"] = std::make_shared<ui::Text>();

        ui::Text* title = dynamic_cast<ui::Text*>(m_uiElements["Title"].get());
        title->setString("Level Selector");
        title->setFont(getResource().getFont("nathanFont"));
        title->setCharacterSize(100);
        title->setPosition({wSize.x * 0.5, wSize.y * 0.1});
        title->setOrigin(title->getGlobalBounds().width / 2, title->getGlobalBounds().height / 2);

        m_uiElements["Back"] = std::make_shared<ui::Button>(getResource().getTexture("generic_button"), "Back");
        ui::Button* backButton = dynamic_cast<ui::Button*>(m_uiElements["Back"].get());
        backButton->setPosition({wSize.x * 0.5, wSize.y * 0.9});
        backButton->getLabel().setFont((getResource().getFont("nathanFont")));
        backButton->setBaseScale(3.0f, 3.0f);
        backButton->getLabel().setCharacterSize(50);
        backButton->setFunction([] { SceneManager::getInstance().setCurrentScene("Main Menu", false); });

        m_background.setSize(sf::Vector2f(wSize));
        m_background.setTexture(&getResource().getTexture("menu_bg"));

        m_transition = trans::Curtains(getResource().getTexture("curtains"), sf::Vector2f(1, 0), 1.5f);
    }

    LevelSelector::~LevelSelector()
    {

    }

    void LevelSelector::handleEvent(sf::Event &event, sf::RenderWindow &window)
    {
        if (!m_transition.isDone()) {
            return;
        }
        for (auto& [key, element] : m_uiElements) {
            element->handleEvent(event, window);
        }
    }

    void LevelSelector::update(float dt)
    {
        if (!m_transition.isDone()) {
            m_transition.update(dt);
            return;
        }
    }

    void LevelSelector::render(sf::RenderTarget &target)
    {
        target.draw(m_background);
        for (auto& [key, element] : m_uiElements) {
            element->render(target);
        }
        if (!m_transition.isDone()) {
            m_transition.render(target);
        }
    }

    void LevelSelector::stop()
    {
        m_music->stop();
    }

    void LevelSelector::restart()
    {
        sf::Vector2u wSize = info::getWindowSize();

        m_transition.restart();

        int i = 0;
        int skipped = 0;
        for (auto it = m_scenesRef.begin(); it != m_scenesRef.end(); ++it)
        {
            auto& name = it->first;
            auto& scene = it->second;

            if (dynamic_cast<RoomScene*>(scene.get()) == nullptr) {
                skipped++;
                continue;
            }

            m_uiElements[name + "Button"] = std::make_shared<ui::Button>(getResource().getTexture("generic_button"), name);
            ui::Button& button = dynamic_cast<ui::Button&>(*m_uiElements[name + "Button"]);

            sf::Vector2f pos = {wSize.x * 0.3 + (i % 3) * wSize.x * 0.2, wSize.y * 0.3 + (i / 3) * wSize.y * 0.2};
            button.setPosition(pos);
            button.setBaseScale(3.0f, 3.0f);
            button.getLabel().setFont((getResource().getFont("nathanFont")));
            button.getLabel().setString(name);
            button.getLabel().setCharacterSize(40);
            button.setFunction([name, i, skipped] {
                SceneManager::getInstance().setCurrentScene(name);
                SceneManager::getInstance().setCurrentSceneIndex(i + skipped);
                });
            i++;
        }
    }
}