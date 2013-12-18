#pragma once

#include <scalar.hpp>

namespace gca {
	class GCA_antiscalar : public GCA_scalar {
	public:
		GCA_antiscalar(const GCA_scalar& a) : GCA_scalar(a) {}
	};
}