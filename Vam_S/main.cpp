#include "Entities.h"
#include "Player.h"
#include "Enemies.h"
#include "Projectile.h"
#include <vector>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Demo");
    window.setFramerateLimit(60);
    Player player;
    sf::Event event;
    sf::Clock clock;
    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        float dt = clock.restart().asSeconds();
        window.clear();
        player.draw(window);
        player.update(dt, window);
        window.display();


    }
    return 0;
}