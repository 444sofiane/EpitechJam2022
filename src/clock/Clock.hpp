/*
** EPITECH PROJECT, 2023
** Jam
** File description:
** Clock
*/

#ifndef CLOCK_HPP_
    #define CLOCK_HPP_

    #include "common.hpp"

    #define getTime() jam::Clock::getInstance().getElapsedTime()
    #define getClock() jam::Clock::getInstance()

    namespace jam {
        class Clock : public sf::Clock {
            public:
                static Clock& getInstance();
                int getFps() const;
                void setTickRate(unsigned int rate);
                float getTickRate() const;
                float getFrameDt() const;
                void update();
            private:
                float m_tickRate;
                float m_frameDt;
        };
    }

#endif /* !CLOCK_HPP_ */
