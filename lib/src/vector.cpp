#include <vector.hpp>
#include <scalar.hpp>

namespace gca {
	GCA_vector::GCA_vector() :
		GCA_vector(0.0,0.0,0.0,1.0)
	{
	}

	GCA_vector::GCA_vector(double x, double y, double z, double w)
	{
		*this << x,y,z,w;
	}

	GCA_vector::GCA_vector(const GCA_vector& other) {
		bases = other.bases;
		valeurs = other.valeurs;
	}

	GCA_bivector GCA_vector::operator^(const GCA_vector& other){
		GCA_bivector biv;
		biv.set(Base::e12, get(e1)*other.get(e2)-get(e2)*other.get(e1));
		biv.set(Base::e13, get(e1)*other.get(e3)-get(e3)*other.get(e1));
		biv.set(Base::e14, get(e1)*other.get(e4)-get(e4)*other.get(e1));
		biv.set(Base::e23, get(e2)*other.get(e3)-get(e3)*other.get(e2));
		biv.set(Base::e24, get(e2)*other.get(e4)-get(e4)*other.get(e2));
		biv.set(Base::e34, get(e3)*other.get(e4)-get(e4)*other.get(e3));
		return biv;
	}

	CommaTrick GCA_vector::operator<<(double d) {
		return CommaTrick(*this, d);
	}

	GCA_vector GCA_vector::operator-() const {
		GCA_vector b(*this);
		for(uint16_t i = 0; i<b.bases.size(); ++i) {
			if(b.bases[i])
				b.valeurs[i] = -b.valeurs[i];					 
		}
		return b;
	}

	GCA_vector GCA_vector::operator*(const GCA_scalar& other) {
		GCA_vector b(*this);
		b *= other;
		return b;
	}

	GCA_vector& GCA_vector::operator*=(const GCA_scalar& other) {
		for(uint16_t i = 0; i<bases.size(); ++i) {
			if(bases[i])
				valeurs[i] *= other;					 
		}
		return *this;
	}

	GCA_vector GCA_vector::operator/(const GCA_scalar& other) {
		GCA_vector b(*this);
		b /= other;
		return b;
	}

	GCA_vector& GCA_vector::operator/=(const GCA_scalar& other) {
		for(uint16_t i = 0; i<bases.size(); ++i) {
			if(bases[i])
				valeurs[i] /= other;					 
		}
		return *this;
	}

	GCA_vector GCA_vector::operator+(const GCA_vector& other) {
		GCA_vector b(*this);
		b += other;
		return b;
	}

	GCA_vector& GCA_vector::operator+=(const GCA_vector& other) {
		for(uint16_t i = 0; i<bases.size(); ++i) {
			assert(((!bases[i] && other.bases[i]) || (bases[i] && !other.bases[i])) && "base not of the same ");
			
			valeurs[i] += other.valeurs[i];					 
		}
		return *this;
	}

	GCA_vector GCA_vector::operator-(const GCA_vector& other) {
		GCA_vector b(*this);
		b -= other;
		return b;
	}

	GCA_vector& GCA_vector::operator-=(const GCA_vector& other) {
		for(uint16_t i = 0; i<bases.size(); ++i) {
			assert(((bases[i] && !other.bases[i]) || (!bases[i] && other.bases[i])) && "base not of the same ");
			
			valeurs[i] -= other.valeurs[i];					 
		}
		return *this;
	}
}