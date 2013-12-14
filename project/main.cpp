#include <iostream>
#include <grassmannCayley.hpp>

int main(void){
	gca::GCA_scalar a(1.0);
	std::cout<< a << std::endl;
	a = 3.0;
	std::cout<< a << std::endl;
	//gca::GCA_vector a(1.0,2.0,3.0,1.0);
	gca::GCA_vector b;
	b << -1.0, -3.0, 2.0, 1.0;
	std::cout << b << std::endl;
	b *= 3.0;
	std::cout << b << std::endl;
	/*gca::GCA_bivector l = a^b;

	std::cout << "l : " << l << std::endl;
	gca::GCA_vector x1(2.0,-1.0,-1.0,1.0);
	gca::GCA_vector x2(1.0,-1.0,1.0,1.0);
	gca::GCA_vector x3(-1.0,-1.0,-2.0,1.0);
	gca::GCA_trivector d = x1^x2^x3;

	std::cout << "intersection : " << ~d^~l << std::endl;*/
	return 0;
}