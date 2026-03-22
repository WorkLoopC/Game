#include "Entities.h"
#include "Player.h"
#include "Enemies.h"
#include "Projectile.h"
#include "Animation.h"
#include <vector>
#include <math.h>
#include <iostream>

int main()
{
    Player player;
    Enemies enemies;
    sf::View view;
    sf::Time time;
    sf::Event event;
    sf::Clock clock;
    sf::Texture texture;
    sf::Sprite sprite;
    sf::RenderWindow window(sf::VideoMode(800, 600), "Demo");
    window.setFramerateLimit(60);
    float dt = clock.restart().asSeconds();
    if (!texture.loadFromFile("resources/arena.jpg")) std::cout << "FAILED TO LOAD\n";
    sprite.setTexture(texture);
    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        player.update(dt, window);
        player.player_position_update(window, view);
    
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && clock.getElapsedTime().asSeconds() > 0.5) { //&& clock.getElapsedTime().asSeconds() > 0.5
            clock.restart();
            player.shoot_mouse(dt, window);
            enemies.spawn_enemy(player.m_rect.getPosition());
        }
        window.clear();
        window.draw(sprite);
        player.draw(window);
        //enemies.draw(window);
        
        int i{};
        for (auto& p : player.m_new_projectile) {
            p.update(player.m_angle[i]);
            p.draw(window);
            i++;
        }
        int j{};
        for (auto& p : enemies.m_enemy_arr) {        
            p.draw(window);
            p.enemy_move(player.m_rect.getPosition(), dt);
            j++;
        }
        window.display();
    }
    return 0;
}
