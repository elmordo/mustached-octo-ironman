/*
 * Colored.cpp
 *
 *  Created on: 29.8.2013
 *      Author: petr
 */

#include "Colored.hpp"

namespace Gremlin {
namespace Materials {

Colored::Colored() {
	s = 0;
	ec.color(0,0,0,255);
	a = 1.0;
}

Colored::Colored(const Colored& o) {
	dc = o.dc;
	ec = o.ec;
	s = o.s;
	sc = o.sc;
	a = o.a;
}

Colored::~Colored() {
	// TODO Auto-generated destructor stub
}

GLfloat Colored::alpha() const {
	return a;
}

void Colored::alpha(GLfloat a) {
	this->a = a;
}

const Color& Colored::ambient() const {
	return ac;
}

Color& Colored::ambient() {
	return ac;
}

const Color& Colored::difuse() const {
	return dc;
}

Color& Colored::difuse() {
	return dc;
}

const Color& Colored::emision() const {
	return ec;
}

Color& Colored::emision() {
	return ec;
}

bool Colored::hasAlpha() const {
	return a != 1;
}

void Colored::setup() const {
	// nastaveni dat
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, dc.color());
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, sc.color());
	glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, ec.color());
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, s);
}

GLfloat Colored::shininess() const {
	return s;
}

void Colored::shininess(GLfloat s) {
	this->s = s;
}

const Color& Colored::specular() const {
	return sc;
}

Color& Colored::specular() {
	return sc;
}

Colored& Colored::operator =(const Colored& o) {
	ac = o.ac;
	dc = o.dc;
	s = o.s;
	sc = o.sc;

	return *this;
}

} /* namespace Material */
} /* namespace Gremlin */
