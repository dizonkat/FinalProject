#include <cmath>

#include "../include/Ball.h"


Ball::Ball(float startX, float startY, float radius, sf::Color color) {
    m_shape.setRadius(radius);
    m_shape.setFillColor(color);
    m_shape.setPosition(startX, startY);

    // Set the desired angle of movement in degrees
    float angleInDegrees = 45.f;

    // Convert the angle to radians
    float angleInRadians = angleInDegrees * (3.14159f / 180.f);

    // Calculate the x and y components of the velocity based on the angle
    float speed = 1.f; // Set the desired speed of the ball
    velocityX = speed * std::cos(angleInRadians);
    velocityY = speed * std::sin(angleInRadians);
    position = m_shape.getPosition();
    //m_velocity = sf::Vector2f(velocityX, velocityY);
    this->radius = radius;
}

void Ball::update(float deltaTime) {
    // Update the ball's position based on its velocity
    position = m_shape.getPosition();
    if ((position.x > 800 + radius) || (position.x < radius)) {
        velocityX *= -1.0f;
    }
    if ((position.y > 600 + radius) || (position.y < radius)) {
        velocityY *= -1.0f;
    }
    m_shape.move(velocityX, velocityY);
}

void Ball::draw(sf::RenderWindow& window) {
    // Draw the ball on the window
    window.draw(m_shape);
}