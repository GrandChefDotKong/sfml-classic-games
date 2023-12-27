#pragma once
#include <SFML/Graphics.hpp>
#include "EntityManager.hpp"

class Game {
 private:
  sf::RenderWindow m_window;
  EntityManager m_entities;
  Entity m_player;
  bool m_paused;
  bool m_running;

 public:
  Game(/* args */);
  void init();
  void update();
  ~Game();
// Systems
  void sMovement();
  void sUserInput();
  void sRender();
  void sEnemySpawner();
  void sCollision();
};

