#include "fruit.h"

class Game
{
     sf::RenderWindow *window;
     sf::Font font;
     std::vector <Segment*> snake;
     Fruit *newFruit=nullptr;
     int points;


 public:
    Game();
    ~Game();
    void drawSnake();
    void updateSnake();
    bool gameOver();
    void gameOverScreen();
    void start();

};
