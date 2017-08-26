/***********************************************************************
     * File       : misc_color.hpp
     * Created    : Aug 25, 2017
     * Copyright  : (C) 2017 Achpile
     * Author     : Fedosov Alexander
     * Email      : achpile@gmail.com

***********************************************************************/
#ifndef __MISC_COLOR
#define __MISC_COLOR


namespace ach {
	struct Color {
		float r;
		float g;
		float b;


		Color();

		void bound();

		sf::Color  get();
		void       set(sf::Color c);
		ach::Color operator+(const ach::Color t);
		ach::Color operator*(const float t);
	};
}

#endif
