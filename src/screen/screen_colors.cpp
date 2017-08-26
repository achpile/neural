/***********************************************************************
     * File       : screen_colors.cpp
     * Created    : Aug 25, 2017
     * Copyright  : (C) 2017 Achpile
     * Author     : Fedosov Alexander
     * Email      : achpile@gmail.com

***********************************************************************/
#include "headers.hpp"



/***********************************************************************
     * ScreenColors
     * constructor

***********************************************************************/
ach::ScreenColors::ScreenColors() {
	network = new ach::Network<ach::Color>;

	network->addLayer(3);
	network->addLayer(4);
	network->addLayer(2);

	population = new ach::Population(100, network->count(), -2.0f, 2.0f);

	input  = network->getInput();
	output = network->getOutput();

	input->neurons[0]->value.set(sf::Color::Red);
	input->neurons[1]->value.set(sf::Color::Green);
	input->neurons[2]->value.set(sf::Color::Blue);

	population->reset();

	circle.setRadius(30);
	timer.setTimer(0.05f);

	goal1.set(sf::Color(200,   0, 200));
	goal2.set(sf::Color(100, 200, 100));

	for (unsigned int i = 0; i < population->creatures.size(); i++)
		process(i);

	iterations = 0;
	copyColors();
}



/***********************************************************************
     * ScreenColors
     * destructor

***********************************************************************/
ach::ScreenColors::~ScreenColors() {
	delete network;
	delete population;
}



/***********************************************************************
     * ScreenColors
     * update

***********************************************************************/
void ach::ScreenColors::update() {
	process(population->crossover());

	if (!timer.process()) {
		timer.reset();
		copyColors();
	}

	render();
}



/***********************************************************************
     * ScreenColors
     * render

***********************************************************************/
void ach::ScreenColors::render() {
	renderNetwork();
	renderText();
}



/***********************************************************************
     * ScreenColors
     * renderNetwork

***********************************************************************/
void ach::ScreenColors::renderNetwork() {
	renderNeuron( 50, 250, colors[0],  1, sf::Color::Black);
	renderNeuron( 50, 350, colors[1],  1, sf::Color::Black);
	renderNeuron( 50, 450, colors[2],  1, sf::Color::Black);

	renderNeuron(200, 200, colors[3],  1, sf::Color::Black);
	renderNeuron(200, 300, colors[4],  1, sf::Color::Black);
	renderNeuron(200, 400, colors[5],  1, sf::Color::Black);
	renderNeuron(200, 500, colors[6],  1, sf::Color::Black);

	renderNeuron(350, 275, colors[7], 20, goal1.get());
	renderNeuron(350, 425, colors[8], 20, goal2.get());
}



/***********************************************************************
     * ScreenColors
     * renderNeuron

***********************************************************************/
void ach::ScreenColors::renderNeuron(int x, int y, sf::Color c, int border, sf::Color bc) {
	circle.setOutlineThickness(border);
	circle.setOutlineColor(bc);
	circle.setPosition(x, y);
	circle.setFillColor(c);
	app->draw(circle);
}



/***********************************************************************
     * ScreenColors
     * renderText

***********************************************************************/
void ach::ScreenColors::renderText() {
	drawText(10, 10, std::string("Population      : ") + std::to_string(population->creatures.size()));
	drawText(10, 30, std::string("Avg. fitness    : ") + std::to_string(population->avg));
	drawText(10, 50, std::string("Iterations      : ") + std::to_string(iterations));
	drawText(10, 70, std::string("Mutations       : ") + std::to_string(population->mutations));
	drawText(10, 90, std::string("Mutation prob, %: ") + std::to_string(population->mutProb * 100.0f));
}



/***********************************************************************
     * ScreenColors
     * fitness

***********************************************************************/
float ach::ScreenColors::fitness(ach::Color c1, ach::Color c2) {
	return 6.0f - ((sqr(c1.r - goal1.r) + sqr(c1.g - goal1.g) + sqr(c1.b - goal1.b)) + 
	               (sqr(c2.r - goal2.r) + sqr(c2.g - goal2.g) + sqr(c2.b - goal2.b)));
}



/***********************************************************************
     * ScreenColors
     * process

***********************************************************************/
void ach::ScreenColors::process(unsigned int index) {
	iterations++;

	network->calculate(&population->creatures[index]->dna);
	population->creatures[index]->fitness = fitness(output->neurons[0]->value,
	                                                output->neurons[1]->value);

	population->mutProb = 1 - (population->avg / 6.0f);
}



/***********************************************************************
     * ScreenColors
     * copyColors

***********************************************************************/
void ach::ScreenColors::copyColors() {
	colors[0] = input->neurons[0]->value.get();
	colors[1] = input->neurons[1]->value.get();
	colors[2] = input->neurons[2]->value.get();

	colors[3] = network->layers[1]->neurons[0]->value.get();
	colors[4] = network->layers[1]->neurons[1]->value.get();
	colors[5] = network->layers[1]->neurons[2]->value.get();
	colors[6] = network->layers[1]->neurons[3]->value.get();

	colors[7] = output->neurons[0]->value.get();
	colors[8] = output->neurons[1]->value.get();
}
