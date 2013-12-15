#pragma once

#include <base.hpp>
#include <quadvector.hpp>

namespace gca {
	class GCA_vector;
	class GCA_trivector : public GCA_base {
	public:
		GCA_quadvector operator^(const GCA_vector& other);
	};
}