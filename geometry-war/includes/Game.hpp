#pragma once
#include <SFML/Graphics.hpp>
#include "EntityManager.hpp"
#include <iostream>

class Game {
 private:
  sf::RenderWindow m_window;
  sf::Font m_font;
  sf::Text m_text;

  EntityManager m_entities;
  Entity* m_player;

  int m_score = 0;
  int m_currentFrame = 0;
  int m_lastEnemySpawnTime = 0;
  bool m_paused = false;
  bool m_running = true; 

  void init(const std::string& config);
  void update();
  void spawnPlayer();
  void spawnEnemy();
  void spawnSmallEnemies(Entity* entity);
  void spawnBullet(Entity* entity, const Vec2& mousePos);
  void spawnWeapon(Entity* entity);
// Systems
  void sMovement();
  void sUserInput();
  void sRender();
  void sEnemySpawner();
  void sCollision();

 public:
  Game(const std::string& config);
  void run();
  ~Game();

};

