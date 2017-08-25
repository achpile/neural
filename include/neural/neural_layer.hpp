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
		std::vector<ach::Neuron<T>*> neurons;


		 Layer(unsigned int count);
		~Layer();
	};
}



/***********************************************************************
     * Layer
     * constructor

***********************************************************************/
template <class T>
ach::Layer<T>::Layer(unsigned int count) {
	for (unsigned int i = 0; i < count; i++)
		neurons.push_back(new ach::Neuron<T>);
}



/***********************************************************************
     * Layer
     * destructor

***********************************************************************/
template <class T>
ach::Layer<T>::~Layer() {
	deleteList(neurons);
}

#endif
