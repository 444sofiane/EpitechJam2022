/*
** EPITECH PROJECT, 2023
** Jam
** File description:
** MenuScene
*/

#include "MenuScene.hpp"
#include "UIText.hpp"
#include "Button.hpp"
#include "Slider.hpp"
#include "ResourceManager.hpp"
#include "SceneManager.hpp"

namespace jam {

MenuScene::MenuScene()
{
    m_uiElements.insert(std::make_pair("test text", std::shared_ptr<ui::Widget>(new ui::UIText())));

    ui::UIText* test_text = ((ui::UIText*)m_uiElements.at("test text").get());
    test_text->setString("Main Menu");
    test_text->setFont(getResource().getFont("debugFont"));
    test_text->setPosition({960, 540});
    test_text->setOrigin(test_text->getGlobalBounds().width / 2, test_text->getGlobalBounds().height / 2);
}

MenuScene::~MenuScene()
{
}

void MenuScene::handleEvent(sf::Event& event, sf::RenderWindow& window)
{
    for (auto& [key, element] : m_uiElements) {
        element->handleEvent(event, window);
    }
}

void MenuScene::update(float dt)
{
}

void MenuScene::render(sf::RenderTarget& target)
{
    for (auto& [key, element] : m_uiElements) {
        element->render(target);
    }
}

}
