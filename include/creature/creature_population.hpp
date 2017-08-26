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

		float min;
		float max;
		float avg;


		 Population(unsigned int count, unsigned int DNAlen, float _min, float _max);
		~Population();

		unsigned int crossover();
		void         reset();
	};
}

#endif
