#pragma once
#include <scalar.hpp>
#include <bitset>

namespace gca{
	typedef enum {
		e1 = 0, 
		e2 = 1,
		e3 = 2,
		e4 = 3,
		e12 = 4,
		e13 = 5,
		e14 = 6,
		e23 = 7,
		e24 = 8,
		e34 = 9,
		e123 = 10,
		e124 = 11,
		e134 = 12,
		e234 = 13,
		e1234 = 14,
		emax
	} Base;

	class GCA_base
	{
	protected:
		std::bitset<emax> bases;
		GCA_scalar valeurs[emax];

	public:
		GCA_scalar get(GCA_base b){
			assert(bases[b] == 0, "Base doesn't exist");
			return valeurs[b];
		}

		void set(GCA_base b, GCA_scalar s){
			valeurs[b] = s;
			bases[b] = 1;
		}
	};
}