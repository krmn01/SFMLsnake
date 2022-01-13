#include "fruit.h"
#include <random>

int random(int min, int max)
{
   static bool first = true;
   if (first)
   {
      srand( time(NULL) );
      first = false;
   }
   return min + rand() % (( max + 1 ) - min);
}

GoodFruit::GoodFruit()
{
    fruitRect.setSize(sf::Vector2f(20,20));
    fruitRect.setFillColor(sf::Color(225,0,0,255));
    fruitRect.setOrigin(sf::Vector2f(10,10));
    fruitPos = sf::Vector2f(random(10,790),random(10,590));
    fruitRect.setPosition(fruitPos);
}



bool GoodFruit::checkCollision(int &points,sf::Vector2f headPos)
{
float distance = sqrt(pow((headPos.x - fruitPos.x),2)+pow((headPos.y - fruitPos.y),2));
if(distance < 20)
{
    points+=1;
    return true;
}else return false;
}

void GoodFruit::drawFruit(sf::RenderWindow &w)
{
    w.draw(fruitRect);
}
