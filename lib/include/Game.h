#pragma once

#include <SFML/Graphics.hpp>
#include "Ball.h"
#include "Paddle.h"

class Game {
public:
    Game();
    void run();

private:
    void processEvents();
    void update(float deltaTime);
    void render();

    sf::RenderWindow m_window;
    Ball m_ball;
    Paddle m_paddle1;
    Paddle m_paddle2;
};