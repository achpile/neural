/***********************************************************************
     * File       : screen_bird.hpp
     * Created    : Aug 26, 2017
     * Copyright  : (C) 2017 Achpile
     * Author     : Fedosov Alexander
     * Email      : achpile@gmail.com

***********************************************************************/
#ifndef __SCREEN_BIRD
#define __SCREEN_BIRD


namespace ach {
	struct Bird {
		float y;
		float speed;
		bool  dead;
	};


	struct ScreenBird : Screen {
		ach::Network<float>      *network;
		ach::Population          *population;
		ach::Layer<float>        *input;
		ach::Layer<float>        *output;
		ach::Bird                 birds[8];

		sf::Texture               bird_up_t;
		sf::Texture               bird_down_t;
		sf::Texture               floor_t;
		sf::Texture               bg_t;
		sf::Texture               tube_top_t;
		sf::Texture               tube_bot_t;

		sf::Sprite                bird_up;
		sf::Sprite                bird_down;
		sf::Sprite                tube_top;
		sf::Sprite                tube_bot;
		sf::RectangleShape        floor;
		sf::RectangleShape        bg;

		sf::IntRect               floor_rect;
		sf::IntRect               bg_rect;

		float                     distance;
		float                     offset;
		float                     dst;
		float                     tubes[4];
		unsigned int              iterations;
		unsigned int              alive;
		int                       actual;


		 ScreenBird();
		~ScreenBird();

		void update();
		void render();
		void renderScene();
		void renderTubes();
		void renderTube(float x, float y);
		void renderBirds();
		void renderBird(float y, float speed);
		void renderText();

		void phys();
		void next();
		void reset();
		bool check(float y);
		void process(unsigned int index);
	};
}

#endif
