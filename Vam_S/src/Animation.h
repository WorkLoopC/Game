#pragma once
#include <SFML/Graphics.hpp>

class Animation{
    private:
        float m_totalTime;
        float m_switchTime;
        sf::Vector2u m_currentPic;
        sf::Vector2u m_imageCount;
    public:
        Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime);
        sf::IntRect Rect;
        void update(int row, float dt);

};