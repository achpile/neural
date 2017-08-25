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
		std::vector<ach::Layer<T>> layers;
	};
}

#endif
