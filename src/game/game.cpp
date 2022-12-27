#include "game.hpp"

Game::Game(){
    this->create(WIN_MODE, "Forgery");
    m_circle.setRadius(100);
    m_circle.setFillColor(sf::Color::Green);
    m_tickCount = 0;
}

Game::~Game(){
}

void Game::play(){
    while (this->isOpen()){
        this->manageEvents();
        this->rendering();
        m_tickCount++;
    }
}

void Game::manageEvents(){
    sf::Event event;
    while (this->pollEvent(event)){
        if (event.type==sf::Event::Closed){
            this->close();
        }
    }
}

void Game::rendering(){
    this->clear();
    this->draw(m_circle);
    this->display();
}
