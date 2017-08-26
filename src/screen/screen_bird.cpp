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
	network = new ach::Network<ach::Color>;

	network->addLayer(3);
	network->addLayer(4);
	network->addLayer(2);

	population = new ach::Population(100, network->count(), 0.0f, 1.0f);

	input  = network->getInput();
	output = network->getOutput();

	input->neurons[0]->value.set(sf::Color::Red);
	input->neurons[1]->value.set(sf::Color::Green);
	input->neurons[2]->value.set(sf::Color::Blue);

	population->reset();

	circle.setRadius(30);
	timer.setTimer(0.1f);

	goal1.set(sf::Color(200,   0, 200));
	goal2.set(sf::Color(100, 200, 100));

	line.append(sf::Vertex());
	line.append(sf::Vertex());
	line.setPrimitiveType(sf::Lines);

	for (unsigned int i = 0; i < population->creatures.size(); i++)
		process(i);

	for (unsigned int i = 0; i < network->count(); i++)
		dna.weights.push_back(0.0f);

	iterations = 0;
	copyColors();
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
	process(population->crossover());

	if (!timer.process()) {
		timer.reset();
		copyColors();
		copyWeights();
	}

	render();
}



/***********************************************************************
     * ScreenBird
     * render

***********************************************************************/
void ach::ScreenBird::render() {
	renderNetwork();
	renderText();
}



/***********************************************************************
     * ScreenBird
     * renderNetwork

***********************************************************************/
void ach::ScreenBird::renderNetwork() {
	renderLine(50, 250, 200, 200, dna.weights[ 0]);
	renderLine(50, 350, 200, 200, dna.weights[ 1]);
	renderLine(50, 450, 200, 200, dna.weights[ 2]);
	renderLine(50, 250, 200, 300, dna.weights[ 3]);
	renderLine(50, 350, 200, 300, dna.weights[ 4]);
	renderLine(50, 450, 200, 300, dna.weights[ 5]);
	renderLine(50, 250, 200, 400, dna.weights[ 6]);
	renderLine(50, 350, 200, 400, dna.weights[ 7]);
	renderLine(50, 450, 200, 400, dna.weights[ 8]);
	renderLine(50, 250, 200, 500, dna.weights[ 9]);
	renderLine(50, 350, 200, 500, dna.weights[10]);
	renderLine(50, 450, 200, 500, dna.weights[11]);

	renderLine(200, 200, 350, 275, dna.weights[12]);
	renderLine(200, 300, 350, 275, dna.weights[13]);
	renderLine(200, 400, 350, 275, dna.weights[14]);
	renderLine(200, 500, 350, 275, dna.weights[15]);
	renderLine(200, 200, 350, 425, dna.weights[16]);
	renderLine(200, 300, 350, 425, dna.weights[17]);
	renderLine(200, 400, 350, 425, dna.weights[18]);
	renderLine(200, 500, 350, 425, dna.weights[19]);


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
     * ScreenBird
     * renderNeuron

***********************************************************************/
void ach::ScreenBird::renderNeuron(int x, int y, sf::Color c, int border, sf::Color bc) {
	circle.setOutlineThickness(border);
	circle.setOutlineColor(bc);
	circle.setPosition(x, y);
	circle.setFillColor(c);
	app->draw(circle);
}



/***********************************************************************
     * ScreenBird
     * renderLine

***********************************************************************/
void ach::ScreenBird::renderLine(int x1, int y1, int x2, int y2, float weight) {
	line[0].color = sf::Color(255 * (1.0f - weight), 255 * (weight), 0);
	line[1].color = sf::Color(255 * (1.0f - weight), 255 * (weight), 0);

	line[0].position = sf::Vector2f(x1 + 31, y1 + 30);
	line[1].position = sf::Vector2f(x2 + 31, y2 + 30);
	app->draw(line);

	line[0].position = sf::Vector2f(x1 + 29, y1 + 30);
	line[1].position = sf::Vector2f(x2 + 29, y2 + 30);
	app->draw(line);

	line[0].position = sf::Vector2f(x1 + 30, y1 + 31);
	line[1].position = sf::Vector2f(x2 + 30, y2 + 31);
	app->draw(line);

	line[0].position = sf::Vector2f(x1 + 30, y1 + 29);
	line[1].position = sf::Vector2f(x2 + 30, y2 + 29);
	app->draw(line);
}



/***********************************************************************
     * ScreenBird
     * renderText

***********************************************************************/
void ach::ScreenBird::renderText() {
	drawText(10, 10, std::string("Population      : ") + std::to_string(population->creatures.size()));
	drawText(10, 30, std::string("Avg. fitness    : ") + std::to_string(population->avg));
	drawText(10, 50, std::string("Iterations      : ") + std::to_string(iterations));
	drawText(10, 70, std::string("Mutations       : ") + std::to_string(population->mutations));
	drawText(10, 90, std::string("Mutation prob, %: ") + std::to_string(population->mutProb * 100.0f));
}



/***********************************************************************
     * ScreenBird
     * fitness

***********************************************************************/
float ach::ScreenBird::fitness(ach::Color c1, ach::Color c2) {
	return 6.0f - ((sqr(c1.r - goal1.r) + sqr(c1.g - goal1.g) + sqr(c1.b - goal1.b)) + 
	               (sqr(c2.r - goal2.r) + sqr(c2.g - goal2.g) + sqr(c2.b - goal2.b)));
}



/***********************************************************************
     * ScreenBird
     * process

***********************************************************************/
void ach::ScreenBird::process(unsigned int index) {
	iterations++;

	network->calculate(&population->creatures[index]->dna);
	population->creatures[index]->fitness = fitness(output->neurons[0]->value,
	                                                output->neurons[1]->value);

	population->mutProb = 1.0f - (population->avg / 6.0f);

	if (population->mutProb > 0.01f)
		population->mutProb = 0.01f;
}



/***********************************************************************
     * ScreenBird
     * copyColors

***********************************************************************/
void ach::ScreenBird::copyColors() {
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



/***********************************************************************
     * ScreenBird
     * copyWeights

***********************************************************************/
void ach::ScreenBird::copyWeights() {
	for (unsigned int i = 0; i < dna.weights.size(); i++)
		dna.weights[i] = population->creatures[population->last]->dna.weights[i];
}
