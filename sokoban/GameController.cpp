#include "GameController.hpp"

GameController::GameController() : m_isRunning(false) {

}

void GameController::initialize() {
  this->m_window = 
    new sf::RenderWindow(sf::VideoMode(1024, 720), "SFML works!");
  this->m_window->setFramerateLimit(60);

  sf::Texture crate_sprite = sf::Texture();
  crate_sprite.loadFromFile("assets/crate.png");
  m_texture["crate-sprite"] = crate_sprite;
  
  sf::Sprite crate = sf::Sprite();
  crate.setTexture(m_texture["crate-sprite"]);
  crate.setPosition(100, 100);
  crate.setScale(0.2, 0.2);

  m_gameObjects["crate"] = crate;

  sf::Texture link_sprites = sf::Texture();
  link_sprites.loadFromFile("assets/link_sprites.png");
  m_texture["link-sprites"] = link_sprites;  
  
  Character link = Character();
  link.setTexture(m_texture["link-sprites"]);
  link.setPosition(500, 300);
  link.scale(sf::Vector2f(4, 4));

// idle animation
  Animation idle_down = Animation(m_texture["link-sprites"]);
  idle_down.setIsLoop(true);
  idle_down.setInterval(sf::milliseconds(80));
  idle_down.addFrame(sf::IntRect(0, 79, 18, 25));

  Animation idle_left = Animation(m_texture["link-sprites"]);
  idle_left.setIsLoop(true);
  idle_left.setInterval(sf::milliseconds(80));
  idle_left.addFrame(sf::IntRect(19, 79, 18, 25));

  Animation idle_right = Animation(m_texture["link-sprites"]);
  idle_right.setIsLoop(true);
  idle_right.setInterval(sf::milliseconds(80));
  idle_right.addFrame(sf::IntRect(19+18, 79, -18, 25));
  
  Animation idle_up = Animation(m_texture["link-sprites"]);
  idle_up.setIsLoop(true);
  idle_up.setInterval(sf::milliseconds(80));
  idle_up.addFrame(sf::IntRect(38, 79, 18, 25));

// running animation
  Animation up = Animation(m_texture["link-sprites"]);
  up.setIsLoop(true);
  up.setInterval(sf::milliseconds(80));
  up.addFrames(10, sf::IntRect(0, 52, 18, 25), 19, 0);

  Animation right = Animation(m_texture["link-sprites"]);
  right.setIsLoop(true);
  right.setInterval(sf::milliseconds(80));
  right.addFrames(10, sf::IntRect(0+25, 26, -25, 25), 26, 0);

  Animation down = Animation(m_texture["link-sprites"]);
  down.setIsLoop(true);
  down.setInterval(sf::milliseconds(80));
  down.addFrames(10, sf::IntRect(0, 0, 18, 25), 19, 0);
  
  Animation left = Animation(m_texture["link-sprites"]);
  left.setIsLoop(true);
  left.setInterval(sf::milliseconds(80));
  left.addFrames(10, sf::IntRect(0, 26, 25, 25), 26, 0);

// pushing animation
  Animation pushing_down = Animation(m_texture["link-sprites"]);
  pushing_down.setIsLoop(true);
  pushing_down.setInterval(sf::milliseconds(80));
  pushing_down.addFrames(9, sf::IntRect(0, 105, 22, 24), 23, 0);
 
  this->m_animationTree["idle-down"] = idle_down;
  this->m_animationTree["idle-left"] = idle_left;
  this->m_animationTree["idle-right"] = idle_right;
  this->m_animationTree["idle-up"] = idle_up;
  this->m_animationTree["left"] = left;
  this->m_animationTree["right"] = right;
  this->m_animationTree["down"] = down;
  this->m_animationTree["up"] = up;
  this->m_animationTree["pushing-down"] = pushing_down;

  link.addAnimation("idle-down", this->m_animationTree["idle-down"]);
  link.addAnimation("idle-left", this->m_animationTree["idle-left"]);
  link.addAnimation("idle-right", this->m_animationTree["idle-right"]);
  link.addAnimation("idle-up", this->m_animationTree["idle-up"]);
  link.addAnimation("up", this->m_animationTree["up"]);
  link.addAnimation("left", this->m_animationTree["left"]);
  link.addAnimation("down", this->m_animationTree["down"]);
  link.addAnimation("right", this->m_animationTree["right"]);

  link.addAnimation("pushing-down", this->m_animationTree["pushing-down"]);

  link.setCurrentAnimation("down");

  m_player = link;

  std::cout << "game controller initialization OK !" << std::endl;
}

void GameController::start() {
  this->m_isRunning = true;
  std::cout << "game started OK !" << std::endl;
  this->update();
}

void GameController::update() {

  while (this->m_isRunning) {
    sf::Event event;
    while (m_window->pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        this->stop();
      }  
    }

    this->m_player.update();
/*    
    for(auto& [key, value]: m_gameObjects) {
      value.update();
    }
*/
    this->draw();
  }

}

void GameController::draw() {
    m_window->clear(sf::Color::White);

    for(const auto& [key, value]: m_gameObjects) {
      m_window->draw(value);
    }

    m_window->draw(m_player);

    m_window->display();
  
}

void GameController::stop() {
    m_isRunning = false;
    m_window->close();
    std::cout << "game ended OK !" << std::endl;
}

GameController::~GameController() {
  delete m_window;
  std::cout << "window deleted from memory" << std::endl;
}