namespace gca {
	
	GCA_trivector GCA_vector::operator^(const GCA_vector& other){
		GCA_trivector triv;
		triv.set(Base::e123, get(e12)*other.get(e1)+get(e13)*other.get(e2)+get(e23)*other.get(e1));
		triv.set(Base::e134, get(e12)*other.get(e4)+get(e14)*other.get(e2)+get(e14)*other.get(e1));
		triv.set(Base::e134, get(e13)*other.get(e4)+get(e14)*other.get(e3)+get(e34)*other.get(e1));
		triv.set(Base::e234, get(e23)*other.get(e4)+get(e14)*other.get(e3)+get(e34)*other.get(e2));
	}

}