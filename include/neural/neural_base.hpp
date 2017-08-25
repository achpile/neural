/***********************************************************************
     * File       : neural_base.hpp
     * Created    : Aug 25, 2017
     * Copyright  : (C) 2017 Achpile
     * Author     : Fedosov Alexander
     * Email      : achpile@gmail.com

***********************************************************************/
#ifndef __NEURAL_BASE
#define __NEURAL_BASE

namespace ach {
	struct Neuron {
		std::vector<ach::Neuron*> links;

		float value;
	};
}

#endif
