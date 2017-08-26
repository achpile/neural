/***********************************************************************
     * File       : screen_base.hpp
     * Created    : Aug 25, 2017
     * Copyright  : (C) 2017 Achpile
     * Author     : Fedosov Alexander
     * Email      : achpile@gmail.com

***********************************************************************/
#ifndef __SCREEN_BASE
#define __SCREEN_BASE


namespace ach {
	struct Screen {
				 Screen()                    {};
		virtual ~Screen()                    {};
		virtual void update()                {};
		virtual void processEvent(sf::Event) {};
	};
}

#endif
