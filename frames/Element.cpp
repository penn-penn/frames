#include "Element.h"


Element::Element(sf::Vector2f v2fSize, Element *ptrParent, int iId) {
	
	id = iId;
	size = v2fSize;
	parent = ptrParent;

	if (parent != nullptr) {
		worldPos = sf::Vector2f(0, 0);
		realSize.x = (parent->realSize.x / 100) * size.x;
		realSize.y = (parent->realSize.y / 100) * size.y;
		rowHeights.push_back(0);
	}
	else {
		rowHeights.push_back(0);
		worldPos = sf::Vector2f(0.0f, 0.0f);
		realSize = sf::Vector2f(Settings::windowWidth, Settings::windowHeight);
	}
	
	//set shape
	area.setSize(realSize);
	r = rand() % 255 + 0;
	g = rand() % 255 + 0;
	b = rand() % 255 + 0;
	area.setFillColor(sf::Color::Transparent);
	area.setOutlineThickness(-5);
	area.setOutlineColor(sf::Color(r, g, b));
	//parent->addChild(shared_from_this()); can't call this from constructor
	if (!window.create(300, 300)) {
		std::cout << "wrong" << std::endl;
	}
}

void Element::addChild(std::shared_ptr<Element> el) {
	float calcWidth = worldPos.x + realSize.x;
	if (!grid.empty()) {
		//add element to a new row
		float rowWidth = (grid.back().back()->getPos().x + grid.back().back()->realSize.x + el->realSize.x);
		if (rowWidth > calcWidth) {
			el->worldPos.x = worldPos.x;
			if (el->parent != nullptr) {
				el->worldPos.y = getPos().y + maxHeight;
			}
			else {
				el->worldPos.y = 0;// nullptr is base element
			}
			el->area.setPosition(el->worldPos);
			grid.push_back(std::vector<std::shared_ptr<Element >>{el});
			rowHeights.push_back(el->realSize.y);
			maxHeight += el->realSize.y;
			std::cout << "box " << el->id << " posY: " << el->worldPos.y << std::endl;
		}
		//add element to the back of the current row
		else {
			el->worldPos.x = grid.back().back()->getPos().x + grid.back().back()->realSize.x;
			if (el->parent != nullptr) {
				el->worldPos.y = getPos().y + rowHeights.end()[-2]; // startpos of this element + second last height
			}
			else {
				el->worldPos.y = 0; // nullptr is base element
			}
			el->area.setPosition(el->worldPos);
			grid.back().push_back(el);
			if (!rowHeights.empty()) {
				if (el->realSize.y > rowHeights.back()) {
					maxHeight += el->realSize.y - rowHeights.back();
					rowHeights.back() = el->realSize.y;
				}
			}
			else {
				rowHeights.push_back(el->realSize.y);
			}
		}
	}
	else {
		el->worldPos.x = worldPos.x;
		el->worldPos.y = worldPos.y;
		el->area.setPosition(el->worldPos);
		grid.push_back(std::vector<std::shared_ptr<Element >>{el});
		maxHeight += el->realSize.y;
		rowHeights.push_back(el->realSize.y);
	}
	
	children.push_back(el);
}

void Element::draw(sf::RenderWindow& rWindow) {
	sf::Vector2f windowMouse;
	windowMouse.x = sf::Mouse::getPosition(rWindow).x;
	windowMouse.y = sf::Mouse::getPosition(rWindow).y;
	bool childrenHovered = false;
	for (int i = 0; i < children.size(); i++) {
		if (children[i]->hover(windowMouse)) {
			childrenHovered = true;
			break;
		}
	}
	for (int i = 0; i < children.size(); i++) {
		children[i]->draw(rWindow);
	}
	if (!childrenHovered && hover(windowMouse)) {
		area.setFillColor(sf::Color(r, g, b));
	}
	else {
		area.setFillColor(sf::Color::Transparent);
	}
	rWindow.draw(area);
}

bool Element::hover(sf::Vector2f mousePos) {
	std::cout << mousePos.y << std::endl;
	if (mousePos.x > worldPos.x && mousePos.x < worldPos.x + realSize.x) {
		if (mousePos.y > worldPos.y && mousePos.y < worldPos.y + realSize.y) {
			return true;
		}
	}
	return false;
}

sf::Vector2f Element::getPos() {
	return worldPos;
}

//for debugging purposes
void Element::parentCheck() {
	if (parent == nullptr) {
		std::cout << "parent = null" << std::endl;
	}
	else {
		std::cout << "parent = exists" << std::endl;
	}
}

Element::~Element(){
}