#pragma once
#include <scalar.hpp>
#include <bitset>
#include <cassert>
#include <array>

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
		std::array<GCA_scalar, emax> valeurs;

		void reset() {
			bases.reset();
		}

	public:
		GCA_base() = default;

		GCA_base(const GCA_base& other) :
			bases(other.bases), valeurs(other.valeurs)
		{

		}

		GCA_base& operator=(const GCA_base& other) {
			bases = other.bases;
			valeurs = other.valeurs;
			return *this;
		}

		GCA_scalar get(Base b) const{
			assert(bases.test(b) && "Base doesn't exist");
			return valeurs[b];
		}

		void set(Base b, GCA_scalar s){
			valeurs[b] = s;
			bases.set(b);
		}

		friend std::ostream& operator<<(std::ostream& out, GCA_base& b);
	};

	inline std::ostream& operator<<(std::ostream& out, GCA_base& b) {
		for(uint16_t i = 0; i<b.bases.size(); ++i)
				if(b.bases[i])
					std::cout << i << "|" << b.valeurs[i] << " ";

		return out;
	}
}