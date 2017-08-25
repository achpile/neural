/***********************************************************************
     * File       : creature_population.cpp
     * Created    : Aug 25, 2017
     * Copyright  : (C) 2017 Achpile
     * Author     : Fedosov Alexander
     * Email      : achpile@gmail.com

***********************************************************************/
#include "headers.hpp"



/***********************************************************************
     * Population
     * constructor

***********************************************************************/
ach::Population::Population(unsigned int count, unsigned int DNAlen, float _min, float _max) {
	min = _min;
	max = _max;

	for (unsigned int i = 0; i < count; i++)
		creatures.push_back(new ach::Creature(DNAlen, _min, _max));
}



/***********************************************************************
     * Population
     * destructor

***********************************************************************/
ach::Population::~Population() {
	deleteList(creatures);
}
