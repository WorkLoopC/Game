#include "Player.h"
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics.hpp>
#include <math.h>
#include <iostream>

Player::Player() : animation(sf::Vector2u(8, 3), 0.3f) {
    m_playerCharacter.loadFromFile("resources/player2.png");
    animation.setTextureSize(m_playerCharacter.getSize());
    m_rect.setTexture(&m_playerCharacter);
    m_rect.setSize(sf::Vector2f(100.f, 100.f));
    m_rect.setPosition(400.f, 300.f);
    m_rect.setOrigin(50.f, 50.f);
    m_speed = 50;
}

void Player::update(float dt, sf::RenderWindow& window) {
    animation.update(0, dt);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        m_rect.move(0, -getSpeed() * dt);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        m_rect.move(0, getSpeed() * dt);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        m_rect.move(-getSpeed() * dt, 0);
        animation.update(2, dt);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        m_rect.move(getSpeed() * dt, 0);
        animation.update(1, dt);
    }
    m_rect.setTextureRect(animation.Rect);
}

void Player::shoot(float dt, sf::RenderWindow& window, sf::Vector2f enemy_position,
    std::vector<Projectile>& projectile_arr, Projectile& projectile) {

    sf::Vector2f direction = enemy_position - m_rect.getPosition();

    projectile.m_rect.setOrigin(projectile.m_rect.getSize().x / 2.f, projectile.m_rect.getSize().y / 2.f);
    float angle_radians = std::atan2(direction.y, direction.x);
    float m_velocity_x = projectile.getSpeed() * cos(angle_radians);
    float m_velocity_y = projectile.getSpeed() * sin(angle_radians);

    projectile.m_rect.setRotation(angle_radians * 180.f / M_PI);
    projectile.m_rect.setPosition(m_rect.getPosition());

    projectile.angle.x = m_velocity_x;
    projectile.angle.y = m_velocity_y;
    projectile_arr.push_back(projectile);
}

void Player::draw(sf::RenderWindow& window) {
    window.draw(m_rect);
}

void Player::player_position_update(sf::RenderWindow& window, sf::View view) {
    view.setCenter(m_rect.getPosition());
    window.setView(view);
}
