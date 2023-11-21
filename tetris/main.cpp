#include <SFML/Graphics.hpp>
#include <time.h>
#include "Game.hpp"

int main() {

  Game game = Game();

  game.initialize();
  game.start();

  return 0;
}
