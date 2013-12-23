/*
 * Color.hpp
 *
 *  Created on: 14.9.2013
 *      Author: petr
 */

#ifndef COLOR_HPP_
#define COLOR_HPP_

#include <GL/gl.h>
#include <cstring>
#include <climits>

namespace Gremlin {
namespace Materials {

class Color {

	/**
	 * pole obsahujici slozky barev
	 */
	GLfloat c[4];

protected:

	/**
	 * prevede desetinne cislo na cele
	 */
	static GLuint floatToUInt(GLfloat v);

	/**
	 * prevede cele cislo na desetinne
	 */
	static GLfloat uintToFloat(GLuint v);

public:

	/**
	 * konstanty indexu slozek v poli
	 */
	static const unsigned char RED;
	static const unsigned char GREEN;
	static const unsigned char BLUE;
	static const unsigned char ALPHA;

	/**
	 * pocet kanalu, se kterymi se pracuje
	 */
	static const unsigned char CHANNELS;

	/**
	 * bezparametricky konstruktor nastavi bilou nepruhlednou barvu
	 */
	Color();

	/**
	 * nastavi slozky RGB z parametru
	 * alfa kanal nastavi na 1
	 */
	Color(GLfloat r, GLfloat g, GLfloat b);

	/**
	 * nastavi RGBA
	 */
	Color(GLfloat r, GLfloat g, GLfloat b, GLfloat a);

	/**
	 * kopytor
	 */
	Color(const Color &o);

	/**
	 * destruktor - nic nedela
	 */
	virtual ~Color();

	/**
	 * vraci nebo nastavi Alfa kanal
	 */
	GLfloat alpha() const;
	void alpha(GLfloat val);

	/**
	 * vraci nebo nastavi modry kanal
	 */
	GLfloat blue() const;
	void blue(GLfloat val);

	/**
	 * vraci ukazatel na surova data v pameti
	 */
	const GLfloat *color() const;

	/**
	 * nastavi nova data z pole
	 */
	void color(const GLfloat *data);

	/**
	 * nastavi slozky RGB
	 * alfa kanal necha tak jak je
	 */
	void color(GLfloat r, GLfloat g, GLfloat b);

	/**
	 * nastavi RGBA
	 */
	void color(GLfloat r, GLfloat g, GLfloat b, GLfloat a);

	/**
	 * vraci nebo nastavi zeleny kanal
	 */
	GLfloat green() const;
	void green(GLfloat val);

	/**
	 * vraci nebo nastavi cerveny kanal
	 */
	GLfloat red() const;
	void red(GLfloat val);

	/**
	 * operator prirazeni
	 */
	Color &operator =(const Color &o);

	/**
	 * operatory souctu barev
	 * provadi se bitovy soucet
	 */
	Color operator +(const Color &o) const;
	Color &operator +=(const Color &o);

	/**
	 * operatory soucinu barev
	 * provadi se bitovy soucin
	 */
	Color operator *(const Color &o) const;
	Color &operator *=(const Color &o);

	/**
	 * operatory exluzivniho souctu barev
	 * provadi se bitovy soucet
	 */
	Color operator ^(const Color &o) const;
	Color &operator ^=(const Color &o);

	/**
	 * negace barvy
	 */
	Color operator !() const;

	/**
	 * operatory rovnosti a nerovnosti
	 */
	bool operator ==(const Color &o) const;
	bool operator !=(const Color &o) const;
};

} /* namespace Materials */
} /* namespace Gremlin */
#endif /* COLOR_HPP_ */
