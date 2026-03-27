#pragma once 
#include "Entities.h"
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "Projectile.h"
class Player : public Entities {
private:
    sf::Texture m_playerCharacter;
    float m_speed{};
    Animation animation;
public:
    Player();
    sf::RectangleShape m_rect;
    float getSpeed() const { return m_speed; };
    void update(float dt, sf::RenderWindow& window);
    void shoot(float dt, sf::RenderWindow& window, sf::Vector2f enemy_position,
        std::vector<Projectile>& projectile_arr, Projectile& projectile);
    void draw(sf::RenderWindow& window);
    void player_position_update(sf::RenderWindow& window, sf::View view);

};