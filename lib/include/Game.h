#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Text.hpp>
#include "Ball.h"
#include "Paddle.h"

class Game {
public:
    Game();
    void run();
    static const int WINDOW_HEIGHT = 600;
    static const int WINDOW_WIDTH = 800;
    int score;
    sf::Text scoreString;

private:
    void processEvents();
    void update(float deltaTime);
    void render();

    sf::RenderWindow m_window;
    Ball m_ball;
    Paddle m_paddle1;
    Paddle m_paddle2;
};