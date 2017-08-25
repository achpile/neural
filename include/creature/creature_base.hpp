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
	};
}

#endif
