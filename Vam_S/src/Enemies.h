#pragma once
#include "Entities.h"
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics.hpp>
class Enemies : public Entities {
    private:

    public:
        Enemies();
        sf::RectangleShape m_enemy;
        std::vector<Enemies> m_enemy_arr;
        void enemy_move(sf::Vector2f player_position, float dt);
        void draw(sf::RenderWindow& window);
        void spawn_enemy(sf::Vector2f player_position);
};