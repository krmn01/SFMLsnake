#include "segment.h"

class Game
{
     sf::RenderWindow *window;
     sf::Font font;
     std::vector <Segment*> snake;
     int points;


 public:
    Game();
    void drawSnake();
    void updateSnake();
    bool gameOver();
    void gameOverScreen();
    void start();

};
