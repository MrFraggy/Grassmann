#pragma once

#include <base.hpp>
#include <trivector.hpp>

namespace gca {
	class GCA_vector;
	class GCA_bivector : public GCA_base {
	public:
		friend GCA_trivector operator^(const GCA_bivector& a, const GCA_vector& b);
		friend GCA_trivector operator^(const GCA_vector& a, const GCA_bivector& b);
	};

	GCA_trivector operator^(const GCA_bivector& a, const GCA_vector& b);
	GCA_trivector operator^(const GCA_vector& b, const GCA_bivector& a);
}