#include "Entities.h"
#include "Player.h"
#include "Enemies.h"
#include <SFML/Graphics.hpp>
#include <vector>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Demo");
    Player player;
    while(window.isOpen()){
        window.clear();

        window.display();
    }
    window.close();
    return 0;
}