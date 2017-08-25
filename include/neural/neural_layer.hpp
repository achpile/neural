/***********************************************************************
     * File       : neural_layer.hpp
     * Created    : Aug 25, 2017
     * Copyright  : (C) 2017 Achpile
     * Author     : Fedosov Alexander
     * Email      : achpile@gmail.com

***********************************************************************/
#ifndef __NEURAL_LAYER
#define __NEURAL_LAYER

namespace ach {
	template <class T>
	struct Layer {
		std::vector<ach::Neuron<T>> neurons;
	};
}

#endif
