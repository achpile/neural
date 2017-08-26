/***********************************************************************
     * File       : misc_timer.hpp
     * Created    : Aug 26, 2017
     * Copyright  : (C) 2017 Achpile
     * Author     : Fedosov Alexander
     * Email      : achpile@gmail.com

***********************************************************************/
#ifndef __MISC_TIMER
#define __MISC_TIMER


namespace ach {
	struct Timer {
		float value;
		float timer;


		Timer() { value = 0.0f; timer = 0.0f; };

		void  setTimer(float _timer);
		void  reset();
		bool  process();
		bool  isActive();
		float getPercent();
		float getPassed();
	};
}

#endif
