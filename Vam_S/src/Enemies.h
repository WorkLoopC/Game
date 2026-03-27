#pragma once
#include "Entities.h"
#include "Animation.h"
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics.hpp>
class Enemies : public Entities {
private:
    float m_speed{};
    Animation animation;
public:
    Enemies(sf::Texture& enemy_texture);
    sf::RectangleShape m_rect;
    float getSpeed() const { return m_speed; };
    void update(sf::Vector2f player_position, float dt);
    void draw(sf::RenderWindow& window);
    void spawn_enemy(std::vector<Enemies>& enemy_arr, Enemies& enemy);
};