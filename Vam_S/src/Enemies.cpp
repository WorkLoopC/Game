#include "Enemies.h"
#include "Player.h"
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics.hpp>

Enemies::Enemies(){
    m_enemy.setFillColor(sf::Color::Red);
    m_enemy.setSize(sf::Vector2f(100.f,100.f));
    m_enemy.setPosition(600.f,600.f);
}

void Enemies::enemy_move(sf::Vector2f player_position, float dt){
    sf::Vector2f player_pos = player_position - m_enemy.getPosition();
    float pos = player_pos.x - player_pos.y;
    m_enemy.move(player_pos * (dt * 1));

}

void Enemies::draw(sf::RenderWindow& window){
    window.draw(m_enemy);
}

void Enemies::spawn_enemy(sf::Vector2f player_position){
    Enemies enemies;
    m_enemy.setPosition(rand() % 2000, rand() % 2000);
    m_enemy_arr.push_back(enemies);
    /*
    sf::Vector2f spawn_position = player_position; 
    spawn_position.x *= 2;
    spawn_position.y *= 2;          
    m_enemy.setPosition(spawn_position);
    */
    
}