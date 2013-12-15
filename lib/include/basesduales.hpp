#pragma once

#include <antiquadvector.hpp>
#include <antitrivector.hpp>
#include <antibivector.hpp>
#include <antivector.hpp>
#include <antiscalar.hpp>

namespace gca {
	class GCA_scalar;
	class GCA_vector;
	class GCA_bivector;
	class GCA_trivector;
	class GCA_quadvector;

	GCA_antiquadvector operator~(const GCA_scalar& s);
	GCA_antitrivector operator~(const GCA_vector& v);
	GCA_antibivector operator~(const GCA_bivector& b);
	GCA_antivector operator~(const GCA_trivector& t);
	GCA_antiscalar operator~(const GCA_quadvector& q);
}