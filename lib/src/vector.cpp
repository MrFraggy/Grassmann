#include <vector.hpp>
#include <scalar.hpp>

namespace gca {
	GCA_vector::GCA_vector() :
		GCA_vector(0.0,0.0,0.0,1.0)
	{
	}

	GCA_vector::GCA_vector(const GCA_vector& other) :
		GCA_vector(other.m_data(0), other.m_data(1), other.m_data(2), other.m_data(3))
	{
	}

	GCA_vector::GCA_vector(double x, double y, double z, double w) :
		m_data(Eigen::VectorXd(4))
	{
		m_data << x,y,z,w;
	}

	GCA_vector& GCA_vector::operator=(const GCA_vector& other) {
		m_data = other.m_data;
		return *this;
	}

	GCA_vector GCA_vector::operator*(const GCA_scalar& other) {
		GCA_vector v(*this);
		v *= other;
		return v;
	}

	GCA_vector& GCA_vector::operator*=(const GCA_scalar& other) {
		m_data *= other.value();
		return *this;
	}

	GCA_vector GCA_vector::operator/(const GCA_scalar& other) {
		GCA_vector v(*this);
		v /= other;
		return v;
	}

	GCA_vector& GCA_vector::operator/=(const GCA_scalar& other) {
		m_data /= other.value();
		return *this;
	}

	GCA_vector GCA_vector::operator+(const GCA_vector& other) {
		GCA_vector v(*this);
		v += other;
		return v;
	}

	GCA_vector& GCA_vector::operator+=(const GCA_vector& other) {
		m_data += other.m_data;
		return *this;
	}

	GCA_vector GCA_vector::operator-(const GCA_vector& other) {
		GCA_vector v(*this);
		v -= other;
		return v;
	}

	GCA_vector& GCA_vector::operator-=(const GCA_vector& other) {
		m_data -= other.m_data;
		return *this;
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


	GCA_vector operator*(const GCA_vector& a, const GCA_scalar& b) {
		GCA_vector v(a);
		v *= b;
		return v;
	}

	GCA_vector operator*(const GCA_scalar& a, const GCA_scalar& b) {
		return b*a;
	}



}