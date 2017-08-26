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

	input->neurons[0]->value.r = 1.0f;
	input->neurons[0]->value.g = 0.0f;
	input->neurons[0]->value.b = 0.0f;

	input->neurons[1]->value.r = 0.0f;
	input->neurons[1]->value.g = 1.0f;
	input->neurons[1]->value.b = 0.0f;

	input->neurons[2]->value.r = 0.0f;
	input->neurons[2]->value.g = 0.0f;
	input->neurons[2]->value.b = 1.0f;

	population->reset();
}



/***********************************************************************
     * ScreenColors
     * destructor

***********************************************************************/
ach::ScreenColors::~ScreenColors() {
	delete network;
	delete population;
}
