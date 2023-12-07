#include "../include/Game.h"

Game::Game() : m_window(sf::VideoMode(800, 600), "Pong Game"), m_ball(400.f, 300.f, 10.f, sf::Color::White),
m_paddle1(20.f, 250.f, 10.f, 100.f, sf::Color::White), m_paddle2(770.f, 250.f, 10.f, 100.f, sf::Color::White) {
    m_window.setPosition(sf::Vector2i(10, 50));
}

void Game::run() {
    sf::Clock clock;
    while (m_window.isOpen()) {
        float deltaTime = clock.restart().asSeconds();

        processEvents();
        update(deltaTime);
        render();
    }
}

void Game::processEvents() {
    sf::Event event;
    while (m_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            m_window.close();
        }
    }
}

void Game::update(float deltaTime) {
    // Update game logic here
    m_ball.update(deltaTime);
    m_paddle1.update(deltaTime);
    m_paddle2.update(deltaTime);
}

void Game::render() {
    m_window.clear(sf::Color::Black);

    // Draw game objects here
    m_ball.draw(m_window);
    m_paddle1.draw(m_window);
    m_paddle2.draw(m_window);

    m_window.display();
}