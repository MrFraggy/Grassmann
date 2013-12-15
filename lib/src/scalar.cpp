#include <scalar.hpp>

namespace gca{

	GCA_scalar::GCA_scalar() : 
		GCA_scalar(0.0)
	{

	}

	GCA_scalar::GCA_scalar(const GCA_scalar& other) : 
		GCA_scalar(other.k)
	{

	}

	GCA_scalar::GCA_scalar(double s) : 
		k(s)
	{

	}

	double GCA_scalar::value() const {
		return k;
	}

	GCA_scalar GCA_scalar::operator-() {
		return GCA_scalar(-k);
	}
	
	GCA_scalar& GCA_scalar::operator=(const GCA_scalar& other){
		k = other.k;
		return *this;
	}

	GCA_scalar& GCA_scalar::operator=(double other){
		k = other;
		return *this;
	}

	GCA_scalar GCA_scalar::operator+(const GCA_scalar& other) {
		GCA_scalar s(*this);
		s+=other;
		return s;
	}

	GCA_scalar& GCA_scalar::operator+=(const GCA_scalar& other) {
		k += other.k;
		return *this;
	}

	GCA_scalar GCA_scalar::operator-(const GCA_scalar& other) {
		GCA_scalar s(*this);
		s-=other;
		return s;
	}

	GCA_scalar& GCA_scalar::operator-=(const GCA_scalar& other) {
		k -= other.k;
		return *this;
	}

	GCA_scalar GCA_scalar::operator*(const GCA_scalar& other) {
		GCA_scalar s(*this);
		s*=other;
		return s;
	}

	GCA_scalar& GCA_scalar::operator*=(const GCA_scalar& other) {
		k *= other.k;
		return *this;
	}

	GCA_scalar GCA_scalar::operator/(const GCA_scalar& other) {
		GCA_scalar s(*this);
		s/=other;
		return s;
	}

	GCA_scalar& GCA_scalar::operator/=(const GCA_scalar& other) {
		k /= other.k;
		return *this;
	}


	GCA_scalar& GCA_scalar::operator^(const GCA_scalar& other){
		k = k*other.k;
		return *this;
	}

	/*GCA_antiquadvector GCA_scalar::operator~(){
		GCA_antiquadvector v();
		return v;
	}*/

	GCA_scalar& GCA_scalar::operator<<(double s){
		k = s;
		return *this;
	}

}