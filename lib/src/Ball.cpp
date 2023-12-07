#include "../include/Ball.h"

Ball::Ball(float startX, float startY, float radius, sf::Color color) {
    m_shape.setRadius(radius);
    m_shape.setFillColor(color);
    m_shape.setPosition(startX, startY);
    m_velocity = sf::Vector2f(0.f, 0.f);
}

void Ball::update(float deltaTime) {
    // Update the ball's position based on its velocity
    sf::Vector2f position = m_shape.getPosition();
    position += m_velocity * deltaTime;
    m_shape.setPosition(position);
}

void Ball::draw(sf::RenderWindow& window) {
    // Draw the ball on the window
    window.draw(m_shape);
}