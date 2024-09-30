#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{   
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Game",sf::Style::Fullscreen, settings);
    
    sf::Clock clock;
    sf::Font font;
    if (!font.loadFromFile("font.ttf")) {
        std::cout << "Could not load fonts!" << std::endl;

    }
    sf::Text score;
    score.setFont(font);
    score.setCharacterSize(10);
    score.setFillColor(sf::Color::White);

    sf::Vector2f ballVel(1, 1);
    sf::CircleShape ball(10);
    ball.setPosition(sf::Vector2f(1920 / 2, 1080 / 2));

    sf::RectangleShape paddle1(sf::Vector2f(500, 30));
    paddle1.setPosition(sf::Vector2f(1920 / 2, 100));
    
    sf::RectangleShape paddle2(sf::Vector2f(500, 30));
    paddle2.setPosition(sf::Vector2f(1920 / 2, 1080 - 100));
        
    sf::RectangleShape rect(sf::Vector2f(100, 100));

   // run the program as long as the window is open
    while (window.isOpen())
    {   
        
        score.setString(std::to_string(clock.getElapsedTime().asSeconds()));
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
        window.draw(score);
        window.draw(paddle1);
        window.draw(paddle2);
        ball.move(ballVel);
        if (ball.getPosition().y <= 0 || ball.getPosition().y >= 1080) {
            ballVel.y = -ballVel.y;
        }
        
        if (ball.getPosition().x <= 0 || ball.getPosition().x >= 1920) {
            ballVel.x = -ballVel.x;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            paddle1.move(sf::Vector2f(-2, 0));
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            paddle1.move(sf::Vector2f(2, 0));
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            paddle2.move(sf::Vector2f(-2, 0));
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            paddle2.move(sf::Vector2f(2, 0));
        }

        if (ball.getGlobalBounds().intersects(paddle1.getGlobalBounds()) ||
            ball.getGlobalBounds().intersects(paddle2.getGlobalBounds())) {
            ballVel.y = -ballVel.y;
        }
        window.display();
    }
    std::cout << clock.restart().asSeconds();
    return 0;
}
    