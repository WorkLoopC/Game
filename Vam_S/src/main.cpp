#include "Entities.h"
#include "Player.h"
#include "Enemies.h"
#include "Projectile.h"
#include "Animation.h"
#include <vector>
#include <math.h>
#include <iostream>
#include <limits>
#include <float.h>
int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Demo");
    Player player;
    sf::View view;
    sf::Time time;
    sf::Event event;
    sf::Clock clock;
    sf::Clock spawn_clock;
    //Map
    sf::Texture map_texture;
    sf::Sprite map_sprite;
    map_texture.loadFromFile("resources/arena.jpg");
    map_sprite.setTexture(map_texture);
    //Enemy
    sf::Texture enemy_texture;
    enemy_texture.loadFromFile("resources/blob.jpg");

    std::vector<Projectile> projectile_arr;
    std::vector<Enemies> enemy_arr;

    window.setFramerateLimit(60);
    float dt = clock.restart().asSeconds();

    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        player.update(dt, window);
        player.player_position_update(window, view);

        if (spawn_clock.getElapsedTime().asSeconds() > 0.5) {
            Enemies enemies(enemy_texture);
            enemy_arr.push_back(enemies);
            spawn_clock.restart();
        }



        if (clock.getElapsedTime().asSeconds() > 0.5) {
            Projectile projectile{ player.m_rect.getPosition() };
            Enemies* closest_enemy = nullptr;
            float smallest_sqrt = FLT_MAX;//100000.f;
            for (auto enemy : enemy_arr) {
                float x = enemy.m_rect.getPosition().x - player.m_rect.getPosition().x;
                float y = enemy.m_rect.getPosition().y - player.m_rect.getPosition().y;
                float radius = (x * x) + (y * y);
                if (radius < smallest_sqrt) {
                    smallest_sqrt = radius;
                    closest_enemy = &enemy;
                }
            }
            if (closest_enemy != nullptr) {
                player.shoot(dt, window, closest_enemy->m_rect.getPosition(), projectile_arr, projectile);
            }
            clock.restart();
        }

        for (auto enemy{ enemy_arr.begin() }; enemy < enemy_arr.end(); enemy++) {
            for (auto bullet{ projectile_arr.begin() }; bullet < projectile_arr.end(); bullet++) {
                if (bullet->m_rect.getGlobalBounds().intersects(enemy->m_rect.getGlobalBounds())) {
                    enemy = enemy_arr.erase(enemy);
                    bullet = projectile_arr.erase(bullet);
                    break;
                }
                if (bullet->isOutsideBorders(player.m_rect.getPosition())) bullet = projectile_arr.erase(bullet);
            }
        }
        window.clear();
        window.draw(map_sprite);
        player.draw(window);
        for (auto& enemy : enemy_arr) {
            enemy.update(player.m_rect.getPosition(), dt);
            enemy.draw(window);
        }
        for (auto& bullet : projectile_arr) {
            bullet.update(bullet.angle, dt);
            bullet.draw(window);

        }
        window.display();
    }
    return 0;
}
