#include <bivector.hpp>
#include <vector.hpp>

namespace gca {
	GCA_trivector operator^(const GCA_bivector& a, const GCA_vector& b) {
		GCA_trivector triv;
		triv.set(Base::e123, a.get(e12)*b.get(e3)-a.get(e13)*b.get(e2)+a.get(e23)*b.get(e1));
		triv.set(Base::e124, a.get(e12)*b.get(e4)-a.get(e14)*b.get(e2)+a.get(e24)*b.get(e1));
		triv.set(Base::e134, a.get(e13)*b.get(e4)-a.get(e14)*b.get(e3)+a.get(e34)*b.get(e1));
		triv.set(Base::e234, a.get(e23)*b.get(e4)-a.get(e24)*b.get(e3)+a.get(e34)*b.get(e2));
		return triv;
	}

	GCA_trivector operator^(const GCA_vector& b, const GCA_bivector& a) {
		return a^-b;
	}
}