/***********************************************************************
     * File       : screen_select.cpp
     * Created    : Dec 06, 2017
     * Copyright  : (C) 2017 Achpile
     * Author     : Fedosov Alexander
     * Email      : achpile@gmail.com

***********************************************************************/
#include "headers.hpp"



/***********************************************************************
     * ScreenSelect
     * constructor

***********************************************************************/
ach::ScreenSelect::ScreenSelect() {
}



/***********************************************************************
     * ScreenSelect
     * destructor

***********************************************************************/
ach::ScreenSelect::~ScreenSelect() {
}



/***********************************************************************
     * ScreenSelect
     * update

***********************************************************************/
void ach::ScreenSelect::update() {
	render();
}



/***********************************************************************
     * ScreenSelect
     * render

***********************************************************************/
void ach::ScreenSelect::render() {
	drawText(250,  50, "Choose the demo");
	drawText( 50, 100, "1. Colors");
	drawText( 50, 150, "2. Flappy Bird");
	drawText( 50, 200, "3. Hexagon");
}



/***********************************************************************
     * ScreenSelect
     * create

***********************************************************************/
void ach::ScreenSelect::create(int index) {
	switch (index) {
		case 1: demo->screen = new ach::ScreenColors ; break;
		case 2: demo->screen = new ach::ScreenBird   ; break;
		case 3: demo->screen = new ach::ScreenHexagon; break;
	}
}



/***********************************************************************
     * ScreenSelect
     * processEvent

***********************************************************************/
void ach::ScreenSelect::processEvent(sf::Event event) {
	if (event.type == sf::Event::KeyPressed) {
		switch (event.key.code) {
			case sf::Keyboard::Num1: create(1); break;
			case sf::Keyboard::Num2: create(2); break;
			case sf::Keyboard::Num3: create(3); break;

			default: break;
		}
	}
}
