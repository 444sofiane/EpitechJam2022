/*
** EPITECH PROJECT, 2023
** Jam
** File description:
** Animation
*/

#ifndef ANIMATION_HPP_
    #define ANIMATION_HPP_

    #include "common.hpp"

    namespace jam {

    class Animation {
    public:
        struct Frame {
            Frame(const sf::IntRect &bnds, sf::Time dly)
                : bounds(bnds), delay(dly)
            {
            }
            sf::IntRect bounds;
            sf::Time delay;
        };
        Animation() = default;
        Animation(unsigned frameWidth, unsigned frameHeight);
        void addFrame(unsigned int index, sf::Time delay);
        const sf::IntRect &getFrame();
        const sf::IntRect &getFrame(unsigned int index) const;

        void pause();
        bool ijamaying() const;
        void play();

    private:
        bool m_paused = false;
        float m_timer;
        sf::Time m_overlappedTime;
        std::vector<Frame> m_frames;
        unsigned m_framePointer = 0;
        const unsigned FRAME_WIDTH;
        const unsigned FRAME_HEIGHT;
};

}
#endif /* !ANIMATION_HPP_ */
