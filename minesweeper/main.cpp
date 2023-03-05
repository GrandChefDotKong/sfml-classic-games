#include <iostream>
#include <SFML/Graphics.hpp>
#include <time.h>

using namespace sf;

const unsigned short int WINDOW_WIDTH(14);
const unsigned short int WINDOW_HEIGHT(14);
const unsigned short int NUMBER_MINES(18);
const unsigned short int SPRITE_SIZE(32);
const unsigned short int MINES(9);
const unsigned short int EMPTY(0);

enum GAME { WIN, LOOSE, CONTINUE };

void generateMinesField(unsigned short int solutionGrid[][WINDOW_HEIGHT]);
GAME handleMouseClick(unsigned short int solutionGrid[][WINDOW_HEIGHT], 
  bool clickGrid[][WINDOW_HEIGHT], int x, int y, unsigned short int &numberOfClick);
void handleGameOver(bool clickGrid[][WINDOW_HEIGHT]);
GAME checkVictory(unsigned short int numberOfClick);

int main() {

  srand(time(0));

  RenderWindow app(VideoMode(WINDOW_WIDTH*SPRITE_SIZE, WINDOW_HEIGHT*SPRITE_SIZE), 
    "Minesweeper!");
  app.setFramerateLimit(60);

  unsigned short int solutionGrid[WINDOW_WIDTH][WINDOW_HEIGHT] = {};
  bool clickGrid[WINDOW_WIDTH][WINDOW_HEIGHT] = {}; 

  unsigned short int gameStatus = CONTINUE;
  unsigned short int numberOfClick(0);

  Texture texture;
  texture.loadFromFile("images/tiles.jpg");
  Sprite sprite(texture);

  generateMinesField(solutionGrid);

  while (app.isOpen() && gameStatus == CONTINUE) {

    Vector2i mousePosition = Mouse::getPosition(app);
    int x = mousePosition.x / SPRITE_SIZE;
    int y = mousePosition.y / SPRITE_SIZE;

    Event e;
    while (app.pollEvent(e)) {

      if (e.type == Event::Closed) {
        app.close();
      }

      if (e.type == Event::MouseButtonPressed) {
        if (e.key.code == Mouse::Left) { 
          gameStatus = handleMouseClick(solutionGrid, clickGrid, x, y, numberOfClick);
        }
      }
    }

    gameStatus = checkVictory(numberOfClick);

    app.clear(Color::White);

    for (short int i(0); i < WINDOW_WIDTH; ++i) {
      for (short int j(0); j < WINDOW_HEIGHT; ++j) {
          
        if(clickGrid[i][j]) {
          sprite.setTextureRect(IntRect(solutionGrid[i][j] * SPRITE_SIZE, 0, SPRITE_SIZE, SPRITE_SIZE));
        } else {
          sprite.setTextureRect(IntRect(10 * SPRITE_SIZE, 0, SPRITE_SIZE, SPRITE_SIZE));
        }
        
        sprite.setPosition(i * SPRITE_SIZE, j * SPRITE_SIZE);
        app.draw(sprite);
      }
    }

    app.display();
  }

  return 0;
}


void generateMinesField(unsigned short int solutionGrid[][WINDOW_HEIGHT]) {
  for(short int mines(0); mines < NUMBER_MINES; ++mines) {
    const unsigned short int numberOfCases(WINDOW_WIDTH*WINDOW_HEIGHT);

    const short int minesPosition = rand() % numberOfCases;

    unsigned short int i = minesPosition / WINDOW_WIDTH;
    unsigned short int j = minesPosition % WINDOW_HEIGHT;

    if(solutionGrid[i][j] == MINES) {
      --mines;
      continue;
    }

    solutionGrid[i][j] = MINES;
        
    if (i <(WINDOW_WIDTH-1)  && solutionGrid[i+1][j] != MINES) solutionGrid[i+1][j] +=1;
    if (j < (WINDOW_HEIGHT-1) && solutionGrid[i][j+1] != MINES) solutionGrid[i][j+1] +=1;
    if (i > 0 && solutionGrid[i-1][j] != MINES) solutionGrid[i-1][j] +=1;;
    if (j > 0 && solutionGrid[i][j-1] != MINES) solutionGrid[i][j-1] +=1;
    if (i < (WINDOW_WIDTH-1) && j < (WINDOW_HEIGHT-1) && solutionGrid[i+1][j+1] != MINES) solutionGrid[i+1][j+1] +=1;
    if (i > 0 && j > 0 && solutionGrid[i-1][j-1] != MINES) solutionGrid[i-1][j-1] +=1;
    if (i > 0 && j < (WINDOW_HEIGHT-1) && solutionGrid[i-1][j+1] != MINES) solutionGrid[i-1][j+1] +=1;
    if (i < (WINDOW_WIDTH-1) && j > 0 && solutionGrid[i+1][j-1] != MINES) solutionGrid[i+1][j-1] +=1;
  } 
}


GAME handleMouseClick(unsigned short int solutionGrid[][WINDOW_HEIGHT], 
  bool clickGrid[][WINDOW_HEIGHT], int x, int y, unsigned short int &numberOfClick) {
  
  clickGrid[x][y] = true;
  ++numberOfClick;

  if(solutionGrid[x][y] == MINES) {
    handleGameOver(clickGrid);
    return LOOSE;
  }

  if(solutionGrid[x][y] != EMPTY) {
    return CONTINUE;
  }

  if(x < (WINDOW_WIDTH-1) && !clickGrid[x+1][y]) {
    handleMouseClick(solutionGrid, clickGrid, x+1, y, numberOfClick);
  }

  if(y < (WINDOW_HEIGHT-1) && !clickGrid[x][y+1]) {
    handleMouseClick(solutionGrid, clickGrid, x, y+1, numberOfClick);
  }

  if(x > 0 && !clickGrid[x-1][y]) {
    handleMouseClick(solutionGrid, clickGrid, x-1, y, numberOfClick);
  }

  if(y > 0 && !clickGrid[x][y-1]) {
    handleMouseClick(solutionGrid, clickGrid, x, y-1, numberOfClick);
  }

  if(x < (WINDOW_WIDTH-1) && y < (WINDOW_HEIGHT-1) && !clickGrid[x+1][y+1]) {
    handleMouseClick(solutionGrid, clickGrid, x+1, y+1, numberOfClick);
  }

  if(x > 0 && y > 0 && !clickGrid[x-1][y-1]) {
    handleMouseClick(solutionGrid, clickGrid, x-1, y-1, numberOfClick);
  }

  if(x > 0 && y < (WINDOW_HEIGHT-1) && !clickGrid[x-1][y+1]) {
    handleMouseClick(solutionGrid, clickGrid, x-1, y+1, numberOfClick);
  }

  if(x < (WINDOW_WIDTH-1) && y > 0 && !clickGrid[x+1][y-1]) {
    handleMouseClick(solutionGrid, clickGrid, x+1, y-1, numberOfClick);
  }

  return CONTINUE;
} 

void handleGameOver(bool clickGrid[][WINDOW_HEIGHT]) {
  for(short int i(0); i < WINDOW_WIDTH; ++i) {
    for(short int j(0); j < WINDOW_HEIGHT; ++j) {
      clickGrid[i][j] = true;
    }
  }

  std::cout << "You Lose !!" << std::endl;
}

GAME checkVictory(unsigned short int numberOfClick) {
  if(numberOfClick == (WINDOW_WIDTH * WINDOW_HEIGHT - NUMBER_MINES)) {
    std::cout << "You Win !!" << std::endl;
    return WIN;
  }

  return CONTINUE;
}