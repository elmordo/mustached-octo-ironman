/*
 * Colored.h
 *
 *  Created on: 29.8.2013
 *      Author: petr
 */

#ifndef COLORED_H_
#define COLORED_H_

#include<list>
#include<map>

#include "Color.hpp"
#include "MaterialBase.hpp"

using namespace std;

namespace Gremlin {
namespace Materials {

class Colored: public MaterialBase {

	/**
	 * pruhlednost
	 */
	GLfloat a;

	/**
	 * ambientni barva
	 */
	Color ac;

	/**
	 * difusni barva
	 */
	Color dc;

	/**
	 * barva emitovaneho svetla
	 * (vychozi je cerna)
	 */
	Color ec;

	/**
	 * reflexni barva
	 */
	Color sc;

	/**
	 * odrazivost materialu
	 */
	GLfloat s;

public:

	/**
	 * bezparametricky konstruktor
	 * nastavi difusni a reflexni slozku na bilou a emisni na cernou
	 */
	Colored();

	/**
	 * kopytor
	 */
	Colored(const Colored &o);

	/**
	 * destruktor
	 */
	virtual ~Colored();

	/**
	 * pristup k pruhlednosti
	 */
	GLfloat alpha() const;
	void alpha(GLfloat a);

	/**
	 * pristup k difusni slozce
	 */
	const Color &ambient() const;
	Color &ambient();

	/**
	 * pristup k difusni slozce
	 */
	const Color &difuse() const;
	Color &difuse();

	/**
	 * pristup k barve emitovaneho svetla
	 */
	const Color &emision() const;
	Color &emision();

	/**
	 * vraci True, pokud je material pruhledny
	 */
	virtual bool hasAlpha() const;

	/**
	 * zapise nastaveni do OpenGL
	 */
	void setup() const;

	/**
	 * ziskani a nastaveni odrazivosti
	 */
	GLfloat shininess() const;
	void shininess(GLfloat s);

	/**
	 * pristup k nastaveni reflexni slozky
	 */
	const Color &specular() const;
	Color &specular();

	/**
	 * operator prirazeni
	 */
	Colored &operator= (const Colored &o);
};

} /* namespace Material */
} /* namespace Gremlin */
#endif /* COLORED_H_ */
