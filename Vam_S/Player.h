#pragma once 
#include "Entities.h"
#include "Projectile.h"
#include <SFML/Graphics.hpp>
class Player : public Entities {
private:
    sf::CircleShape m_circle;
    float m_speed{};

public:
    Player();
    float getSpeed() const { return m_speed; };
    void update(float dt, sf::RenderWindow& window);
    void shoot_mouse(float dt, sf::RenderWindow& window);
    void draw(sf::RenderWindow& window);
    
    std::vector<Projectile> m_new_projectile;
    std::vector<float> m_angle;
};