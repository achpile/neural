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
	min       = _min;
	max       = _max;
	mutations = 0;

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



/***********************************************************************
     * Population
     * crossover

***********************************************************************/
unsigned int ach::Population::crossover() {
	unsigned int min, p1, p2;

	min = 0;
	avg = creatures[0]->fitness;

	for (unsigned int i = 1; i < creatures.size(); i++) {
		avg += creatures[i]->fitness;

		if (creatures[min]->fitness > creatures[i]->fitness)
			min = i;
	}

	avg /= creatures.size();

	do {
		p1 = rand() % creatures.size();
	} while (p1 == min);

	do {
		p2 = rand() % creatures.size();
	} while (p2 == min || p2 == p1);

	creatures[min]->fitness = 0.0f;

	mutations += creatures[min]->crossover(&creatures[p1]->dna, &creatures[p2]->dna, min, max, mutProb);

	return min;
}



/***********************************************************************
     * Population
     * reset

***********************************************************************/
void ach::Population::reset() {
	for (unsigned int i = 0; i < creatures.size(); i++)
		creatures[i]->fitness = 0.0f;
}
