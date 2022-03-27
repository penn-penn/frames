#include "Element.h"
#include "Fonts.h"
int main()
{
    srand(time(NULL));
    sf::RenderWindow window(sf::VideoMode(Settings::windowWidth, Settings::windowHeight), "SFML works!");
    std::shared_ptr<Element> e1 = std::make_shared<Element>(sf::Vector2f(100, 100), nullptr, 1);
    std::shared_ptr<Element> e2 = std::make_shared<Element>(sf::Vector2f(50, 50), e1.get(), 2);
    std::shared_ptr<Element> e3 = std::make_shared<Element>(sf::Vector2f(10, 10), e1.get(), 3);
    std::shared_ptr<Element> e4 = std::make_shared<Element>(sf::Vector2f(41, 40), e1.get(), 4);
    std::shared_ptr<Element> e5 = std::make_shared<Element>(sf::Vector2f(41, 40), e4.get(), 5);
    std::shared_ptr<Element> e6 = std::make_shared<Element>(sf::Vector2f(41, 40), e4.get(), 6);
    std::shared_ptr<Element> e7 = std::make_shared<Element>(sf::Vector2f(41, 40), e4.get(), 7);
    //std::shared_ptr<Element> e8 = std::make_shared<Button>("testaaaaaaaaaaaaaaaaaaaaaaaaa", sf::Vector2f(41, 13), e1.get(), 8);
    std::shared_ptr<Element> e9 = std::make_shared<Element>(sf::Vector2f(41, 40), e4.get(), 9);
    std::shared_ptr<Element> e10 = std::make_shared<Element>(sf::Vector2f(41, 40), e4.get(), 10);
    e1->parentCheck();
    e2->parentCheck();
    e3->parentCheck();
    e4->parentCheck();
    e5->parentCheck();
    e6->parentCheck();
    e7->parentCheck();
    e1->addChild(e2);
    e1->addChild(e3);
    e1->addChild(e4);
    e4->addChild(e5);
    e4->addChild(e6);
    e4->addChild(e7);
    //e1->addChild(e8);
    e4->addChild(e9);
    e4->addChild(e10);

    while (window.isOpen())
    {
        sf::Event event;
        sf::Vector2f mouseCoords;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            else if (event.type == sf::Event::MouseMoved)
            {
               mouseCoords.x = event.mouseMove.x;
               mouseCoords.y = event.mouseMove.y;
            }
                
        }

        
        window.clear(sf::Color::Transparent);
        e1->draw(window, mouseCoords);
        window.display();
    }

    return 0;
}