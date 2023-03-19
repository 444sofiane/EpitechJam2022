/*
** EPITECH PROJECT, 2023
** Jam
** File description:
** main
*/

#include "Engine.hpp"

int main(int argc, char **argv)
{
    jam::Engine& engine = jam::Engine::getInstance();

    engine.init();
    engine.run();
    return 0;
}
