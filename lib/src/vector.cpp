#include <vector.hpp>

namespace gca {
	GCA_vector::GCA_vector() :
		GCA_vector(0.0,0.0,0.0,1.0)
	{
	}

	GCA_vector::GCA_vector(double x, double y, double z, double w) :
		m_data(Eigen::VectorXd(4))
	{
		m_data << x,y,z,w;
	}

	CommaTrick GCA_vector::operator<<(double d) {
		return CommaTrick(*this, d);
	}

}