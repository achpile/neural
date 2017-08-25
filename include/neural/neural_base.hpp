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
	template <class T>
	struct Neuron {
		std::vector<Neuron<T>*> links;

		T value;
	};
}

#endif
