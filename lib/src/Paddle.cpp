#include "../include/Paddle.h"

Paddle::Paddle(float startX, float startY, float w, float h, sf::Color color) : width(w), height(h) {
    m_shape.setSize(sf::Vector2f(width, height));
    m_shape.setFillColor(color);
    position = sf::Vector2f(startX, startY);
    m_shape.setPosition(startX, startY);
    m_velocity = sf::Vector2f(0.f, 0.f);
}

void Paddle::update(float deltaTime) {
    // Update the paddle's position based on its velocity
    position += m_velocity * deltaTime;
    m_shape.setPosition(position);
    if ((position.y >= 600 - height / 2) || (position.y <= 0 - height / 2)) {
        m_velocity.y = 0;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        if (position.y >= 0 - height/2) {
            Paddle::moveUp();
        }
        else {
            m_velocity.y = 0;
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        if (position.y <= 600 - height / 2) {
            Paddle::moveDown();
        }
        else {
            m_velocity.y = 0;
        }
    }
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