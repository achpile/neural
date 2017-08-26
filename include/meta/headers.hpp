/***********************************************************************
     * File       : headers.hpp
     * Created    : Aug 25, 2017
     * Copyright  : (C) 2017 Achpile
     * Author     : Fedosov Alexander
     * Email      : achpile@gmail.com

***********************************************************************/
#ifndef __HEADERS
#define __HEADERS

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <random>
#include <string.h>
#include <math.h>
#include <dirent.h>
#include <jansson.h>


#include "defines.hpp"

#include "misc/misc_base.hpp"
#include "misc/misc_math.hpp"
#include "misc/misc_color.hpp"
#include "misc/misc_timer.hpp"

#include "neural/neural_base.hpp"
#include "neural/neural_layer.hpp"
#include "neural/neural_dna.hpp"
#include "neural/neural_network.hpp"

#include "creature/creature_base.hpp"
#include "creature/creature_population.hpp"

#include "screen/screen_base.hpp"
#include "screen/screen_colors.hpp"
#include "screen/screen_jump.hpp"

#include "demo.hpp"
#include "externs.hpp"

#endif
