#pragma once
#include "Element.h"
class Button : public Element
{
public:
	Button(std::string sText, sf::Vector2f v2fSize, Element* ptrParent, int iId);
	~Button();
	//sf::RenderTexture& draw() override;
	std::string text;
	sf::Text tText;
};

