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

		void           addLayer(unsigned int _count);
		void           calculate(ach::DNA *dna);
		unsigned int   count();

		ach::Layer<T>* getInput();
		ach::Layer<T>* getOutput();
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

	if (layers.size() > 1)
		for (unsigned int i = 0; i < layers[layers.size() - 1]->neurons.size(); i++)
			for (unsigned int j = 0; j < layers[layers.size() - 2]->neurons.size(); j++)
				layers[layers.size() - 1]->neurons[i]->links.push_back(layers[layers.size() - 2]->neurons[j]);
}



/***********************************************************************
     * Network
     * count

***********************************************************************/
template <class T>
unsigned int ach::Network<T>::count() {
	unsigned int result = 0;

	for (unsigned int i = 0; i < layers.size() - 1; i++)
		result += layers[i]->neurons.size() * layers[i + 1]->neurons.size();

	return result;
}



/***********************************************************************
     * Network
     * getInput

***********************************************************************/
template <class T>
ach::Layer<T>* ach::Network<T>::getInput() {
	return layers[0];
}



/***********************************************************************
     * Network
     * getOutput

***********************************************************************/
template <class T>
ach::Layer<T>* ach::Network<T>::getOutput() {
	return layers[layers.size() - 1];
}



/***********************************************************************
     * Network
     * calculate

***********************************************************************/
template <class T>
void ach::Network<T>::calculate(ach::DNA *dna) {
	unsigned int index = 0;

	for (unsigned int i = 1; i < layers.size(); i++)
		for (unsigned int j = 0; j < layers[i]->neurons.size(); j++) {
			T res;

			for (unsigned int k = 0; k < layers[i]->neurons[j]->links.size(); k++)
				res = res + layers[i]->neurons[j]->links[k]->value * dna->weights[index++];

			layers[i]->neurons[j]->value = res;
		}
}

#endif
