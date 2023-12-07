#pragma once

#include <SFML/Graphics.hpp>

class Paddle {
public:
    Paddle(float startX, float startY, float w, float h, sf::Color color);
    void update(float deltaTime);
    void draw(sf::RenderWindow& window);
    void moveUp();
    void moveDown();

private:
    sf::RectangleShape m_shape;
    sf::Vector2f m_velocity;
    sf::Vector2f position;
    float height;
    float width;
};