/*
 * MaterialBase.hpp
 *
 *  Created on: 14.9.2013
 *      Author: petr
 */

#ifndef MATERIALBASE_HPP_
#define MATERIALBASE_HPP_

#include <list>
#include <map>

using namespace std;

namespace Gremlin {
namespace Materials {

class MaterialBase {
public:

	/**
	 * bezparametricky konstruktor
	 */
	MaterialBase();

	/**
	 * kopytor
	 */
	MaterialBase(const MaterialBase &o);

	/**
	 * destruktor
	 */
	virtual ~MaterialBase();

	/**
	 * nastavi barvu do open GL
	 */
	virtual void setup() const = 0;

	/**
	 * vraci TRUE, pokud je material pruhledny
	 */
	virtual bool hasAlpha() const = 0;
};

typedef list<const MaterialBase*> MaterialList;
typedef map<size_t, MaterialBase*> MaterialMap;

} /* namespace Materials */
} /* namespace Gremlin */
#endif /* MATERIALBASE_HPP_ */
