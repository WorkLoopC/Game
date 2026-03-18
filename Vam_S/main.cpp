#include "Entities.h"
#include "Player.h"
#include "Enemies.h"
#include "Projectile.h"
#include <vector>
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

    sprite.setTexture(texture);
    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        float dt = clock.restart().asSeconds();
        player.update(dt, window);
        player.player_position_update(window);
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            player.shoot_mouse(dt, window);
        }
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