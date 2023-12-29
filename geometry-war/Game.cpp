#include "includes/Game.hpp"

Game::Game(const std::string& config) {
  this->init(config);
}

void Game::init(const std::string& config) {
  m_window.create(sf::VideoMode(1280, 720), "Geometry Wars");
  m_window.setFramerateLimit(60);
}

void Game::run() {
  this->spawnPlayer();

  while(m_running) {
    this->update();
    sEnemySpawner();
    sMovement();
    sCollision();
    sUserInput();
    sRender();

    m_currentFrame++;
  }
}

void Game::update() {
  for(auto entity : m_entities.getEntities()) {
    entity->cTransform->angle += 1.0f;
  }
}

void Game::spawnPlayer() {
  auto entity = m_entities.addEntities("player");
  entity->cTransform = new CTransform(Vec2(200.0f, 200.0f), Vec2(1.0f, 1.0f), Vec2(1.0f, 1.0f), 0.0f);
  entity->cShape = new CShape(32.0f, 3, sf::Color(10, 10, 10), sf::Color(255, 0, 0), 4.0f);
  entity->cInput = new CInput();

  m_player = entity;
}

void Game::spawnEnemy() {
  auto entity = m_entities.addEntities("enemy");

  Vec2 pos = Vec2(rand() % m_window.getSize().x, rand() % m_window.getSize().y);
  Vec2 vel = m_player->cTransform->position;
  vel -= pos;
  vel.normalize().scale(5);

  entity->cTransform = new CTransform(pos, vel, Vec2(1, 1), 0.0f);
  entity->cShape = new CShape(16.0f, 4, sf::Color::Blue, sf::Color::White, 4.0f);

  m_lastEnemySpawnTime = m_currentFrame;
}

void Game::spawnSmallEnemies(Entity* entity) {}

void Game::spawnBullet(Entity* entity, const Vec2& mousePos) {
  auto bullet = m_entities.addEntities("bullet");

  Vec2 bulletPos = mousePos;
  bulletPos -= entity->cTransform->position;

  Vec2 bulletVel = bulletPos.normalize();
  
  bulletPos.scale(60).add(entity->cTransform->position);
  bulletVel.scale(5);

  bullet->cTransform = new CTransform(bulletPos, bulletVel, Vec2(1, 1), 0);
  bullet->cShape = new CShape(5, 8, sf::Color::White, sf::Color::Red, 2);
}

void Game::spawnWeapon(Entity* entity) {}

void Game::sEnemySpawner() {
  if(m_lastEnemySpawnTime == m_currentFrame - 60) {
    this->spawnEnemy();
  }
}

void Game::sMovement() {
  if(m_player->cInput->down) {
    m_player->cTransform->velocity.y = 5; 
  } else if(m_player->cInput->up) {
    m_player->cTransform->velocity.y = -5; 
  } else {
    m_player->cTransform->velocity.y = 0;
  }
  
  if(m_player->cInput->left) {
    m_player->cTransform->velocity.x = -5; 
  } else if(m_player->cInput->right) {
    m_player->cTransform->velocity.x = 5; 
  } else {
    m_player->cTransform->velocity.x = 0;
  }

  for(auto entity : m_entities.getEntities()) {
    entity->cTransform->position.add(entity->cTransform->velocity);
  }
}

void Game::sCollision() {
  for(auto bullet : m_entities.getEntities("bullet")) {
    for(auto enemy : m_entities.getEntities("enemy")) {
      //TO DO
    }
  }
}

void Game::sUserInput() {
  sf::Event event;
  while (m_window.pollEvent(event)) {
    if (event.type == sf::Event::Closed) {
      m_running = false;
    }

    if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
      this->spawnBullet(m_player, Vec2(sf::Mouse::getPosition(m_window).x, sf::Mouse::getPosition(m_window).y));
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
      m_player->cInput->left = true;
    } else {
      m_player->cInput->left = false;
    }
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
      m_player->cInput->right = true;
    } else {
      m_player->cInput->right = false;
    }
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
      m_player->cInput->up = true;
    } else {
      m_player->cInput->up = false;
    }
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
      m_player->cInput->down = true;
    } else {
      m_player->cInput->down = false;
    }
  }
}

void Game::sRender() {
  m_window.clear();
  
  for(auto entity : m_entities.getEntities()) {
    entity->cShape->circle.setPosition(entity->cTransform->position.x, entity->cTransform->position.y);
    entity->cShape->circle.setRotation(entity->cTransform->angle);
    m_window.draw(entity->cShape->circle);
  } 

  m_window.draw(m_player->cShape->circle);
  m_window.display();
}

Game::~Game() {
  m_window.close();
}

