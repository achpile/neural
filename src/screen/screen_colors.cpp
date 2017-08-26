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

	population = new ach::Population(100, network->count(), 0.0f, 2.0f);

	input  = network->getInput();
	output = network->getOutput();

	input->neurons[0]->value.set(sf::Color::Red);
	input->neurons[1]->value.set(sf::Color::Green);
	input->neurons[2]->value.set(sf::Color::Blue);

	population->reset();

	circle.setRadius(30);
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
	render();
}



/***********************************************************************
     * ScreenColors
     * render

***********************************************************************/
void ach::ScreenColors::render() {
	renderNetwork();
}



/***********************************************************************
     * ScreenColors
     * renderNetwork

***********************************************************************/
void ach::ScreenColors::renderNetwork() {
	renderNeuron( 50, 300, input->neurons[0]->value.get());
	renderNeuron( 50, 400, input->neurons[1]->value.get());
	renderNeuron( 50, 500, input->neurons[2]->value.get());

	renderNeuron(200, 250, network->layers[1]->neurons[0]->value.get());
	renderNeuron(200, 350, network->layers[1]->neurons[1]->value.get());
	renderNeuron(200, 450, network->layers[1]->neurons[2]->value.get());
	renderNeuron(200, 550, network->layers[1]->neurons[3]->value.get());

	renderNeuron(350, 325, output->neurons[0]->value.get());
	renderNeuron(350, 475, output->neurons[1]->value.get());
}



/***********************************************************************
     * ScreenColors
     * renderNeuron

***********************************************************************/
void ach::ScreenColors::renderNeuron(int x, int y, sf::Color c) {
	circle.setPosition(x, y);
	circle.setFillColor(c);
	app->draw(circle);
}
