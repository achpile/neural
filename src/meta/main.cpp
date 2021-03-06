/***********************************************************************
     * File       : main.cpp
     * Created    : Aug 25, 2017
     * Copyright  : (C) 2017 Achpile
     * Author     : Fedosov Alexander
     * Email      : achpile@gmail.com

***********************************************************************/
#include "headers.hpp"
#include "globals.hpp"



/***********************************************************************
     * Main function

***********************************************************************/
int main() {
	demo = new ach::Demo;

	while(demo->running) demo->update();
	delete demo;

	return EXIT_SUCCESS;
}
