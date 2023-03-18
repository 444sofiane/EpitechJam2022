/*
** EPITECH PROJECT, 2023
** Jam
** File description:
** Animation
*/

#include "Animation.hpp"
#include "Clock.hpp"

namespace jam {

Animation::Animation(unsigned frameWidth, unsigned frameHeight)
: FRAME_WIDTH(frameWidth), FRAME_HEIGHT(frameHeight)
{
}

void Animation::addFrame(unsigned int index, sf::Time delay)
{
    sf::IntRect bounds;
    bounds.top = 0;
    bounds.height = FRAME_HEIGHT;
    bounds.width = FRAME_WIDTH;
    bounds.left = index * FRAME_WIDTH;

    m_frames.emplace_back(bounds, delay);
}

void Animation::pause()
{
    m_paused = true;
}

bool Animation::ijamaying() const
{
    return m_paused;
}

void Animation::play()
{
    m_paused = false;
}

const sf::IntRect& Animation::getFrame()
{
    if (ijamaying()) {
        m_overlappedTime += getTime();
        while (m_overlappedTime >= m_frames[m_framePointer].delay) {
            m_overlappedTime -= m_frames[m_framePointer].delay;
            m_framePointer++;
        }
    }
    return m_frames[m_framePointer % m_frames.size()].bounds;
}

const sf::IntRect& Animation::getFrame(unsigned int index) const
{
    return m_frames[index].bounds;
}

}
