#include <scalar.hpp>

namespace gca{

	GCA_scalar::GCA_scalar() : k(0.0){};
	GCA_scalar::GCA_scalar(const GCA_scalar& other) : k(other.k){};
	GCA_scalar::GCA_scalar(double s) : k(s){};
	
	GCA_scalar& GCA_scalar::operator=(const GCA_scalar& other){
		k = other.k;
		return *this;
	}

	GCA_scalar& GCA_scalar::operator=(double other){
		k = other;
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