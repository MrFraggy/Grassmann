#include <basesduales.hpp>

#include <quadvector.hpp>
#include <trivector.hpp>
#include <bivector.hpp>
#include <vector.hpp>
#include <scalar.hpp>

namespace gca {
	GCA_antiquadvector operator~(const GCA_scalar& s) {
		GCA_antiquadvector a;
		a.set(e1234, s.value());
		return a;
	}

	GCA_antitrivector operator~(const GCA_vector& v) {
		GCA_antitrivector a;
		a.set(e123, -v.get(e4));
		a.set(e124, v.get(e3));
		a.set(e134, -v.get(e2));
		a.set(e234, v.get(e1));
		return a;
	}

	GCA_antibivector operator~(const GCA_bivector& b) {
		GCA_antibivector a;
		a.set(e12, b.get(e34));
		a.set(e13, -b.get(e24));
		a.set(e14, b.get(e23));
		a.set(e23, b.get(e14));
		a.set(e24, -b.get(e13));
		a.set(e34, b.get(e12));
		return a;
	}

	GCA_antivector operator~(const GCA_trivector& t) {
		GCA_antivector v;
		v.set(e1, -t.get(e234));
		v.set(e2, t.get(e134));
		v.set(e3, -t.get(e124));
		v.set(e4, t.get(e123));
		return v;
	}

	GCA_antiscalar operator~(const GCA_quadvector& q) {
		GCA_antiscalar a(q.get(e1234));
		return a;
	}

}