/***********************************************************************
     * File       : defines.hpp
     * Created    : Aug 25, 2017
     * Copyright  : (C) 2017 Achpile
     * Author     : Fedosov Alexander
     * Email      : achpile@gmail.com

***********************************************************************/
#ifndef __DEFINES
#define __DEFINES



/***********************************************************************
     * Main project constants

***********************************************************************/
#define PROJECT_CAPTION "Neural Networks"



/***********************************************************************
     * List processing macros

***********************************************************************/
#define deleteList(list) for (; !(list).empty();) { if ((list).back()) delete (list).back(); (list).pop_back(); }



/***********************************************************************
     * Math

***********************************************************************/
#define PI             3.1415926f



/***********************************************************************
     * Flappy Bird

***********************************************************************/
#define FLAPPY_SPEED   200.0f
#define FLAPPY_DIFF    300.0f
#define FLAPPY_HIGH     75.0f
#define FLAPPY_COUNT   10
#define FLAPPY_LIMIT_T 125.0f
#define FLAPPY_LIMIT_B 415.0f



/***********************************************************************
     * Hexagon

***********************************************************************/
#define HEXAGON_COUNT     8
#define HEXAGON_MOVE      8.0f
#define HEXAGON_RADIUS    40.0f
#define HEXAGON_OFFSET    50.0f
#define HEXAGON_THICKNESS 20.0f
#define HEXAGON_SPEED     175.0f
#define HEXAGON_MINRAD    185.0f
#define HEXAGON_STEPRAD   75.0f


#endif
