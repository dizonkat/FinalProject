#pragma once

// when using the vcpkg C and C++ library manager library, any projects using the
// vcpkg cmake toolchain (such as this one) will have access to any packages installed with
// vcpkg immediately (as is the case here with SFML)
#include <SFML/Graphics.hpp>

class Ball {
public:
    Ball(float startX, float startY, float radius, sf::Color color);
    void update(float deltaTime);
    void draw(sf::RenderWindow& window);

private:
    sf::CircleShape m_shape;
    float velocityX;
    float velocityY;
    sf::Vector2f position;
    float radius;
};