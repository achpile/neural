/***********************************************************************
     * File       : creature_base.hpp
     * Created    : Aug 25, 2017
     * Copyright  : (C) 2017 Achpile
     * Author     : Fedosov Alexander
     * Email      : achpile@gmail.com

***********************************************************************/
#ifndef __CREATURE_BASE
#define __CREATURE_BASE

namespace ach {
	struct Creature {
		ach::DNA dna;

		float fitness;


		Creature(unsigned int DNAlen, float min, float max);

		int  crossover(ach::DNA *p1, ach::DNA *p2, float min, float max, float mutProb);
	};
}

#endif
