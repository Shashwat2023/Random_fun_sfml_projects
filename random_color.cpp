#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <optional>
#include <random>


// modifying image
void ImageColor(sf::Image *image){

    // creating random number
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0, 255);

    if (image !=nullptr)
    {
        for (unsigned int y = 0; y < 600; y++)
        {
            for (unsigned int x = 0; x < 800; x++)
            {
                 int r = dist(gen);
                int g = dist(gen);
                int b = dist(gen);
                sf::Color color(r,g,b);
                image->setPixel({x,y},color);
            } 
        }
    }
}



int main(){

    // Creating window 
    sf::RenderWindow window;
    window.create(
        sf::VideoMode({800,600}),
        "Random Color"
    );
    // setting its framerate and switching on vsync
    window.setFramerateLimit(60);
    window.setVerticalSyncEnabled(true);

    // creating an image
    sf::Image image(
        {800,600},
        sf::Color::Black
    );
    image.setPixel({100,50},sf::Color::Red);
    sf::Texture texture({800, 600});
    sf::Sprite sprite(texture);

    

    // main loop
    while (window.isOpen())
    {

        
        while (const std::optional event = window.pollEvent() )
        {
            if (event->is<sf::Event::Closed>())
            {
                
                window.close();
            }
        }
        ImageColor(&image);
        texture.update(image);

        window.clear();
        window.draw(sprite);
        window.display();
    }
    


    return 0;
}