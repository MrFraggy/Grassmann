#pragma once
#include <vector>
#include <vector.hpp>
#include <bivector.hpp>
#include <trivector.hpp>

namespace gca {

	void draw(const GCA_vector& point);
	void draw(const GCA_bivector& droite);
	void draw(const GCA_trivector& plan);

	class Visualiseur{
	private:
		std::vector<GCA_vector> vectors;
		std::vector<GCA_bivector> bivectors;
		std::vector<GCA_trivector> trivectors;
		
	public:
		Visualiseur(int width, int height);
		int render();
		void addVector(const GCA_vector& v);
		void addBiVector(const GCA_bivector& b);
		void addTriVector(const GCA_trivector& t);
	};

	
}