#pragma once 
#include "Entities.h"
#include "Projectile.h"
#include <SFML/Graphics.hpp>
#include "Animation.h"
class Player : public Entities {
private:
    sf::Texture m_playerCharacter;
    float m_speed{};
    Animation m_animation;
public:
    Player();  
    float getSpeed() const { return m_speed; };
    void update(float dt, sf::RenderWindow& window);
    void shoot_mouse(float dt, sf::RenderWindow& window);
    void draw(sf::RenderWindow& window);
    void player_position_update(sf::RenderWindow& window, sf::View view);
    sf::RectangleShape m_rect;
    std::vector<Projectile> m_new_projectile;
    std::vector<float> m_angle;
    
};