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
		ach::DNA                  dna;

		ach::Timer                timer;
		ach::Color                goal1;
		ach::Color                goal2;
		sf::CircleShape           circle;
		sf::Color                 colors[9];
		sf::VertexArray           line;

		unsigned int              iterations;


		 ScreenColors();
		~ScreenColors();

		void update();
		void render();
		void renderText();
		void renderNetwork();
		void renderNeuron(int x, int y, sf::Color c, int border = 0, sf::Color bc = sf::Color::White);
		void renderLine(int x1, int y1, int x2, int y2, float weight);

		float fitness(ach::Color c1, ach::Color c2);
		void  process(unsigned int index);
		void  copyColors();
		void  copyWeights();
	};
}

#endif
