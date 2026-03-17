#include "Projectile.h"
#include "Player.h"
#include <math.h>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
Player player;
Projectile::Projectile(sf::Vector2f position, std::vector<float> direction) {
    rect.setFillColor(sf::Color::Yellow);
    rect.setSize(sf::Vector2f(15.f, 1.f));
    rect.setPosition(position);
}

void Projectile::update(float angle) {
    rect.move(5 * cos(angle), 5 * sin(angle));//circle.getPosition() * speed, sf::Mouse::getPosition() * speed
}

void Projectile::draw(sf::RenderWindow& window) {
    window.draw(rect);
}