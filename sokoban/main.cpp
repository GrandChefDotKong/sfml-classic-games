#include <SFML/Graphics.hpp>
#include "GameController.hpp"

int main() {

  GameController gameController;

  gameController.initialize();

  gameController.start();

  return EXIT_SUCCESS;
}
