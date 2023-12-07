#include <cmath>
#include <iostream>
#include "../include/Ball.h"
#include "../include/Game.h"

Ball::Ball(float startX, float startY, float radius, sf::Color color) {
    m_shape.setRadius(radius);
    m_shape.setFillColor(color);
    m_shape.setPosition(startX, startY);

    // Set the desired angle of movement in degrees
    float angleInDegrees = 45.f;

    // Convert the angle to radians
    float angleInRadians = angleInDegrees * (3.14159f / 180.f);

    // Calculate the x and y components of the velocity based on the angle
    float speed = 100.f; // Set the desired speed of the ball
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
//    if (outOfBounds()) {
//        //std::cout << "x: " << position.x << std::endl;
//        //std::cout << "y: " << position.x << std::endl;
//        reverse();
//    }
    //position += m_velocity * deltaTime;
    m_shape.move(velocityX, velocityY);
//    if (outOfBounds()) {
//        //std::cout << "x: " << position.x << std::endl;
//        //std::cout << "y: " << position.x << std::endl;
//        reverse();
//    }
    //m_shape.setPosition(position);
    //std::cout << "x: " <<
}

void Ball::draw(sf::RenderWindow& window) {
    // Draw the ball on the window
    window.draw(m_shape);
}

void Ball::reverse() {
    //m_velocity = m_velocity * -1.0f;
    //std::cout << m_shape.getPosition().x;
}

bool Ball::outOfBounds() {
    sf::Vector2f position = m_shape.getPosition();
    if (position.x < 0 - m_shape.getRadius()) {
        return true;
    }
    if (position.x > m_shape.getRadius() + 800) {
        return true;
    }
    if (position.y < 0 - m_shape.getRadius()) {
        return true;
    }
    if (position.y > m_shape.getRadius() + 600) {
        return true;
    }
    return false;
}