/***********************************************************************
     * File       : demo.hpp
     * Created    : Aug 25, 2017
     * Copyright  : (C) 2017 Achpile
     * Author     : Fedosov Alexander
     * Email      : achpile@gmail.com

***********************************************************************/
#ifndef __DEMO
#define __DEMO


namespace ach {
	struct Demo {
		ach::Screen      *screen;
		sf::Clock        *clock;

		long lastClock;
		bool running;
		bool focused;


		 Demo();
		~Demo();

		void update();
		void stop();

		void processEvents();
		void processEvent(sf::Event event);
	};
}

#endif
