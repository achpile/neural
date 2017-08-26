/***********************************************************************
     * File       : screen_bird.cpp
     * Created    : Aug 25, 2017
     * Copyright  : (C) 2017 Achpile
     * Author     : Fedosov Alexander
     * Email      : achpile@gmail.com

***********************************************************************/
#include "headers.hpp"



/***********************************************************************
     * ScreenBird
     * constructor

***********************************************************************/
ach::ScreenBird::ScreenBird() {
	network = new ach::Network<float>;

	network->addLayer(2);
	network->addLayer(6);
	network->addLayer(1);

	population = new ach::Population(FLAPPY_COUNT, network->count(), -1.0f, 1.0f);

	input  = network->getInput();
	output = network->getOutput();

	population->reset();

	population->mutProb = 0.005f;
	best                = 0.0f;
	iterations          = 0;
	maxScore            = 0;

	bird_up_t.loadFromFile("data/flappy/bird_up.png");
	bird_down_t.loadFromFile("data/flappy/bird_down.png");
	floor_t.loadFromFile("data/flappy/floor.png");
	bg_t.loadFromFile("data/flappy/bg.png");
	tube_top_t.loadFromFile("data/flappy/tube_top.png");
	tube_bot_t.loadFromFile("data/flappy/tube_bot.png");

	floor_t.setRepeated(true);
	bg_t.setRepeated(true);

	bird_up.setTexture(bird_up_t);
	bird_down.setTexture(bird_down_t);
	floor.setTexture(&floor_t);
	bg.setTexture(&bg_t);
	tube_top.setTexture(tube_top_t);
	tube_bot.setTexture(tube_bot_t);

	bird_up.setOrigin(sf::Vector2f(bird_up_t.getSize()) * 0.5f);
	bird_down.setOrigin(sf::Vector2f(bird_down_t.getSize()) * 0.5f);

	tube_top.setOrigin(sf::Vector2f(0, tube_top_t.getSize().y));

	floor.setPosition(0, 520);
	bg.setPosition(0, 0);

	floor.setSize(sf::Vector2f(800, 80));
	bg.setSize(sf::Vector2f(800, 520));

	floor_rect = sf::IntRect(0, 0, 800,  80);
	bg_rect    = sf::IntRect(0, 0, 800, 520);

	reset();
}



/***********************************************************************
     * ScreenBird
     * destructor

***********************************************************************/
ach::ScreenBird::~ScreenBird() {
	delete network;
	delete population;
}



/***********************************************************************
     * ScreenBird
     * update

***********************************************************************/
void ach::ScreenBird::update() {
	distance += FLAPPY_SPEED * frameClock;
	offset   -= FLAPPY_SPEED * frameClock;
	dst      -= FLAPPY_SPEED * frameClock;

	if (offset < -64.0f) {
		next();
		actual--;
	}

	if (dst    <   0.0f) {
		dst += FLAPPY_DIFF;
		actual++;
		score++;
	}

	phys();

	for (int i = 0; i < FLAPPY_COUNT; i++)
		if (!birds[i].dead)
			process(i);

	render();
}



/***********************************************************************
     * ScreenBird
     * render

***********************************************************************/
void ach::ScreenBird::render() {
	renderScene();
	renderText();
}



/***********************************************************************
     * ScreenBird
     * renderScene

***********************************************************************/
void ach::ScreenBird::renderScene() {
	bg_rect.left    = distance / 2.0f;
	floor_rect.left = distance;

	bg.setTextureRect(bg_rect);
	floor.setTextureRect(floor_rect);

	app->draw(bg);
	renderBirds();
	renderTubes();
	app->draw(floor);
}



/***********************************************************************
     * ScreenBird
     * renderTubes

***********************************************************************/
void ach::ScreenBird::renderTubes() {
	for (int i = 0; i < 4; i++)
		renderTube(offset + FLAPPY_DIFF * i, tubes[i]);
}



/***********************************************************************
     * ScreenBird
     * renderTube

***********************************************************************/
void ach::ScreenBird::renderTube(float x, float y) {
	tube_top.setPosition(x, y - FLAPPY_HIGH);
	app->draw(tube_top);

	tube_bot.setPosition(x, y + FLAPPY_HIGH);
	app->draw(tube_bot);
}



/***********************************************************************
     * ScreenBird
     * renderBirds

***********************************************************************/
void ach::ScreenBird::renderBirds() {
	for (int i = 0; i < FLAPPY_COUNT; i++)
		if (!birds[i].dead)
			renderBird(birds[i].y, birds[i].speed);
}



/***********************************************************************
     * ScreenBird
     * renderBird

***********************************************************************/
void ach::ScreenBird::renderBird(float y, float speed) {
	if (speed > 0.0f) {
		bird_up.setPosition(100, y);
		app->draw(bird_up);
	} else {
		bird_down.setPosition(100, y);
		app->draw(bird_down);
	}
}



/***********************************************************************
     * ScreenBird
     * renderText

***********************************************************************/
void ach::ScreenBird::renderText() {
	drawText(410,  10, std::string("Population      : ") + std::to_string(population->creatures.size()));
	drawText(410,  30, std::string("Alive           : ") + std::to_string(alive));
	drawText(410,  50, std::string("Avg. fitness    : ") + std::to_string(population->avg));
	drawText(410,  70, std::string("Best fitness    : ") + std::to_string(population->best));
	drawText(410,  90, std::string("Max fitness     : ") + std::to_string(best));
	drawText(410, 110, std::string("Iterations      : ") + std::to_string(iterations));
	drawText(410, 130, std::string("Distance        : ") + std::to_string(distance));
	drawText(410, 150, std::string("Score           : ") + std::to_string(score));
	drawText(410, 170, std::string("Max Score       : ") + std::to_string(maxScore));
	drawText(410, 190, std::string("Distance left   : ") + std::to_string(dst));
	drawText(410, 210, std::string("Mutations       : ") + std::to_string(population->mutations));
	drawText(410, 230, std::string("Mutation prob, %: ") + std::to_string(population->mutProb * 100.0f));
}



/***********************************************************************
     * ScreenBird
     * reset

***********************************************************************/
void ach::ScreenBird::reset() {
	offset   = 300.0f;
	distance = 0.0f;
	actual   = 0;
	score    = 0;
	dst      = 281.0f;

	for (int i = 0; i < 4; i++)
		tubes[i] = getRandomFloat(FLAPPY_LIMIT_T, FLAPPY_LIMIT_B);

	for (int i = 0; i < FLAPPY_COUNT; i++) {
		birds[i].y     = 260.0f;
		birds[i].dead  = false;
		birds[i].speed = 0.0f;
	}
}



/***********************************************************************
     * ScreenBird
     * phys

***********************************************************************/
void ach::ScreenBird::phys() {
	alive = 0;

	for (int i = 0; i < FLAPPY_COUNT; i++) {
		if (birds[i].dead) continue;

		birds[i].speed +=        1200.0f * frameClock;
		birds[i].y     += birds[i].speed * frameClock;

		if (check(birds[i].y)) {
			birds[i].dead = true;
			population->creatures[i]->fitness = distance;
		}

		if (!birds[i].dead) alive++;
	}

	if (!alive) {
		if (maxScore < score)
			maxScore = score;

		population->crossover2();
		reset();
		iterations++;

		if (best < population->best)
			best = population->best;
	}
}



/***********************************************************************
     * ScreenBird
     * check

***********************************************************************/
bool ach::ScreenBird::check(float y) {
	sf::FloatRect bird;
	sf::FloatRect tube;

	if (y > 528.0f) return true;
	if (y <  12.0f) return true;

	bird = sf::FloatRect(87, y - 12, 34, 24);

	tube = sf::FloatRect(offset, tubes[0] + FLAPPY_HIGH, 64, 500);
	if (tube.intersects(bird)) return true;

	tube = sf::FloatRect(offset, 0, 64, tubes[0] - FLAPPY_HIGH);
	if (tube.intersects(bird)) return true;

	tube = sf::FloatRect(offset + FLAPPY_DIFF, tubes[1] + FLAPPY_HIGH, 64, 500);
	if (tube.intersects(bird)) return true;

	tube = sf::FloatRect(offset + FLAPPY_DIFF, 0, 64, tubes[1] - FLAPPY_HIGH);
	if (tube.intersects(bird)) return true;


	return false;
}



/***********************************************************************
     * ScreenBird
     * next

***********************************************************************/
void ach::ScreenBird::next() {
	for (int i = 0; i < 3; i++)
		tubes[i] = tubes[i+1];

	tubes[3]  = getRandomFloat(FLAPPY_LIMIT_T, FLAPPY_LIMIT_B);
	offset   += FLAPPY_DIFF;
}



/***********************************************************************
     * ScreenBird
     * process

***********************************************************************/
void ach::ScreenBird::process(unsigned int index) {
	input->neurons[0]->value = birds[index].y - tubes[actual];
	input->neurons[1]->value = dst;

	network->calculate(&population->creatures[index]->dna);

	if (output->neurons[0]->value > 0.0f)
		birds[index].speed = -300.0f;
}



/***********************************************************************
     * ScreenBird
     * processEvent

***********************************************************************/
void ach::ScreenBird::processEvent(sf::Event event) {
	if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Right) {
		for (int i = 0; i < FLAPPY_COUNT; i++)
			if (!birds[i].dead) {
				birds[i].dead = true;
				population->creatures[i]->fitness = distance;
			}


		if (maxScore < score)
			maxScore = score;

		population->crossover2();
		reset();
		iterations++;

		if (best < population->best)
			best = population->best;
	}
}
