#pragma once
#include <vector>
#include <iostream>
#include "vector2i.h"
#include <SFML/Graphics.hpp>
#include "Settings.h"

class Element
{
public:
	//width and height of the window in percentage. Same for the position. unique pointer to parent
	Element(sf::Vector2f v2fSize, Element* ptrParent, int iId = 0);
	~Element();
	//relative size and pos
	sf::Vector2f size;
	//world size and pos
	sf::Vector2f worldPos;
	sf::Vector2f realSize;
	//gridsystem
	std::vector<std::vector< std::shared_ptr<Element>>> grid;
	std::vector<float> rowHeights;
	float maxHeight = 0; //total of rowheights
	//functions
	void addChild(std::shared_ptr<Element> El);
	virtual void draw(sf::RenderWindow &rWindow);
	bool hover(sf::Vector2f mousePos);
	sf::Vector2f getPos();

	Element *parent;
	std::vector<std::shared_ptr<Element>> children;

	sf::RectangleShape area;

	void parentCheck();
	int id;

	int r;
	int g;
	int b;

	//drawWindow
	sf::RenderTexture window;
	sf::Sprite sp;
};

