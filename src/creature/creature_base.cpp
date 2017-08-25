/***********************************************************************
     * File       : creature_base.cpp
     * Created    : Aug 25, 2017
     * Copyright  : (C) 2017 Achpile
     * Author     : Fedosov Alexander
     * Email      : achpile@gmail.com

***********************************************************************/
#include "headers.hpp"



/***********************************************************************
     * Creature
     * constructor

***********************************************************************/
ach::Creature::Creature(unsigned int DNAlen, float min, float max) {
	for (unsigned int i = 0; i < DNAlen; i++)
		dna.weights.push_back(getRandomFloat(min, max));
}
