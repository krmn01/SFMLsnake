#include "segment.h"
#define segmentSize 10

TailSegment::TailSegment(Segment *lastElem)
{
nextElement = lastElem;
piece.setSize(sf::Vector2f(segmentSize,segmentSize));
piece.setFillColor(sf::Color::White);
piece.setOrigin(sf::Vector2f(segmentSize/2,segmentSize/2));
this->currentDirection = nextElement->oldDirection;
this->oldDirection=currentDirection;
switch(currentDirection)
{
case 0:
    this->currentPos = sf::Vector2f(lastElem->currentPos.x, lastElem->currentPos.y);
    break;
case 1:
    this->currentPos = sf::Vector2f(lastElem->currentPos.x, lastElem->currentPos.y);
    break;
case 2:
    this->currentPos = sf::Vector2f(lastElem->currentPos.x, lastElem->currentPos.y);
    break;
case 3:
    this->currentPos = sf::Vector2f(lastElem->currentPos.x-segmentSize, lastElem->currentPos.y);
    break;
}
//this->currentPos = nextElement->oldPos;
piece.setPosition(currentPos);
}

void TailSegment::update(float snakeSpeed)
{
this->oldDirection = this->currentDirection;
this->currentDirection = nextElement->oldDirection;

switch(currentDirection)
{
case 0:
    this->oldPos = currentPos;
    currentPos = sf::Vector2f(currentPos.x,nextElement->oldPos.y);
    break;
case 1:
    this->oldPos = currentPos;
     currentPos = sf::Vector2f(currentPos.x,nextElement->oldPos.y);
    break;
case 2:
    this->oldPos = currentPos;
     currentPos = sf::Vector2f(nextElement->oldPos.x,currentPos.y);
    break;
case 3:
    this->oldPos = currentPos;
     currentPos = sf::Vector2f(nextElement->oldPos.x,currentPos.y);
    break;
default:
    break;
}

//this->currentPos = nextElement->oldPos;
piece.setPosition(this->currentPos);
checkPos();
}

void TailSegment::draw(sf::RenderWindow &win)
{
win.draw(piece);
}

void TailSegment::checkPos()
{
    if(currentPos.x >= 800)currentPos.x=segmentSize;
    else if(currentPos.x <= 0)currentPos.x=800-segmentSize;
    else if(currentPos.y <= 0)currentPos.y=600-segmentSize;
    else if(currentPos.y >= 600)currentPos.y=segmentSize;
}

void TailSegment::changeDirection()
{
}

TailSegment::~TailSegment()
{
    delete nextElement;
}

HeadSegment::HeadSegment()
{
this->oldPos  = sf::Vector2f(100,100);
this->currentPos = sf::Vector2f(100,100);
piece.setOrigin(sf::Vector2f(segmentSize/2,segmentSize/2));
currentDirection = 1;
this->oldDirection = 1;
piece.setSize(sf::Vector2f(segmentSize,segmentSize));
piece.setFillColor(sf::Color::Red);
}



void HeadSegment::update(float snakeSpeed)
{
switch(currentDirection)
{
case 0:
    this->oldPos = currentPos;
    this->currentPos.y-=snakeSpeed;
    break;
case 1:
    this->oldPos = currentPos;
    this->currentPos.y+=snakeSpeed;
    break;
case 2:
    this->oldPos = currentPos;
    this->currentPos.x-=snakeSpeed;
    break;
case 3:
    this->oldPos = currentPos;
    this->currentPos.x+=snakeSpeed;
    break;
default:
    break;
}
piece.setPosition(currentPos);
checkPos();
}

void HeadSegment::draw(sf::RenderWindow &win)
{
win.draw(piece);
}

void HeadSegment::changeDirection()
{
this->oldDirection = currentDirection;
if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)&&currentDirection!=3)
{
    this->currentDirection=2;
}
else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)&&currentDirection!=2)
{
     this->currentDirection=3;
}
else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)&&currentDirection!=0)
{
    this->currentDirection=1;
}
else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)&&currentDirection!=1)
{
    this->currentDirection=0;
}
}

HeadSegment::~HeadSegment()
{

}

void HeadSegment::checkPos()
{
    if(currentPos.x >= 800)currentPos.x=segmentSize;
    else if(currentPos.x <= 0)currentPos.x=800-segmentSize;
    else if(currentPos.y <= 0)currentPos.y=600-segmentSize;
    else if(currentPos.y >= 600)currentPos.y=segmentSize;
}
