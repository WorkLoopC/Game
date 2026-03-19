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
    sf::Event event;
    sf::Clock clock;
    sf::Texture texture;
    sf::Sprite sprite;


    sf::RenderWindow window(sf::VideoMode(800, 600), "Demo");
    window.setFramerateLimit(60);
    if (!texture.loadFromFile("image.jpg")) std::cout << "FAILED TO LOAD\n";
    //sprite.setTexture(texture);
    Animation animation (&player.m_playerCharacter, sf::Vector2u (3,6), 0.3f);
    sprite.setTextureRect(animation.Rect);
    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        float dt = clock.restart().asSeconds();

        player.update(dt, window);
        player.player_position_update(window);

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) ) {  //&& cl.getElapsedTime().asSeconds() > 0.5
            player.shoot_mouse(dt, window);
        }
        
        
        animation.update(0,dt);

        window.clear();
        window.draw(sprite);
        
        int i{};
        for (auto& p : player.m_new_projectile) {
            p.update(player.m_angle[i]);
            p.draw(window);
            i++;
        }
        player.draw(window);
        window.display();
    }
    return 0;
}