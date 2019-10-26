#include <SFML/Graphics.hpp>

using namespace std;

int main() {
    // Create Window
  sf::RenderWindow window(sf::VideoMode(640, 480), "SFML Application Sivan");

  // Create shapes
  // Circle
  sf::Vector2f posCircle(100.0f, 100.0f);
  float circleIncX = -0.05f;
  sf::Uint8 circleR = 127;
  sf::Uint8 circleG = 65;
  sf::Uint8 circleB = 215;
  sf::CircleShape shapeCircle;
  shapeCircle.setRadius(40.f);
  shapeCircle.setPosition(posCircle);
  shapeCircle.setFillColor(sf::Color(circleR, circleG, circleB));

  sf::Vector2f posRect(200.0f, 200.0f);
  sf::RectangleShape shapeRect;
  shapeRect.setSize(sf::Vector2f(20.0f, 45.0f));
  shapeRect.setPosition(posRect);
  shapeRect.setFillColor(sf::Color::Yellow);

    int drawNum = 0;
  while (window.isOpen()) {
    drawNum++;
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) window.close();
    }

    window.clear();

    posCircle.x += circleIncX;
    if (posCircle.x < 0.0f)
    {
        circleR += 20;
        circleG += 20;
        circleB += 20;
        circleIncX *= -1;
        shapeCircle.setFillColor(sf::Color(circleR, circleG, circleB));
    }
    else if ((posCircle.x + (2.0f * shapeCircle.getRadius())) > window.getSize().x)
    {
        circleR += 10;
        circleG += 25;
        circleB += 20;
        circleIncX *= -1;
        shapeCircle.setFillColor(sf::Color(circleR, circleG, circleB));
    }

    shapeCircle.setPosition(posCircle);
    window.draw(shapeCircle);
    window.draw(shapeRect);
    window.display();
  }

  return 0;
}
