#include "Player.h"
#include <SFML/Window/Keyboard.hpp>
#include <math.h>

sf::Clock cl;

Player::Player() {
    circle.setRadius(25.f);
    circle.setOrigin(30.f, 30.f);
    circle.setFillColor(sf::Color::Green);
    circle.setPosition(375.f, 275.f);
    speed = 300;
}

void Player::update(float dt, sf::RenderWindow& window) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        circle.move(0, -getSpeed() * dt);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        circle.move(0, getSpeed() * dt);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        circle.move(-getSpeed() * dt, 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        circle.move(getSpeed() * dt, 0);
    }
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && cl.getElapsedTime().asSeconds() > 0.5) {
        shoot_mouse(dt, window);
    }

    int i{};
    for (auto& p : new_projectile) {
        p.update(angle[i]);
        p.draw(window);
        i++;
    }

}

//draw a move uz jsou v SDFL

void Player::shoot_mouse(float dt, sf::RenderWindow& window) {
    Projectile projectile{ circle.getPosition() , angle };

    sf::Vector2f targetPos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
    sf::Vector2f direction = targetPos - circle.getPosition();
    projectile.rect.setOrigin(projectile.rect.getSize().x / 2.f, projectile.rect.getSize().y / 2.f);
    float angle_rotation = std::atan2(direction.y, direction.x) * 180 / M_PI;
    projectile.rect.setRotation(angle_rotation);
    projectile.rect.setPosition(circle.getPosition());

    angle.push_back(atan2(sf::Mouse::getPosition(window).y - circle.getPosition().y,
        sf::Mouse::getPosition(window).x - circle.getPosition().x));
    new_projectile.push_back(projectile);
    cl.restart();
}

void Player::draw(sf::RenderWindow& window) {
    window.draw(circle);
}

