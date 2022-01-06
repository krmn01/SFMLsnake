#include "game.h"

Game::Game()
{
       window = new  sf::RenderWindow(sf::VideoMode(800, 600), "SFML Snake");
       window->setFramerateLimit(30);

if (!font.loadFromFile("pricedown.ttf"))
{
window->close();
}

      snake.push_back(new HeadSegment());
      snake.push_back(new TailSegment(snake.back()));
      snake.push_back(new TailSegment(snake.back()));
      snake.push_back(new TailSegment(snake.back()));
      snake.push_back(new TailSegment(snake.back()));
      snake.push_back(new TailSegment(snake.back()));
       points = 0;
       newFruit = new GoodFruit();
}

void Game::updateSnake()
{
    float vel = (5+points )*0.5;
    for(Segment*s : snake)s->update(vel);
    if(newFruit != nullptr){
    if(newFruit->checkCollision(points,snake[0]->currentPos)==true)
    {
        delete newFruit;
        newFruit = new GoodFruit();
        snake.push_back(new TailSegment(snake.back()));
        std::cout<<points<<std::endl;
    }
   }
}

void Game::drawSnake()
{
    for(Segment*s : snake)s->draw(*window);
    newFruit->drawFruit(*window);
}

bool Game::gameOver()
{
    if(snake.size()>5){
    float distance;
    for(unsigned int i = 10; i<snake.size(); i++)
    {
        distance = sqrt(pow((snake[0]->currentPos.x - snake[i]->currentPos.x),2)+pow((snake[0]->currentPos.y - snake[i]->currentPos.y),2));
        if(distance < 5)
        {
            return true;
        }
    }
    }
    return false;
}

void Game::gameOverScreen()
{
    window->clear();
    sf::Text text;
    text.setFont(font);
    text.setString("Game Over!");
    text.setCharacterSize(36);
    text.setFillColor(sf::Color::White);
    text.setPosition(300,250);
    window->draw(text);

}

void Game::start()
{

    do
    {
    if(gameOver()==false){
    sf::Event event;

    while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window->close();
        }
    snake[0]->changeDirection();
    window->clear();
    updateSnake();
    drawSnake();
    window->display();
    }else
    {
        sf::Event event;

        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window->close();
        }
        gameOverScreen();
        window->display();
    }
    }while (window->isOpen());


}

Game::~Game()
{
    for(Segment *s: snake)delete s;
    delete window;
}
