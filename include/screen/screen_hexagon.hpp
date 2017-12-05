/***********************************************************************
     * File       : screen_hexagon.hpp
     * Created    : Dec 06, 2017
     * Copyright  : (C) 2017 Achpile
     * Author     : Fedosov Alexander
     * Email      : achpile@gmail.com

***********************************************************************/
#ifndef __SCREEN_HEXAGON
#define __SCREEN_HEXAGON


namespace ach {
	struct HexPlayer {
		float angle;
		bool  dead;
	};


	struct ScreenHexagon : Screen {
		ach::Network<float>      *network;
		ach::Population          *population;
		ach::Layer<float>        *input;
		ach::Layer<float>        *output;
		ach::HexPlayer            players[HEXAGON_COUNT];

		sf::CircleShape          *center;
		sf::CircleShape          *player;
		sf::ConvexShape          *shape;
		sf::Vertex                line[2];

		float                     sectors[6];
		float                     distance;
		float                     best;
		unsigned int              iterations;
		unsigned int              alive;
		int                       actual;


		 ScreenHexagon();
		~ScreenHexagon();

		void update();
		void render();
		void renderScene();
		void renderLine(int i);
		void renderShape(int i, float dist);
		void renderPlayer(float angle, int index);
		void renderText();

		void phys();
		void next();
		bool needNext();
		void reset();
		bool check(float angle);
		void process(unsigned int index);

		sf::Vector2f getPos(int i, float radius);
		sf::Vector2f getPos(float angle, float radius);

		void processEvent(sf::Event event);
	};
}

#endif
