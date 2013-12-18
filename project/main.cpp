#include <iostream>
#include <grassmannCayley.hpp>
#include <vision.hpp>

int main(void){
	gca::Visualiseur visu(800,600);
	gca::GCA_vector a(1.0,2.0,3.0,1.0);
	gca::GCA_vector b;
	b << -1.0, -3.0, 2.0, 1.0;
	std::cout << b << std::endl;
	gca::GCA_bivector l = a^b;

	std::cout << "l : " << l << std::endl;
	gca::GCA_vector x2(1.0,-1.0,1.0,1.0);
	gca::GCA_vector x1(2.0,-1.0,-1.0,1.0);
	auto l2 = x1^l^x2;
	std::cout << l2 << std::endl;
	
	gca::GCA_vector x3(-1.0,-1.0,-2.0,1.0);
	gca::GCA_trivector d = x1^x2^x3;
	std::cout << d << std::endl;
	/*std::cout << "intersection : " << ~d^~l << std::endl;*/

	visu.addVector(a);
	visu.addVector(b);
	visu.addVector(x1);
	visu.addVector(x2);
	visu.addVector(x3);
	visu.addBiVector(l);
	visu.addTriVector(d);
	visu.render();
	return 0;
}