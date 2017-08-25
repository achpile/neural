/***********************************************************************
     * File       : misc_base.cpp
     * Created    : Aug 25, 2017
     * Copyright  : (C) 2017 Achpile
     * Author     : Fedosov Alexander
     * Email      : achpile@gmail.com

***********************************************************************/
#include "headers.hpp"



/***********************************************************************
     * createWindow

***********************************************************************/
void createWindow() {
	app->create(sf::VideoMode(800, 600, 32), PROJECT_CAPTION, sf::Style::Close);
	app->setMouseCursorVisible(true);
	app->setFramerateLimit(60);
	app->setVerticalSyncEnabled(true);

	sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
	sf::Vector2i  offset;

	offset.x = (desktop.width  - 800) / 2;
	offset.y = (desktop.height - 600) / 2;

	if (offset.x > 0 && offset.y > 0)
		app->setPosition(offset);
}
