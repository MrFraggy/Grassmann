#pragma once
#include <iostream>

namespace gca{
	
	class GCA_scalar
	{
	private:
		double k;

	public:
		GCA_scalar();
		GCA_scalar(const GCA_scalar& other);
		GCA_scalar(double s);
		
		double value() const;

		GCA_scalar operator-();

		GCA_scalar& operator=(const GCA_scalar& other);
		GCA_scalar& operator=(double other);

		GCA_scalar operator+(const GCA_scalar& other);
		GCA_scalar& operator+=(const GCA_scalar& other);
		GCA_scalar operator-(const GCA_scalar& other);
		GCA_scalar& operator-=(const GCA_scalar& other);
		GCA_scalar operator*(const GCA_scalar& other);
		GCA_scalar& operator*=(const GCA_scalar& other);
		GCA_scalar operator/(const GCA_scalar& other);
		GCA_scalar& operator/=(const GCA_scalar& other);

		GCA_scalar& operator^(const GCA_scalar& other);

		friend std::ostream& operator<<(std::ostream& out, const GCA_scalar& a);
		GCA_scalar& operator<<(double s);

	};

	inline std::ostream& operator<<(std::ostream& out, const GCA_scalar& a){
		out << a.k;
		return out;
	}
	
}