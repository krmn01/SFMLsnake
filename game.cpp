#include "game.h"
#include <string>

Game::Game()
{
       window = new  sf::RenderWindow(sf::VideoMode(800, 600), "SFML Snake");
       window->setFramerateLimit(60);
       inMenu = true;

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

void Game::showScore()
{
    sf::Text text;
    text.setFont(font);
    text.setString(std::to_string(points));
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::White);
    text.setPosition(50,20);
    window->draw(text);

}

void Game::menu(int &currentOption)
{
    window->clear();
    auto color1 = sf::Color{ 255,255,255,255};
    auto color2 = sf::Color{ 142,142,142,255 };

        sf::Text text;
        text.setFont(font);
        text.setString("SFML Snake");
        text.setCharacterSize(36);
        text.setFillColor(sf::Color::White);
        text.setPosition(305,50);

        sf::Text text2;
        text2.setFont(font);
        text2.setString("Start Game");
        text2.setCharacterSize(24);
        text2.setPosition(325,250);

        sf::Text text3;
        text3.setFont(font);
        text3.setString("Exit");
        text3.setCharacterSize(24);
        text3.setPosition(370,280);

    switch(currentOption){

    case 0:
        text2.setFillColor(color1);
        text3.setFillColor(color2);
        break;

    case 1:
        text2.setFillColor(color2);
        text3.setFillColor(color1);
        break;

    }
    window->draw(text);
    window->draw(text2);
    window->draw(text3);

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
            if(currentOption==0)currentOption+=1;
            else currentOption = 0;
    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
            if(currentOption==1)currentOption-=1;
            else currentOption = 1;
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && currentOption == 0)
    {
        inMenu = false;
    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && currentOption == 1)
    {
        window->close();
    }

}


void Game::updateSnake()
{
    float vel = (5+points )*0.3;
    for(Segment*s : snake)s->update(vel);
    if(newFruit != nullptr){
    if(newFruit->checkCollision(points,snake[0]->currentPos)==true)
    {
        delete newFruit;
        newFruit = new GoodFruit();
        snake.push_back(new TailSegment(snake.back()));
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
    if(snake.size()>8){
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
    text.setCharacterSize(20);
    text.setFillColor(sf::Color::White);
    text.setPosition(340,225);

    sf::Text text2;
    text2.setFont(font);
    text2.setString("Score: "+std::to_string(points));
    text2.setCharacterSize(20);
    text2.setFillColor(sf::Color::White);
    text2.setPosition(350,250);

    sf::Text text3;
    text3.setFont(font);
    text3.setString("Click ESC to back to main menu");
    text3.setCharacterSize(20);
    text3.setFillColor(sf::Color::White);
    text3.setPosition(250,380);

    sf::Text text4;
    text4.setFont(font);
    text4.setString("Click ENTER to try again");
    text4.setCharacterSize(20);
    text4.setFillColor(sf::Color::White);
    text4.setPosition(280,350);

    window->draw(text);
    window->draw(text2);
    window->draw(text3);
    window->draw(text4);
}

void Game::restart()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)){
    for(Segment *s: snake)delete s;
    snake.clear();
    snake.push_back(new HeadSegment());
    snake.push_back(new TailSegment(snake.back()));
    snake.push_back(new TailSegment(snake.back()));
    snake.push_back(new TailSegment(snake.back()));
    snake.push_back(new TailSegment(snake.back()));
    snake.push_back(new TailSegment(snake.back()));
    points = 0;
    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
        inMenu = true;
        for(Segment *s: snake)delete s;
    snake.clear();
    snake.push_back(new HeadSegment());
    snake.push_back(new TailSegment(snake.back()));
    snake.push_back(new TailSegment(snake.back()));
    snake.push_back(new TailSegment(snake.back()));
    snake.push_back(new TailSegment(snake.back()));
    snake.push_back(new TailSegment(snake.back()));
    points = 0;
    }
}

void Game::start()
{
     int currOpt = 0;
    do
    {
    if(gameOver()==false && inMenu == true)
    {
        sf::Event event;


    while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window->close();
        }
        menu(currOpt);
        window->display();
    }
    else if(gameOver()==false && inMenu == false){
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
    showScore();
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
        restart();
    }
    }while (window->isOpen());


}

Game::~Game()
{
    for(Segment *s: snake)delete s;
    snake.clear();
    delete window;
}
