#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

class Segment
{
 public:
     short int currentDirection;
     short int oldDirection;
     sf::Vector2f currentPos;
     sf::Vector2f oldPos;
     sf::RectangleShape piece;
     virtual void update(float snakeSpeed)=0;
     virtual void draw(sf::RenderWindow &win)=0;
     virtual void changeDirection()=0;
     virtual void checkPos()=0;
     //virtual ~Segment(){};
};


class TailSegment :public Segment
{
    Segment *nextElement = nullptr;
public:
    TailSegment(Segment *lastElem);
    void update(float snakeSpeed);
    void draw(sf::RenderWindow &win);
    void changeDirection();
    void checkPos();
    ~TailSegment();
};

class HeadSegment :public Segment
{
    public:
    HeadSegment();
    void update(float snakeSpeed);
    void draw(sf::RenderWindow &win);
    void changeDirection();
    void checkPos();
    ~HeadSegment();
};
