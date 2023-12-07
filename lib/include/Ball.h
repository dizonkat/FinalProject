#pragma once

#include <SFML/Graphics.hpp>

class Ball {
public:
    Ball(float startX, float startY, float radius, sf::Color color);
    void update(float deltaTime);
    void draw(sf::RenderWindow& window);

private:
    sf::CircleShape m_shape;
    sf::Vector2f m_velocity;
};