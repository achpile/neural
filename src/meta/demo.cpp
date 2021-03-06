/***********************************************************************
     * File       : demo.cpp
     * Created    : Aug 25, 2017
     * Copyright  : (C) 2017 Achpile
     * Author     : Fedosov Alexander
     * Email      : achpile@gmail.com

***********************************************************************/
#include "headers.hpp"



/***********************************************************************
     * Demo
     * constructor

***********************************************************************/
ach::Demo::Demo() {
	srand(time(NULL));

	app       = new sf::RenderWindow();
	clock     = new sf::Clock;
	select    = new ach::ScreenSelect();
	screen    = NULL;
	running   = true;
	lastClock = clock->getElapsedTime().asMilliseconds();

	createWindow();

	font.loadFromFile("data/FSEX300.ttf");
	text.setFont(font);
	text.setCharacterSize(24);
	text.setFillColor(sf::Color::Black);
}



/***********************************************************************
     * Demo
     * destructor

***********************************************************************/
ach::Demo::~Demo() {
	delete clock;
	delete select;
	delete app;

	if (screen) delete screen;
}



/***********************************************************************
     * Demo
     * update

***********************************************************************/
void ach::Demo::update() {
	long currentClock = clock->getElapsedTime().asMilliseconds();
	if (currentClock - lastClock < 10) return;

	frameClock = (currentClock - lastClock) / 1000.0;
	lastClock  = currentClock;

	processEvents();

	app->clear(sf::Color::White);

	if (screen) screen->update();
	else        select->update();

	app->display();
}



/***********************************************************************
     * Demo
     * processEvents

***********************************************************************/
void ach::Demo::processEvents() {
	sf::Event event;
	while (app->pollEvent(event)) processEvent(event);

	if (!app->isOpen()) stop();
}



/***********************************************************************
     * Demo
     * processEvent

***********************************************************************/
void ach::Demo::processEvent(sf::Event event) {
	switch(event.type) {
		case sf::Event::Closed:
			stop();
		break;


		default:
			if (screen) screen->processEvent(event);
			else        select->processEvent(event);
		break;
	}
}



/***********************************************************************
     * Demo
     * stop

***********************************************************************/
void ach::Demo::stop() {
	running = false;
}
