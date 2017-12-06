/***********************************************************************
     * File       : screen_hexagon.cpp
     * Created    : Dec 06, 2017
     * Copyright  : (C) 2017 Achpile
     * Author     : Fedosov Alexander
     * Email      : achpile@gmail.com

***********************************************************************/
#include "headers.hpp"



/***********************************************************************
     * ScreenHexagon
     * constructor

***********************************************************************/
ach::ScreenHexagon::ScreenHexagon() {
	network = new ach::Network<float>;

	network->addLayer(6);
	network->addLayer(12);
	network->addLayer(2);

	population = new ach::Population(HEXAGON_COUNT, network->count(), -10.0f, 10.0f);

	input  = network->getInput();
	output = network->getOutput();

	population->reset();

	population->mutProb = 0.05f;
	best                = 0.0f;
	iterations          = 0;

	center = new sf::CircleShape(HEXAGON_RADIUS, 6);
	player = new sf::CircleShape(4);
	shape  = new sf::ConvexShape(4);

	player->setOrigin(4, 4);
	player->setFillColor(sf::Color::Green);

	center->setOrigin  (HEXAGON_RADIUS, HEXAGON_RADIUS);
	center->setPosition(400, 300);
	center->setFillColor(sf::Color::Black);
	center->setOutlineColor(sf::Color::White);
	center->setOutlineThickness(2);
	center->setRotation((PI / 6.0f) * RAD_TO_DEG);

	line[0].color = sf::Color(100, 100, 100);
	line[1].color = sf::Color(100, 100, 100);

	shape->setFillColor(sf::Color::White);

	reset();
}



/***********************************************************************
     * ScreenHexagon
     * destructor

***********************************************************************/
ach::ScreenHexagon::~ScreenHexagon() {
	delete network;
	delete population;
	delete center;
	delete player;
	delete shape;
}



/***********************************************************************
     * ScreenHexagon
     * update

***********************************************************************/
void ach::ScreenHexagon::update() {
	distance += frameClock;

	for (int i = 0; i < 6; i++)
		sectors[i] -= HEXAGON_SPEED * frameClock;

	if (needNext()) next();

	phys();

	for (int i = 0; i < HEXAGON_COUNT; i++)
		if (!players[i].dead)
			process(i);

	render();
}



/***********************************************************************
     * ScreenHexagon
     * render

***********************************************************************/
void ach::ScreenHexagon::render() {
	app->clear(sf::Color::Black);

	renderScene();
	renderText();
}



/***********************************************************************
     * ScreenHexagon
     * renderScene

***********************************************************************/
void ach::ScreenHexagon::renderScene() {
	for (int i = 0; i < 6; i++)
		renderLine(i);

	app->draw(*center);

	for (int i = 0; i < 6; i++)
		renderShape(i, sectors[i]);

	for (int i = 0; i < HEXAGON_COUNT; i++)
		if (!players[i].dead)
			renderPlayer(players[i].angle, i);
}



/***********************************************************************
     * ScreenHexagon
     * renderShape

***********************************************************************/
void ach::ScreenHexagon::renderShape(int i, float dist) {
	shape->setPoint(0, getPos(i    , dist                    ));
	shape->setPoint(1, getPos(i    , dist + HEXAGON_THICKNESS));
	shape->setPoint(2, getPos(i + 1, dist + HEXAGON_THICKNESS));
	shape->setPoint(3, getPos(i + 1, dist                    ));

	app->draw(*shape);
}



/***********************************************************************
     * ScreenHexagon
     * renderLine

***********************************************************************/
void ach::ScreenHexagon::renderLine(int i) {
	line[0].position = getPos(i, HEXAGON_RADIUS);
	line[1].position = getPos(i, 500);

	app->draw(line, 2, sf::Lines);
}



/***********************************************************************
     * ScreenHexagon
     * renderPlayer

***********************************************************************/
void ach::ScreenHexagon::renderPlayer(float angle, int index) {
	sf::Color color;

	color.a = 255;
	color.r = (index & (1     )) ? 255 : 100;
	color.g = (index & (1 << 1)) ? 255 : 100;
	color.b = (index & (1 << 2)) ? 255 : 100;

	player->setPosition(getPos(angle, HEXAGON_OFFSET));
	player->setFillColor(color);
	app->draw(*player);
}



/***********************************************************************
     * ScreenHexagon
     * renderText

***********************************************************************/
void ach::ScreenHexagon::renderText() {
	drawText(410,  10, std::string("Population      : ") + std::to_string(population->creatures.size()), sf::Color::White);
	drawText(410,  30, std::string("Alive           : ") + std::to_string(alive)                       , sf::Color::White);
	drawText(410,  50, std::string("Avg. fitness    : ") + std::to_string(population->avg)             , sf::Color::White);
	drawText(410,  70, std::string("Best fitness    : ") + std::to_string(population->best)            , sf::Color::White);
	drawText(410,  90, std::string("Max fitness     : ") + std::to_string(best)                        , sf::Color::White);
	drawText(410, 110, std::string("Iterations      : ") + std::to_string(iterations)                  , sf::Color::White);
	drawText(410, 130, std::string("Distance        : ") + std::to_string(distance)                    , sf::Color::White);
	drawText(410, 150, std::string("Mutations       : ") + std::to_string(population->mutations)       , sf::Color::White);
	drawText(410, 170, std::string("Mutation prob, %: ") + std::to_string(population->mutProb * 100.0f), sf::Color::White);
}



/***********************************************************************
     * ScreenHexagon
     * reset

***********************************************************************/
void ach::ScreenHexagon::reset() {
	distance = 0.0f;

	for (int i = 0; i < HEXAGON_COUNT; i++) {
		players[i].angle = getRandomFloat(0.0f, 2.0f * PI);
		players[i].dead  = false;
	}

	next();
}



/***********************************************************************
     * ScreenHexagon
     * phys

***********************************************************************/
void ach::ScreenHexagon::phys() {
	alive = 0;

	for (int i = 0; i < HEXAGON_COUNT; i++) {
		if (players[i].dead) continue;

		if (check(players[i].angle)) {
			players[i].dead = true;
			population->creatures[i]->fitness = distance;
		}

		if (!players[i].dead) alive++;
	}

	if (alive < HEXAGON_COUNT / 100) {
		population->crossover2();
		reset();
		iterations++;

		if (best < population->best)
			best = population->best;
	}
}



/***********************************************************************
     * ScreenHexagon
     * check

***********************************************************************/
bool ach::ScreenHexagon::check(float angle) {
	if (angle < 0.0f     ) angle += 2.0f * PI;
	if (angle > 2.0f * PI) angle -= 2.0f * PI;

	int section   = floor(angle / (PI / 3.0f));
	float loBound = sectors[section];
	float hiBound = sectors[section] + HEXAGON_THICKNESS;

	if (HEXAGON_OFFSET > loBound &&
	    HEXAGON_OFFSET < hiBound) return true;

	return false;
}



/***********************************************************************
     * ScreenHexagon
     * next

***********************************************************************/
void ach::ScreenHexagon::next() {
	std::vector<int> list;
	int              k;

	for (int i = 0; i < 6; i++)
		list.push_back(i);

	std::random_shuffle(list.begin(), list.end());

	switch (rand() % 5) {
		case 0: k = 1; break;
		case 1: k = 2; break;
		case 2: k = 3; break;
		case 3: k = 4; break;
		case 4: k = 5; break;
	}

	for (int i = 0; i < 6; i++)
		sectors[list[i]] = HEXAGON_MINRAD + HEXAGON_STEPRAD * (i / k);
}



/***********************************************************************
     * ScreenHexagon
     * needNext

***********************************************************************/
bool ach::ScreenHexagon::needNext() {
	for (int i = 0; i < 6; i++)
		if (sectors[i] > HEXAGON_RADIUS - HEXAGON_THICKNESS)
			return false;

	return true;
}



/***********************************************************************
     * ScreenHexagon
     * process

***********************************************************************/
void ach::ScreenHexagon::process(unsigned int index) {
	float angle = players[index].angle;

	if (angle < 0.0f     ) angle += 2.0f * PI;
	if (angle > 2.0f * PI) angle -= 2.0f * PI;

	int section = floor(angle / (PI / 3.0f));

	for (int i = 0; i < 6; i++)
		input->neurons[i]->value = (sectors[(section + i) % 6] > HEXAGON_OFFSET) ? sectors[(section + i) % 6] - HEXAGON_OFFSET : HEXAGON_MINRAD + HEXAGON_STEPRAD * 5;

	network->calculate(&population->creatures[index]->dna);

	if (output->neurons[0]->value > 0.0f) {
		int dir = 1;
		if (output->neurons[1]->value < 0.0f) dir = -1;

		if (!check(players[index].angle + dir * frameClock * HEXAGON_MOVE))
			players[index].angle += dir * frameClock * HEXAGON_MOVE;
	}

	if (players[index].angle < 0.0f     ) players[index].angle += 2.0f * PI;
	if (players[index].angle > 2.0f * PI) players[index].angle -= 2.0f * PI;
}



/***********************************************************************
     * ScreenHexagon
     * getPos

***********************************************************************/
sf::Vector2f ach::ScreenHexagon::getPos(int i, float radius) {
	float angle = 2.0f * PI * i / 6.0f;
	float rad   = (radius < HEXAGON_RADIUS) ? HEXAGON_RADIUS : radius;

	return getPos(angle, rad);
}



/***********************************************************************
     * ScreenHexagon
     * getPos

***********************************************************************/
sf::Vector2f ach::ScreenHexagon::getPos(float angle, float radius) {
	return sf::Vector2f(cos(angle), sin(angle)) * radius + sf::Vector2f(400, 300);
}



/***********************************************************************
     * ScreenHexagon
     * processEvent

***********************************************************************/
void ach::ScreenHexagon::processEvent(sf::Event event) {
	if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Right) {
		for (int i = 0; i < HEXAGON_COUNT; i++)
			if (!players[i].dead) {
				players[i].dead = true;
				population->creatures[i]->fitness = distance;
			}


		population->crossover2();
		reset();
		iterations++;

		if (best < population->best)
			best = population->best;
	}
}
