/*
** EPITECH PROJECT, 2023
** Jam
** File description:
** Controller
*/

#ifndef CONTROLLER_HPP_
#define CONTROLLER_HPP_

#include "common.hpp"
#include "IEntity.hpp"
#include <functional>

namespace jam {
    class Controller {
        class CKey {
            public:
                CKey(const sf::Keyboard::Key &key, std::function<void()> callback);
                ~CKey();
                void call();
                void setKey(const sf::Keyboard::Key &key);
                void setCallback(std::function<void()> callback);
                void setEnabled(bool enabled);
                bool isEnabled() const;
                sf::Keyboard::Key getKey() const;
            private:
                sf::Keyboard::Key m_key;
                std::function<void()> m_callback;
                bool m_enabled;
        };

        public:
            Controller(IEntity &entity);
            ~Controller();
            void enableKey(const std::string& identifier, bool enabled);
            void createBasicKeys();
            void overrideKey(const std::string& identifier);
            void control(float dt);
            void lock();
            void unlock();
            bool isLocked() const;
            void setKey(const std::string& identifier, sf::Keyboard::Key key);
            void registerKey(const std::string& identifier, const sf::Keyboard::Key &key, std::function<void()> callback);

        private:
            bool m_locked = false;
            std::map<std::string, CKey> m_keys;
            IEntity& m_entity;
    };
}

#endif /* !CONTROLLER_HPP_ */
