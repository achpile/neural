/***********************************************************************
     * File       : screen_select.hpp
     * Created    : Dec 06, 2017
     * Copyright  : (C) 2017 Achpile
     * Author     : Fedosov Alexander
     * Email      : achpile@gmail.com

***********************************************************************/
#ifndef __SCREEN_SELECT
#define __SCREEN_SELECT


namespace ach {
	struct ScreenSelect : Screen {
		 ScreenSelect();
		~ScreenSelect();

		void update();
		void render();

		void create(int index);

		void processEvent(sf::Event event);
	};
}

#endif
