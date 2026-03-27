#include "Projectile.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <iostream>
Projectile::Projectile(sf::Vector2f position) {
    m_rect.setFillColor(sf::Color::Yellow);
    m_rect.setSize(sf::Vector2f(15.f, 5.f));
    m_rect.setPosition(position);
    m_speed = 100;
}

void Projectile::update(sf::Vector2f angle, float dt) {
    m_rect.move(angle * dt);

}

void Projectile::draw(sf::RenderWindow& window) {
    window.draw(m_rect);
}

bool Projectile::isOutsideBorders(sf::Vector2f player_position) {
    float x_pos = player_position.x + 600.f;
    float y_pos = player_position.y + 500.f;

    float x_neg = player_position.x - 600.f;
    float y_neg = player_position.y - 500.f;

    if (m_rect.getPosition().x > x_pos || m_rect.getPosition().x < x_neg) return true;
    if (m_rect.getPosition().y > y_pos || m_rect.getPosition().y < y_neg) return true;
    return false;
}