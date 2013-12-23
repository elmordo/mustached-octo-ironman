/*
 * Color.cpp
 *
 *  Created on: 14.9.2013
 *      Author: petr
 */

#include "Color.hpp"

namespace Gremlin {
namespace Materials {

const unsigned char Color::RED = 0;
const unsigned char Color::GREEN = 1;
const unsigned char Color::BLUE = 2;
const unsigned char Color::ALPHA = 3;
const unsigned char Color::CHANNELS = 4;

Color::Color() {
	// nastavni bile nepruhledne barvy
	c[RED] = c[GREEN] = c[BLUE] = c[ALPHA] = 255;

}

Color::Color(GLfloat r, GLfloat g, GLfloat b) {
	color(r, g, b);
	c[ALPHA] = 255;
}

Color::Color(GLfloat r, GLfloat g, GLfloat b, GLfloat a) {
	color(r, g, b, a);
}

Color::Color(const Color& o) {
	// prekopirovani dat v pameti
	color(o.c);
}

Color::~Color() {
	// TODO Auto-generated destructor stub
}

GLfloat Color::alpha() const {
	return c[ALPHA];
}

void Color::alpha(GLfloat val) {
	c[ALPHA] = val;
}

GLfloat Color::blue() const {
	return c[BLUE];
}

void Color::blue(GLfloat val) {
	c[BLUE] = val;
}

const GLfloat* Color::color() const {
	return c;
}

void Color::color(const GLfloat* data) {
	// prekopirovani pameti
	memcpy(c, data, sizeof(GLfloat) * CHANNELS);
}

void Color::color(GLfloat r, GLfloat g, GLfloat b) {
	c[RED] = r;
	c[GREEN] = g;
	c[BLUE] = b;
}

void Color::color(GLfloat r, GLfloat g, GLfloat b, GLfloat a) {
	c[RED] = r;
	c[GREEN] = g;
	c[BLUE] = b;
	c[ALPHA] = a;
}

GLfloat Color::green() const {
	return c[GREEN];
}

void Color::green(GLfloat val) {
	c[GREEN] = val;
}

GLfloat Color::red() const {
	return c[RED];
}

void Color::red(GLfloat val) {
	c[RED] = val;
}

Color& Color::operator =(const Color& o) {
	// prekopirovani pameti
	color(o.c);

	return *this;
}

Color Color::operator +(const Color& o) const {
	// navratova hodnota
	Color retVal;

	// provedeni bitoveho souctu
	for (unsigned char i = 0; i < CHANNELS; i++) {
		retVal.c[i] = uintToFloat(floatToUInt(o.c[i]) | floatToUInt(c[i]));
	}

	return retVal;
}

Color& Color::operator +=(const Color& o) {
	// provedeni bitoveho souctu
	for (unsigned char i = 0; i < CHANNELS; i++) {
		c[i] = uintToFloat(floatToUInt(o.c[i]) | floatToUInt(c[i]));
	}

	return *this;
}

Color Color::operator *(const Color& o) const {
	// navratova hodnota
	Color retVal;

	// provedeni bitoveho soucinu
	for (unsigned char i = 0; i < CHANNELS; i++) {
		retVal.c[i] = uintToFloat(floatToUInt(o.c[i]) & floatToUInt(c[i]));
	}

	return retVal;
}

Color& Color::operator *=(const Color& o) {
	// provedeni bitoveho soucinu
	for (unsigned char i = 0; i < CHANNELS; i++) {
		c[i] = uintToFloat(floatToUInt(o.c[i]) & floatToUInt(c[i]));
	}

	return *this;
}

Color Color::operator ^(const Color& o) const {
	// navratova hodnota
	Color retVal;

	// provedeni bitoveho exkluzivniho souctu
	for (unsigned char i = 0; i < CHANNELS; i++) {
		retVal.c[i] = uintToFloat(floatToUInt(o.c[i]) ^ floatToUInt(c[i]));
	}

	return retVal;
}

Color& Color::operator ^=(const Color& o) {
	// provedeni bitoveho exklizivniho souctu
	for (unsigned char i = 0; i < CHANNELS; i++) {
		c[i] = uintToFloat(floatToUInt(o.c[i]) ^ floatToUInt(c[i]));
	}

	return *this;
}

Color Color::operator !() const {
	Color retVal;

	// bitova negace vsech slozek
	for (unsigned char i = 0; i < CHANNELS; i++) {
		retVal.c[i] = uintToFloat(~floatToUInt(c[i]));
	}

	return retVal;
}

bool Color::operator ==(const Color& o) const {
	// porovnani pameti obou instanci a vraceni True, pokud jsou stejne
	return memcmp(o.c, c, CHANNELS) == 0;
}

GLuint Color::floatToUInt(GLfloat v) {
	return v * UINT_MAX;
}

GLfloat Color::uintToFloat(GLuint v) {
	return v / UINT_MAX;
}

bool Color::operator !=(const Color& o) const {
	// porovnani pameti obou instanci a vraceni True, pokud nejsou stejne
	return memcmp(o.c, c, CHANNELS) != 0;
}

} /* namespace Materials */
} /* namespace Gremlin */
