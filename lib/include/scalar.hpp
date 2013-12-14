#pragma once
#include <iostream>
#include <antiquadvector.hpp>

namespace gca{
	
	class GCA_scalar
	{
	private:
		double k;

	public:
		GCA_scalar();
		GCA_scalar(const GCA_scalar& other);
		GCA_scalar(double s);
		
		GCA_scalar& operator=(const GCA_scalar& other);
		GCA_scalar& operator=(double other);

		GCA_scalar& operator^(const GCA_scalar& other);
		GCA_antiquadvector operator~();

		friend std::ostream& operator<<(std::ostream& out, const GCA_scalar& a);
		GCA_scalar& operator<<(double s);

	};

	inline std::ostream& operator<<(std::ostream& out, const GCA_scalar& a){
		out << a.k;
		return out;
	}
	
}