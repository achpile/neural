/***********************************************************************
     * File       : misc_color.cpp
     * Created    : Aug 25, 2017
     * Copyright  : (C) 2017 Achpile
     * Author     : Fedosov Alexander
     * Email      : achpile@gmail.com

***********************************************************************/
#include "headers.hpp"



/***********************************************************************
     * Color
     * constructor

***********************************************************************/
ach::Color::Color() {
	r = 0.0f;
	g = 0.0f;
	b = 0.0f;
}



/***********************************************************************
     * Color
     * bound

***********************************************************************/
void ach::Color::bound() {
	if (r < 0.0f) r = 0.0f;
	if (r > 1.0f) r = 1.0f;

	if (g < 0.0f) g = 0.0f;
	if (g > 1.0f) g = 1.0f;

	if (b < 0.0f) b = 0.0f;
	if (b > 1.0f) b = 1.0f;
}



/***********************************************************************
     * Color
     * operator +

***********************************************************************/
ach::Color ach::Color::operator+(const ach::Color t) {
	ach::Color res;

	res.r = r + t.r;
	res.g = g + t.g;
	res.b = b + t.b;

	res.bound();

	return res;
}



/***********************************************************************
     * Color
     * operator *

***********************************************************************/
ach::Color ach::Color::operator*(const float t) {
	ach::Color res;

	res.r = r * t;
	res.g = g * t;
	res.b = b * t;

	res.bound();

	return res;
}
