#include <SFML/Graphics.hpp>
#include <time.h>

using namespace sf;

const unsigned int WINDOW_WIDTH(14);
const unsigned int WINDOW_HEIGHT(14);
const unsigned int NUMBER_MINES(18);

void generateMinesField(int solutionGrid[][WINDOW_HEIGHT]);
void handleMouseClick(int solutionGrid[][WINDOW_HEIGHT], bool clickGrid[][WINDOW_HEIGHT], int x, int y);

int main() {

  srand(time(0));

  RenderWindow app(VideoMode(WINDOW_WIDTH*32, WINDOW_HEIGHT*32), "Minesweeper!");
  app.setFramerateLimit(60);

  int width = 32;
  int solutionGrid[WINDOW_WIDTH][WINDOW_HEIGHT] = {};
  bool clickGrid[WINDOW_WIDTH][WINDOW_HEIGHT] = {}; 

  Texture texture;
  texture.loadFromFile("images/tiles.jpg");
  Sprite sprite(texture);

  generateMinesField(solutionGrid);

  while (app.isOpen()) {

    Vector2i pos = Mouse::getPosition(app);
    int x = pos.x / width;
    int y = pos.y / width;

    Event e;
    while (app.pollEvent(e)) {

      if (e.type == Event::Closed) {
        app.close();
      }

      if (e.type == Event::MouseButtonPressed) {
        if (e.key.code == Mouse::Left) { 
          handleMouseClick(solutionGrid, clickGrid, x, y);
        }
      }
    }

    app.clear(Color::White);

    for (int i = 0; i < WINDOW_WIDTH; ++i) {
      for (int j = 0; j < WINDOW_HEIGHT; ++j) {
          
        if(clickGrid[i][j]) {
          sprite.setTextureRect(IntRect(solutionGrid[i][j]*width, 0, width, width));
        } else {
          sprite.setTextureRect(IntRect(10 * width, 0, width, width));
        }
        
        sprite.setPosition(i * width, j * width);
        app.draw(sprite);
      }
    }

    app.display();
  }

  return 0;
}

void generateMinesField(int solutionGrid[][WINDOW_HEIGHT]) {
  for(int numero = 0; numero < NUMBER_MINES; ++numero) {
    const unsigned int numberOfCases(WINDOW_WIDTH*WINDOW_HEIGHT);

    const int minesPosition = rand() % numberOfCases;

    int i = minesPosition / WINDOW_WIDTH;
    int j = minesPosition % WINDOW_HEIGHT;

    if(solutionGrid[i][j] == 9) {
      --numero;
      continue;
    }

    solutionGrid[i][j] = 9;
        
    if (i <(WINDOW_WIDTH-1)  && solutionGrid[i+1][j] != 9) solutionGrid[i+1][j] +=1;
    if (j < (WINDOW_HEIGHT-1) && solutionGrid[i][j+1] != 9) solutionGrid[i][j+1] +=1;
    if (i > 0 && solutionGrid[i-1][j] != 9) solutionGrid[i-1][j] +=1;;
    if (j > 0 && solutionGrid[i][j-1] != 9) solutionGrid[i][j-1] +=1;
    if (i < (WINDOW_WIDTH-1) && j < (WINDOW_HEIGHT-1) && solutionGrid[i+1][j+1] != 9) solutionGrid[i+1][j+1] +=1;
    if (i > 0 && j > 0 && solutionGrid[i-1][j-1] != 9) solutionGrid[i-1][j-1] +=1;
    if (i > 0 && j < (WINDOW_HEIGHT-1) && solutionGrid[i-1][j+1] != 9) solutionGrid[i-1][j+1] +=1;
    if (i < (WINDOW_WIDTH-1) && j > 0 && solutionGrid[i+1][j-1] != 9) solutionGrid[i+1][j-1] +=1;
  } 
}


void handleMouseClick(int solutionGrid[][WINDOW_HEIGHT], bool clickGrid[][WINDOW_HEIGHT], int x, int y) {
  
  clickGrid[x][y] = true;

  if(solutionGrid[x][y] == 0) {
    if(x < (WINDOW_WIDTH-1)) {
      if(solutionGrid[x+1][y] == 0 && !clickGrid[x+1][y]) {
        handleMouseClick(solutionGrid, clickGrid, x+1, y);
      } else {
        clickGrid[x+1][y] = true;
      }
    }

    if(y < (WINDOW_HEIGHT-1)) { 
      if(solutionGrid[x][y+1] == 0 && !clickGrid[x][y+1]) {
        handleMouseClick(solutionGrid, clickGrid, x, y+1);
      } else {
        clickGrid[x][y+1] = true;
      }
    }

    if(x > 0) {
      if(solutionGrid[x-1][y] == 0 && !clickGrid[x-1][y]) {
        handleMouseClick(solutionGrid, clickGrid, x-1, y);
      } else {
        clickGrid[x-1][y] = true;
      }
    }

    if(y > 0) {
      if(solutionGrid[x][y-1] == 0 && !clickGrid[x][y-1]) {
        handleMouseClick(solutionGrid, clickGrid, x, y-1);
      } else {
        clickGrid[x][y-1] = true;
      }
    }

    if(x < (WINDOW_WIDTH-1) && y < (WINDOW_HEIGHT-1)) {
      if(solutionGrid[x+1][y+1] == 0 && !clickGrid[x+1][y+1]) {
        handleMouseClick(solutionGrid, clickGrid, x+1, y+1);
      } else {
        clickGrid[x+1][y+1] = true;
      }
    }

    if(x > 0 && y > 0) {
      if(solutionGrid[x-1][y-1] == 0 && !clickGrid[x-1][y-1]) {
        handleMouseClick(solutionGrid, clickGrid, x-1, y-1);
      } else {
        clickGrid[x-1][y-1] = true;
      }
    }

    if(x > 0 && y < (WINDOW_HEIGHT-1)) { 
      if(solutionGrid[x-1][y+1] == 0 && !clickGrid[x-1][y+1]) {
        handleMouseClick(solutionGrid, clickGrid, x-1, y+1);
      } else {
        clickGrid[x-1][y+1] = true;
      }
    }

    if(x < (WINDOW_WIDTH-1) && y > 0) {
      if(solutionGrid[x+1][y-1] == 0 && !clickGrid[x+1][y-1]) {
        handleMouseClick(solutionGrid, clickGrid, x+1, y-1);
      } else {
        clickGrid[x+1][y-1] = true;
      }
    }
  }
} 

