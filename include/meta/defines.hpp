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
     * Flappy Bird

***********************************************************************/
#define FLAPPY_SPEED 100.0f
#define FLAPPY_DIFF  300.0f
#define FLAPPY_HIGH   75.0f


#endif
