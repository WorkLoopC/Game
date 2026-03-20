#include "Projectile.h"
#include "Player.h"
#include <math.h>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
Player player;

Projectile::Projectile(sf::Vector2f position, std::vector<float> direction) {
    m_rect.setFillColor(sf::Color::Yellow);
    m_rect.setSize(sf::Vector2f(15.f, 5.f));
    m_rect.setPosition(position);
    m_speed = 20;
}

void Projectile::update(float angle) {
    m_rect.move(m_speed * cos(angle), m_speed * sin(angle));
}

void Projectile::draw(sf::RenderWindow& window) {
    window.draw(m_rect);
}