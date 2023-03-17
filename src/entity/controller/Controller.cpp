/*
** EPITECH PROJECT, 2023
** Jam
** File description:
** Controller
*/

#include "Controller.hpp"

namespace jam {

    Controller::Controller(IEntity &entity)
    : m_entity(entity)
    {
    }

    Controller::~Controller()
    {

    }

    void Controller::createBasicKeys()
    {
        registerKey("up", sf::Keyboard::Z, [&]() {
            m_entity.move(0, -m_entity.getSpeed());
        });
        registerKey("down", sf::Keyboard::S, [&]() {
            m_entity.move(0, m_entity.getSpeed());
        });
        registerKey("left", sf::Keyboard::Q, [&]() {
            m_entity.move(-m_entity.getSpeed(), 0);
        });
        registerKey("right", sf::Keyboard::D, [&]() {
            m_entity.move(m_entity.getSpeed(), 0);
        });
    }

    void Controller::control(float dt)
    {
        if (isLocked())
            return;
        for (auto &[label, key] : m_keys) {
            if (sf::Keyboard::isKeyPressed(key.getKey()))
                key.call();
        }
    }

    bool Controller::isLocked() const
    {
        return m_locked;
    }

    void Controller::lock()
    {
        m_locked = true;
    }

    void Controller::unlock()
    {
        m_locked = false;
    }

    void Controller::setKey(const std::string& identifier, sf::Keyboard::Key key)
    {
        m_keys.at(identifier).setKey(key);
    }

    void Controller::registerKey(const std::string& identifier, const sf::Keyboard::Key &key, std::function<void()> callback)
    {
        m_keys.insert(std::make_pair(identifier, CKey(key, callback)));
    }

    void Controller::enableKey(const std::string& identifier, bool enabled)
    {
        m_keys.at(identifier).setEnabled(enabled);
    }

    void Controller::overrideKey(const std::string& identifier)
    {
        bool enabled = m_keys.at(identifier).isEnabled();

        if (!enabled)
            m_keys.at(identifier).setEnabled(true);
        m_keys.at(identifier).call();

        if (!enabled)
            m_keys.at(identifier).setEnabled(false);
    }

    Controller::CKey::CKey(const sf::Keyboard::Key &key, std::function<void()> callback)
    : m_key(key), m_callback(callback), m_enabled(true)
    {
    }

    Controller::CKey::~CKey()
    {
    }

    void Controller::CKey::call()
    {
        if (m_enabled)
            m_callback();
    }

    void Controller::CKey::setKey(const sf::Keyboard::Key &key)
    {
        m_key = key;
    }

    void Controller::CKey::setCallback(std::function<void()> callback)
    {
        m_callback = callback;
    }

    void Controller::CKey::setEnabled(bool enabled)
    {
        m_enabled = enabled;
    }

    bool Controller::CKey::isEnabled() const
    {
        return m_enabled;
    }

    sf::Keyboard::Key Controller::CKey::getKey() const
    {
        return m_key;
    }

}