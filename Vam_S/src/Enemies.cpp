#include "Enemies.h"
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics.hpp>

Enemies::Enemies(sf::Texture& enemy_texture) : animation(sf::Vector2u(10, 1), 0.3f) {
    animation.setTextureSize(enemy_texture.getSize());
    m_rect.setTexture(&enemy_texture);
    m_rect.setSize(sf::Vector2f(100.f, 100.f));
    m_rect.setOrigin(50.f, 50.f);
    m_rect.setPosition(rand() % 2000, rand() % 2000);
    m_speed = 0.1f;
}

void Enemies::update(sf::Vector2f player_position, float dt) {
    animation.update(0, dt);
    sf::Vector2f player_pos = player_position - m_rect.getPosition();
    m_rect.move(player_pos * dt * getSpeed());
    m_rect.setTextureRect(animation.Rect);

}

void Enemies::draw(sf::RenderWindow& window) {
    window.draw(m_rect);
}

void Enemies::spawn_enemy(std::vector<Enemies>& enemy_arr, Enemies& enemy) {
    m_rect.setPosition(rand() % 2000, rand() % 2000);
    enemy_arr.push_back(enemy);
}
