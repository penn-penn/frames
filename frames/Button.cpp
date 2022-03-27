#include "Button.h"
#include "Fonts.h"
Button::Button(std::string sText, sf::Vector2f v2fSize, Element* ptrParent, int iId) : Element(v2fSize, ptrParent, iId) {
    text = sText;
    tText.setFont(Fonts::font.roboto);
    tText.setString(text);
    
    tText.setFillColor(sf::Color::Red);
    tText.setStyle(sf::Text::Regular);
    
}

Button::~Button() {}

/*sf::RenderTexture& Button::draw() {
    sf::Vector2f adjustCenter(sf::Vector2f(5.0f, realSize.y / 4.0f));
    sf::Vector2f pos = worldPos + adjustCenter;
    float widthOfALetter = tText.getLocalBounds().width / text.size();
    if (tText.getLocalBounds().width > realSize.x) {
        float deltaSize = tText.getLocalBounds().width - realSize.x;
        int numLetters = std::floor(deltaSize / widthOfALetter);
        std::string temp = text;
        temp.erase(temp.size() - numLetters);
        tText.setString(temp);
    }
    tText.setCharacterSize(realSize.y/3);
    tText.setPosition(pos);
    window.display();
    return window;
}*/