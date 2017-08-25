/***********************************************************************
     * File       : misc_math.cpp
     * Created    : Aug 25, 2017
     * Copyright  : (C) 2017 Achpile
     * Author     : Fedosov Alexander
     * Email      : achpile@gmail.com

***********************************************************************/
#include "headers.hpp"



/***********************************************************************
     * getRandomFloat

***********************************************************************/
float getRandomFloat(float min, float max) {
	return min + (max - min) * (float)(rand() % 1000) / 1000.0f;
}
