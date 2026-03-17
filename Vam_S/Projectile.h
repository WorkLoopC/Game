#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
class Projectile {
private:
    float speed{ 1000.f };

public:
    Projectile(sf::Vector2f position, std::vector<float> direction);
    sf::RectangleShape rect;
    void draw(sf::RenderWindow& window);
    void update(float angle);

};