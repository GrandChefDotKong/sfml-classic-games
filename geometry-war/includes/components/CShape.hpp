#pragma once
#include <SFML/Graphics.hpp>

struct CShape {
  sf::CircleShape circle;
  CShape(float radius, std::size_t pointCount, const sf::Color& fillColor, const sf::Color& outlineColor, float thickness) : 
    circle(radius, pointCount) {
      circle.setFillColor(fillColor);
      circle.setOutlineColor(outlineColor);
      circle.setOutlineThickness(thickness);
      circle.setOrigin(radius, radius);
    }
};
