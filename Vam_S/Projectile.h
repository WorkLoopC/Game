#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
class Projectile {
private:
    float m_speed{};

public:
    Projectile(sf::Vector2f position, std::vector<float> direction);
    float getSpeed() const { return m_speed; };
    void draw(sf::RenderWindow& window);
    void update(float angle);

    sf::RectangleShape m_rect;
};