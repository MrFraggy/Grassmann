#pragma once

#include <antitrivector.hpp>
#include <iostream>
#include <Eigen/Dense>

namespace gca {

	class CommaTrick;
	
	class GCA_vector {
	public:
		GCA_vector();
		GCA_vector(const GCA_vector& other);
		GCA_vector(double x, double y, double z, double w);

		GCA_vector& operator=(const GCA_vector& other);

		void operator^(const GCA_vector& other);
		GCA_antitrivector operator~();

		friend std::ostream& operator<<(std::ostream& out, const GCA_vector& v);

		CommaTrick operator<<(double d);
		friend class CommaTrick;

	private:
		Eigen::VectorXd m_data;
	};

	class CommaTrick {
	public:
		CommaTrick(GCA_vector& v, double d) :
			v(v), m_counter(0)
		{ insert(d); }

		CommaTrick& operator,(double d) {
			insert(d);
			return *this;
		}

		void insert(double d) {
			if(m_counter < v.m_data.size())
				v.m_data(m_counter++) = d;
		}
	private:
		GCA_vector& v;
		int m_counter;
	};

	inline std::ostream& operator<<(std::ostream& out, const GCA_vector& v) {
		out << v.m_data.transpose();
		return out;
	}
}