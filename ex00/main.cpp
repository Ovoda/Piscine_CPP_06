# include <iostream>
# include <string>
# include <math.h>
# include <cmath>


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
	if (!isascii(c)
		|| c < std::numeric_limits<char>::min()
		|| c > std::numeric_limits<char>::max()
		|| std::isnan(d))
		std::cout << "impossible" << std::endl;
	else if (!isprint(c))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << c << "'" << std::endl;

	// Integer cast
	std::cout << "int : ";
	i = static_cast<int>(d);
	if (static_cast<long long>(d) > std::numeric_limits<int>::max()
		 || static_cast<long long>(d) < std::numeric_limits<int>::min())
		std::cout << "impossible" << std::endl;
	else
		std::cout << i << std::endl;

	// Float cast
	std::cout << "float : ";
	f = static_cast<float>(d);
	if (fmod(f, 1) == 0)
		std::cout << f << ".0f" << std::endl;
	else
		std::cout << f << "f" << std::endl;
	
	// Double output
	std::cout << "double : ";
	if (fmod(d, 1) == 0)
		std::cout << d << ".0" << std::endl;
	else
		std::cout << d << std::endl;
	return (0);
}