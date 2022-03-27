#include "FontLoader.h"
#include <iostream>
FontLoader::FontLoader() {
	if (!roboto.loadFromFile("fonts/Roboto/Roboto-Regular.ttf")) {
		std::cout << "unable to load font" << std::endl;
	}

}
FontLoader::~FontLoader(){}