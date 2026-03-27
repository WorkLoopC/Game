#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <iostream>
class Projectile {
private:
    float m_speed{};

public: //sf::Texture m_playerCharacter;
    Projectile(sf::Vector2f position);
    sf::RectangleShape m_rect;
    float getSpeed() const { return m_speed; };
    void draw(sf::RenderWindow& window);
    void update(sf::Vector2f angle, float dt);
    sf::Vector2f angle{};
    bool isOutsideBorders(sf::Vector2f player_position);
};