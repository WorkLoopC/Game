#include "Player.h"
#include "Animation.h"
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics.hpp>
#include <math.h>
#include <iostream>

sf::View view;
//sf::Clock clock;

Player::Player() {
    m_playerCharacter.loadFromFile("resources/player.jpg");
    m_rect.setTexture(&m_playerCharacter);
    m_rect.setSize(sf::Vector2f(150.f, 200.f));
    m_rect.setPosition(400.f, 300.f);
    m_speed = 300;
}

void Player::update(float dt, sf::RenderWindow& window) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        m_rect.move(0, -getSpeed() * dt);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        m_rect.move(0, getSpeed() * dt);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        m_rect.move(-getSpeed() * dt, 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        m_rect.move(getSpeed() * dt, 0);
    }

}

void Player::shoot_mouse(float dt, sf::RenderWindow& window) {

    Projectile projectile{ m_rect.getPosition() , m_angle };

    sf::Vector2f targetPos = window.mapPixelToCoords(sf::Mouse::getPosition(window));

    sf::Vector2f direction = targetPos - m_rect.getPosition();

    projectile.m_rect.setOrigin(projectile.m_rect.getSize().x / 2.f, projectile.m_rect.getSize().y / 2.f);

    float angle_rotation = std::atan2(direction.y, direction.x) * 180 / M_PI;

    projectile.m_rect.setRotation(angle_rotation);
    projectile.m_rect.setPosition(m_rect.getPosition());

    m_angle.push_back(atan2(direction.y, direction.x));
    m_new_projectile.push_back(projectile);
    //clock.restart();
}

void Player::draw(sf::RenderWindow& window) {
    window.draw(m_rect);
}

void Player::player_position_update(sf::RenderWindow& window) {
    view.setCenter(m_rect.getPosition());
    window.setView(view);
}
