#include "Player.h"
#include <SFML/Window/Keyboard.hpp>
#include <math.h>
#include <iostream>

sf::View view;
sf::Clock cl;

Player::Player() {
    m_circle.setRadius(25.f);
    m_circle.setOrigin(m_circle.getRadius(), m_circle.getRadius());
    m_circle.setFillColor(sf::Color::Green);
    m_circle.setPosition(375.f, 275.f);
    m_speed = 300;
}

void Player::update(float dt, sf::RenderWindow& window) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        m_circle.move(0, -getSpeed() * dt);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        m_circle.move(0, getSpeed() * dt);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        m_circle.move(-getSpeed() * dt, 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        m_circle.move(getSpeed() * dt, 0);
    }
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && cl.getElapsedTime().asSeconds() > 0.5) {
        //shoot_mouse(dt, window);
    }
    /*
    int i{};
    for (auto& p : m_new_projectile) {
        p.update(m_angle[i]);
        p.draw(window);
        i++;
    }
    */
}

//draw a move uz jsou v SDFL

void Player::shoot_mouse(float dt, sf::RenderWindow& window) {
    Projectile projectile{ m_circle.getPosition() , m_angle };

    sf::Vector2f targetPos = window.mapPixelToCoords(sf::Mouse::getPosition(window));

    sf::Vector2f direction = targetPos - m_circle.getPosition();

    projectile.m_rect.setOrigin(projectile.m_rect.getSize().x / 2.f, projectile.m_rect.getSize().y / 2.f);

    float angle_rotation = std::atan2(direction.y, direction.x) * 180 / M_PI;

    projectile.m_rect.setRotation(angle_rotation);
    projectile.m_rect.setPosition(m_circle.getPosition());

    m_angle.push_back(atan2(sf::Mouse::getPosition(window).y - m_circle.getPosition().y,
        sf::Mouse::getPosition(window).x - m_circle.getPosition().x));
    m_new_projectile.push_back(projectile);
    std::cout << direction.x << ", " << direction.y << "\n";
    cl.restart();

}

void Player::draw(sf::RenderWindow& window) {
    window.draw(m_circle);
}

void Player::player_position_update(sf::RenderWindow& window) {

    view.setCenter(m_circle.getPosition());
    window.setView(view);
}