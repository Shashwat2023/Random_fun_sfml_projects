#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <optional>

int main(){
    float speed = 800.f;
    float distance =0.f;
    bool ismoving =false;


    sf::Window window;

    window.create(
        sf::VideoMode({640,480}),
        "Window moves :)"
    );
    window.setFramerateLimit(60);

    auto desktop = sf::VideoMode::getDesktopMode();
    auto [x, y] = desktop.size;

    auto [w, h] = window.getSize();
    float midx = (x - w) / 2;
    float midy = (y - h) / 2;
    window.setPosition({midx, midy});

    sf::Clock clock;
    window.setVerticalSyncEnabled(true);
    while (window.isOpen())
    {

        float time = clock.restart().asSeconds();

        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }

            // checking if the key is releasd
            if (const auto* key = event->getIf<sf::Event::Event::KeyReleased>())
            {
                // midx = (x - w) / 2;
                // midy = (y - h) / 2;
                // window.setPosition({midx,midy});
                ismoving =false;
                
            }
            
        }

        // real time event
        distance = speed * time;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)){
            midy-=distance;
            ismoving=true;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)){
            midy+=distance;
            ismoving=true;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)){
            midx-=distance;
            ismoving=true;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)){
            midx+=distance;
            ismoving=true;
        }
        window.setPosition({midx, midy});
        
        if (!ismoving)
        {
            midx = (x - w) / 2;
            midy = (y - h) / 2;
            window.setPosition({midx,midy});
            ismoving=false;
        }
        
    }

    return 0;
}
