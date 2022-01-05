#include <SFML/Graphics.hpp>
#include <iostream>


class Segment
{
 public:
     sf::Vector2f currentPos;
     virtual void update(sf::Vector2f nextPos)=0;
     virtual void draw(sf::RenderWindow &win)=0;
};


class TailSegment :public Segment
{
    Segment *nextElement = nullptr;
public:
    TailSegment(Segment *lastElem);
    void update(sf::Vector2f nextPos);
    void draw(sf::RenderWindow &win);
};

