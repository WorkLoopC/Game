#pragma once 
#include "Entities.h"
#include "Projectile.h"
#include <SFML/Graphics.hpp>

class Player : public Entities {
private:
float m_speed{};

public:
    Player();
    sf::Texture m_playerCharacter;
    float getSpeed() const { return m_speed; };
    sf::RectangleShape m_rect;
    void update(float dt, sf::RenderWindow& window);
    void shoot_mouse(float dt, sf::RenderWindow& window);
    void draw(sf::RenderWindow& window);
    void player_position_update(sf::RenderWindow& window);
    std::vector<Projectile> m_new_projectile;
    std::vector<float> m_angle;
};