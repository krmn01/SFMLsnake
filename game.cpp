#include "game.h"

Game::Game()
{
       window = new  sf::RenderWindow(sf::VideoMode(800, 600), "SFML Snake");
       window->setFramerateLimit(30);
       snake.push_back(new HeadSegment());
       snake.push_back(new TailSegment(snake.back()));
        snake.push_back(new TailSegment(snake.back()));
         snake.push_back(new TailSegment(snake.back()));
          snake.push_back(new TailSegment(snake.back())); snake.push_back(new TailSegment(snake.back()));
          snake.push_back(new TailSegment(snake.back()));
          snake.push_back(new TailSegment(snake.back()));
          snake.push_back(new TailSegment(snake.back()));
          snake.push_back(new TailSegment(snake.back()));
          snake.push_back(new TailSegment(snake.back()));
          snake.push_back(new TailSegment(snake.back()));
          snake.push_back(new TailSegment(snake.back()));
          snake.push_back(new TailSegment(snake.back()));
          snake.push_back(new TailSegment(snake.back()));
             snake.push_back(new TailSegment(snake.back()));
          snake.push_back(new TailSegment(snake.back()));
          snake.push_back(new TailSegment(snake.back()));
          snake.push_back(new TailSegment(snake.back()));
          snake.push_back(new TailSegment(snake.back()));
               snake.push_back(new TailSegment(snake.back()));
          snake.push_back(new TailSegment(snake.back()));
          snake.push_back(new TailSegment(snake.back()));
          snake.push_back(new TailSegment(snake.back()));
             snake.push_back(new TailSegment(snake.back()));
          snake.push_back(new TailSegment(snake.back()));
          snake.push_back(new TailSegment(snake.back()));
          snake.push_back(new TailSegment(snake.back()));
          snake.push_back(new TailSegment(snake.back()));
                    snake.push_back(new TailSegment(snake.back()));
          snake.push_back(new TailSegment(snake.back()));
          snake.push_back(new TailSegment(snake.back()));
             snake.push_back(new TailSegment(snake.back()));
          snake.push_back(new TailSegment(snake.back()));
          snake.push_back(new TailSegment(snake.back()));
          snake.push_back(new TailSegment(snake.back()));
          snake.push_back(new TailSegment(snake.back()));
               snake.push_back(new TailSegment(snake.back()));
          snake.push_back(new TailSegment(snake.back()));
          snake.push_back(new TailSegment(snake.back()));
          snake.push_back(new TailSegment(snake.back()));
             snake.push_back(new TailSegment(snake.back()));
          snake.push_back(new TailSegment(snake.back()));
          snake.push_back(new TailSegment(snake.back()));
          snake.push_back(new TailSegment(snake.back()));
          snake.push_back(new TailSegment(snake.back()));
          std::cout<<"Segmentow"<<snake.size();
       points = 0;
}

void Game::updateSnake()
{
    float vel = (10+points )*0.5;
    for(Segment*s : snake)s->update(vel);
}

void Game::drawSnake()
{
    for(Segment*s : snake)s->draw(*window);
}

void Game::start()
{
    while (window->isOpen())
    {
    sf::Event event;

    while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window->close();
        }
    snake[0]->changeDirection();
    // window->clear();
    updateSnake();
    drawSnake();
    window->display();
    }
}
