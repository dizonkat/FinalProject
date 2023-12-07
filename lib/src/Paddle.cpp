#include "../include/Paddle.h"
#include <iostream>

Paddle::Paddle(float startX, float startY, float w, float h, sf::Color color) : width(w), height(h) {
    m_shape.setSize(sf::Vector2f(width, height));
    m_shape.setFillColor(color);
    position = sf::Vector2f(startX, startY);
    m_shape.setPosition(startX, startY);
    m_velocity = sf::Vector2f(0.f, 0.f);
}

void Paddle::update(float deltaTime) {
    // Update the paddle's position based on its velocity
    //sf::Vector2f position = m_shape.getPosition();
    position += m_velocity * deltaTime;
    m_shape.setPosition(position);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        // left key is pressed: move our character
        if (position.y >= 0 - height/2) {
            Paddle::moveUp();
        }
        else {
            m_velocity.y = 0;
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        // right key is pressed: move our character
        if (position.y + height / 2 <= 600) {
            Paddle::moveDown();
        }
        else {
            m_velocity.y = 0;
        }
    }
    //std::cout << m_velocity.y
}

void Paddle::draw(sf::RenderWindow& window) {
    // Draw the paddle on the window
    window.draw(m_shape);
}

void Paddle::moveUp() {
    // Move the paddle up
    m_velocity.y = -400.f; // Adjust the speed as needed
}

void Paddle::moveDown() {
    // Move the paddle down
    m_velocity.y = 400.f; // Adjust the speed as needed
}