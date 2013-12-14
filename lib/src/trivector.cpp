namespace gca {
	
	GCA_quadvector GCA_vector::operator^(const GCA_vector& other){
		GCA_quadvector quadv;
		quadv.set(Base::e1234, get(e123)*other.get(e4)+get(e124)*other.get(e3)+get(e134)*other.get(e2)+get(e234)*other.get(e1));
		return quadv;
	}
}