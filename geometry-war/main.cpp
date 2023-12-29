#include <SFML/Graphics.hpp>
#include "includes/Game.hpp"

int main() {

  Game game = Game("config");
  game.run();

  return 0;
}