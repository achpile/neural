/***********************************************************************
     * File       : neural_network.hpp
     * Created    : Aug 25, 2017
     * Copyright  : (C) 2017 Achpile
     * Author     : Fedosov Alexander
     * Email      : achpile@gmail.com

***********************************************************************/
#ifndef __NEURAL_NETWORK
#define __NEURAL_NEYWORK

namespace ach {
	template <class T>
	struct Network {
		std::vector<ach::Layer<T>*> layers;


		 Network();
		~Network();

		void         addLayer(unsigned int _count);
		unsigned int count();
	};
}



/***********************************************************************
     * Network
     * constructor

***********************************************************************/
template <class T>
ach::Network<T>::Network() {
}



/***********************************************************************
     * Network
     * destructor

***********************************************************************/
template <class T>
ach::Network<T>::~Network() {
	deleteList(layers);
}



/***********************************************************************
     * Network
     * addLayer

***********************************************************************/
template <class T>
void ach::Network<T>::addLayer(unsigned int _count) {
	layers.push_back(new ach::Layer<T>(_count));
}



/***********************************************************************
     * Network
     * count

***********************************************************************/
template <class T>
unsigned int ach::Network<T>::count() {
	unsigned int result = 0;

	for (unsigned int i = 0; i < layers.size(); i++)
		result += layers[i]->neurons.size();

	return result;
}

#endif
