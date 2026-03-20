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
    Animation animation(&player.m_playerCharacter, sf::Vector2u(8, 2), 0.3f);
    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }


        animation.update(0, dt);
        player.m_rect.setTextureRect(animation.Rect);

        player.update(dt, window);
        player.player_position_update(window);

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && clock.getElapsedTime().asSeconds() > 0.5) { //&& clock.getElapsedTime().asSeconds() > 0.5
            clock.restart();
            player.shoot_mouse(dt, window);

        }

        window.clear();
        window.draw(sprite);
        player.draw(window);
        int i{};
        for (auto& p : player.m_new_projectile) {
            p.update(player.m_angle[i]);
            p.draw(window);
            i++;
        }
        window.display();
    }
    return 0;
}
