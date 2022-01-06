#include "segment.h"

class Fruit
{
    public:
    sf::Vector2f fruitPos;
    sf::RectangleShape fruitRect;
    virtual void drawFruit(sf::RenderWindow &w) = 0;
    virtual bool checkCollision(int &points, sf::Vector2f headPos)=0;
};

class GoodFruit :public Fruit
{
    public:
    GoodFruit();
    bool checkCollision(int &points, sf::Vector2f headPos);
    void drawFruit(sf::RenderWindow &w);
};
/*
class SmallBadFruit :public Fruit
{
    public:
    SmallBadFruit();
    bool checkCollision(int &points, sf::Vector2f headPos);
    ~SmallBadFruit();
};

class BigGoodFruit :public Fruit
{
    public:
    BigGoodFruit();
    bool checkCollision(int &points, sf::Vector2f headPos);
    ~BigGoodFruit();
};

class BigBadFruit :public Fruit
{
    public:
    BigBadFruit();
    bool checkCollision(int &points, sf::Vector2f headPos);
    ~BigBadFruit();
};


*/
