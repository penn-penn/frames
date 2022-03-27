#pragma once
#include "Element.h"
class Window : public Element
{
public:
	//width and height of the window in percentage
	Window(int iWidth, int iHeight);
	~Window();
};

