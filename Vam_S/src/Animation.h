#pragma once
#include <SFML/Graphics.hpp>
class Animation{
    private:
        float m_totalTime;
        float m_switchTime;
        sf::Vector2u m_currentPic;
        sf::Vector2u m_imageCount;
    public:
        sf::Vector2u getImageCount() const {return m_imageCount;};
        Animation(sf::Vector2u imageCount, float switchTime);

        sf::IntRect Rect;
        void update(int row, float dt);
        void setTextureSize(sf::Vector2u textureSize);
};