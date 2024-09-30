#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{   
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Game",sf::Style::Default, settings);
    
    sf::Clock clock;

    sf::Vector2f ballVel(1, 1);

    sf::CircleShape ball(10);
    ball.setPosition(sf::Vector2f(1920 / 2, 1080 / 2));
        
    sf::RectangleShape rect(sf::Vector2f(100, 100));

   // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        } 

        window.clear();

        //ALl the Draw calls here
        window.draw(ball);
        ball.move(ballVel);
        if (ball.getPosition().y <= 0 || ball.getPosition().y >= 1080) {
            ballVel.y = -ballVel.y;
        }
        if (ball.getPosition().x <= 0 || ball.getPosition().x >= 1920) {
            ballVel.x = -ballVel.x;
        }
        window.display();
    }
    std::cout << clock.restart().asSeconds();
    return 0;
}
    