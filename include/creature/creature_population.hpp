/***********************************************************************
     * File       : creature_population.hpp
     * Created    : Aug 25, 2017
     * Copyright  : (C) 2017 Achpile
     * Author     : Fedosov Alexander
     * Email      : achpile@gmail.com

***********************************************************************/
#ifndef __CREATURE_POPULATION
#define __CREATURE_POPULATION


namespace ach {
	struct Population {
		std::vector<ach::Creature*> creatures;

		unsigned int last;
		int          mutations;
		float        min;
		float        max;
		float        avg;
		float        best;
		float        mutProb;


		 Population(unsigned int count, unsigned int DNAlen, float _min, float _max);
		~Population();

		unsigned int crossover();
		unsigned int crossover2();
		void         stats();
		void         reset();
	};
}

#endif
