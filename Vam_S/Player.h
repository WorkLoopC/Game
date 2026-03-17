#pragma once 
#include "Entities.h"
#include "Projectile.h"
#include <SFML/Graphics.hpp>
class Player : public Entities {
private:
    sf::CircleShape circle;
    float speed{ 1000 };

public:
    Player();
    float getSpeed() const { return speed; };
    std::vector<Projectile> new_projectile;
    std::vector<float> angle;
    void update(float dt, sf::RenderWindow& window);
    void shoot_mouse(float dt, sf::RenderWindow& window);
    void draw(sf::RenderWindow& window);
};