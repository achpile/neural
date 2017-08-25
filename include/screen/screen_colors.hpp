/***********************************************************************
     * File       : screen_colors.hpp
     * Created    : Aug 25, 2017
     * Copyright  : (C) 2017 Achpile
     * Author     : Fedosov Alexander
     * Email      : achpile@gmail.com

***********************************************************************/
#ifndef __SCREEN_COLORS
#define __SCREEN_COLORS


namespace ach {
	struct ScreenColors : Screen {
		ach::Network<ach::Color> *network;
		ach::Population          *population;
		ach::Layer<ach::Color>   *input;
		ach::Layer<ach::Color>   *output;


		 ScreenColors();
		~ScreenColors();

		void update()                {};
		void processEvent(sf::Event) {};
		void applyLangSettings()     {};
	};
}

#endif
