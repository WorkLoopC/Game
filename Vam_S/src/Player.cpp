#include "Player.h"
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics.hpp>
#include <math.h>
#include <iostream>

Player::Player() : m_animation (sf::Vector2u(8, 3), 0.3f){
    m_playerCharacter.loadFromFile("resources/player2.png");
    m_animation.setTextureSize(m_playerCharacter.getSize());
    m_rect.setTexture(&m_playerCharacter);
    m_rect.setSize(sf::Vector2f(150.f, 100.f));
    m_rect.setPosition(400.f, 300.f);
    m_speed = 300;
}
 
void Player::update(float dt, sf::RenderWindow& window) {
    m_animation.update(0, dt); 
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {        
        m_rect.move(0, -getSpeed() * dt);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        m_rect.move(0, getSpeed() * dt);       
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        m_rect.move(-getSpeed() * dt, 0);
        m_animation.update(2, dt);       
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        m_rect.move(getSpeed() * dt, 0);
        m_animation.update(1, dt);               
    }
    m_rect.setTextureRect(m_animation.Rect);
}

void Player::shoot_mouse(float dt, sf::RenderWindow& window) {

    Projectile projectile{ m_rect.getPosition() , m_angle };

    sf::Vector2f targetPos = window.mapPixelToCoords(sf::Mouse::getPosition(window));

    sf::Vector2f direction = targetPos - m_rect.getPosition();

    projectile.m_rect.setOrigin(projectile.m_rect.getSize().x / 2.f, projectile.m_rect.getSize().y / 2.f);

    float angle_rotation = std::atan2(direction.y, direction.x) * 180 / M_PI;

    projectile.m_rect.setRotation(angle_rotation);
    projectile.m_rect.setPosition(m_rect.getPosition().x + m_rect.getSize().x - 15.f, m_rect.getPosition().y + m_rect.getSize().y / 2.f); //projectile.m_rect.setPosition(m_rect.getPosition());

    m_angle.push_back(atan2(direction.y, direction.x));
    m_new_projectile.push_back(projectile);
}

void Player::draw(sf::RenderWindow& window) {
    window.draw(m_rect);
}

void Player::player_position_update(sf::RenderWindow& window, sf::View view) {
    view.setCenter(m_rect.getPosition());
    window.setView(view);
}
