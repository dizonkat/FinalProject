#include "../include/Paddle.h"

Paddle::Paddle(float startX, float startY, float width, float height, sf::Color color) {
    m_shape.setSize(sf::Vector2f(width, height));
    m_shape.setFillColor(color);
    m_shape.setPosition(startX, startY);
    m_velocity = sf::Vector2f(0.f, 0.f);
}

void Paddle::update(float deltaTime) {
    // Update the paddle's position based on its velocity
    sf::Vector2f position = m_shape.getPosition();
    position += m_velocity * deltaTime;
    m_shape.setPosition(position);
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