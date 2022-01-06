#include "segment.h"

class Game
{
     sf::RenderWindow *window;
     std::vector <Segment*> snake;
     int points;

 public:
    Game();
    void drawSnake();
    void updateSnake();
    void start();

};
