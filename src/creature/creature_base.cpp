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



/***********************************************************************
     * Creature
     * crossover

***********************************************************************/
void ach::Creature::crossover(ach::DNA *p1, ach::DNA *p2, float min, float max) {
	for (unsigned int i = 0; i < dna.weights.size(); i++) {
		if (rand() % 1000 < 5)
			dna.weights[i] = getRandomFloat(min, max);
		else {
			if (rand() % 2) dna.weights[i] = p1->weights[i];
			else            dna.weights[i] = p2->weights[i];
		}
	}
}
