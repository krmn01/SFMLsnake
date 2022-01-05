#include <SFML/Graphics.hpp>

using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Unnamed car game");
    window.setFramerateLimit(30);
    return 0;
}
