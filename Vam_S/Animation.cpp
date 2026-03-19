#include "Animation.h"
#include <SFML/Graphics.hpp>

Animation::Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime){
    m_imageCount = imageCount;
    m_switchTime = switchTime;
    m_totalTime = 0.f;
    m_currentPic.x = 0;
    Rect.width = texture->getSize().x / float(imageCount.x);
    Rect.height = texture->getSize().y / float(imageCount.y);
}  

void Animation::update(int row, float dt){
    m_currentPic.y = row;
    m_totalTime+=dt;
    if(m_totalTime >= m_switchTime){
        m_totalTime-=m_switchTime;
        m_currentPic.x++;
        if(m_currentPic.x >= m_imageCount.x){
            m_currentPic.x = 0;
        }
    }
    Rect.left = m_currentPic.x * Rect.width;
    Rect.top  = m_currentPic.y * Rect.height;

}