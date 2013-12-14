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

		GCA_scalar& operator^(const GCA_scalar& other);
		GCA_antiquadvector operator~();

		std::ostream& operator<<(std::ostream& out);
		GCA_scalar& operator<<(double s);

	};
	
}