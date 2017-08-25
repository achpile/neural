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
	network    = new ach::Network<sf::Color>;
	population = new ach::Population(100, 12, 0.0f, 2.0f);
}



/***********************************************************************
     * ScreenColors
     * destructor

***********************************************************************/
ach::ScreenColors::~ScreenColors() {
	delete network;
	delete population;
}
