#include "game.h"

Game::Game()
    {
       window = new  sf::RenderWindow(sf::VideoMode(800, 600), "SFML Snake");
       window->setFramerateLimit(30);
    }
