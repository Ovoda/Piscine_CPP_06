# include <iostream>
# include <string>


int main( int argc, char **argv )
{
	if (argc != 2)
	{
		std::cout << "Please enter one and only argument" << std::endl;
		return (1);
	}
	std::string arg = std::string(argv[1]);
	std::string::size_type sz;
	char	c;
	int		i;
	float	f;
	double	d;

	d = std::stod(arg, &sz);

	// Character cast
	c = static_cast<char>(d);
	std::cout << "char : ";
	if (!isascii(c))
		std::cout << "impossible" << std::endl;
	else if (!isprint(c))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << c << "'" << std::endl;

	// Integer cast
	i = static_cast<int>(d);
	if (d > std::numeric_limits<int>::max())
		std::cout << "Not possible" << std::endl;
	else
		std::cout << i << std::endl;

	// Float cast
	f = static_cast<float>(d);
	std::cout << std::showpoint << f << "f" << std::endl;
	
	// Double output
	std::cout << d << std::endl;
	return (0);
}