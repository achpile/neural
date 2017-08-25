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
		ach::Network<sf::Color> *network;
		ach::Population         *population;


		 ScreenColors();
		~ScreenColors();

		void update()                {};
		void processEvent(sf::Event) {};
		void applyLangSettings()     {};
	};
}

#endif
