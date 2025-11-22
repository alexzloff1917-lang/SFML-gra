#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
using namespace sf;

int main() {
    RenderWindow window(VideoMode(800, 600), "Bez wychodzenia za ekran");

    CircleShape circle(50.f);
    circle.setFillColor(Color::Red);
    circle.setPosition(300.f, 250.f);

    const float speed = 0.5f;

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
        }

        if (Keyboard::isKeyPressed(Keyboard::W))
            circle.move(0, -speed);
        if (Keyboard::isKeyPressed(Keyboard::S))
            circle.move(0, speed);
        if (Keyboard::isKeyPressed(Keyboard::A))
            circle.move(-speed, 0);
        if (Keyboard::isKeyPressed(Keyboard::D))
            circle.move(speed, 0);

        float x = circle.getPosition().x;
        float y = circle.getPosition().y;
        float r = circle.getRadius();

        int width  = window.getSize().x;
        int height = window.getSize().y;

        if (x < 0)
            circle.setPosition(0, y);
        if (y < 0)
            circle.setPosition(x, 0);
        if (x + r*2 > width)
            circle.setPosition(width - r*2, y);
        if (y + r*2 > height)
            circle.setPosition(x, height - r*2);
        window.clear();
        window.draw(circle);
        window.display();
    }
}
