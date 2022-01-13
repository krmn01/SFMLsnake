#include "fruit.h"

class Game
{
     sf::RenderWindow *window;
     sf::Font font;
     std::vector <Segment*> snake;
     Fruit *newFruit=nullptr;
     int points;
     bool inMenu;


 public:
    Game();
    ~Game();
    void drawSnake();
    void updateSnake();
    void showScore();
    void restart();
    void menu(int &currentOption);
    bool gameOver();
    void gameOverScreen();
    void start();

};
