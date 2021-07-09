#include <math.h>

#include <cmath>
#include <iostream>
#include <string>

bool is_only_digit(std::string const &str) {
    for (int i = 0; str[i]; i++)
        if (!isdigit(str[i]) && str[i] != '.' && str[i] != '-' && str[i] != 'f')
            return false;
    return true;
}

bool is_except(std::string const &str) {
    return (str == "nan" || str == "nanf" || str == "inf" || str == "-inf" ||
            str == "inff" || str == "-inff");
}

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "Please enter one and only argument" << std::endl;
        return (1);
    }
    std::string arg = std::string(argv[1]);
    char c;
    int i;
    float f;
    double d;

    if ((is_except(arg) || is_only_digit(arg)) &&
        !(arg.size() == 1 &&
          (arg[0] == 'f' || arg[0] == '.' || arg[0] == '-'))) {
        d = stod(arg);
        c = static_cast<char>(d);
        i = static_cast<int>(d);
        f = static_cast<float>(d);
    } else if (arg.length() == 1 && isprint(arg[0])) {
        c = static_cast<char>(arg[0]);
        i = static_cast<int>(c);
        f = static_cast<float>(c);
        d = static_cast<double>(c);
    } else {
        std::cout << "Impossible" << std::endl;
        return (1);
    }

    // Character cast
    std::cout << "char : ";
    if (!isascii(c) || c < std::numeric_limits<char>::min() ||
        c > std::numeric_limits<char>::max() || std::isnan(d))
        std::cout << "impossible" << std::endl;
    else if (!isprint(c))
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" << c << "'" << std::endl;

    // Integer cast
    std::cout << "int : ";
    if (static_cast<long long>(d) > std::numeric_limits<int>::max() ||
        static_cast<long long>(d) < std::numeric_limits<int>::min())
        std::cout << "impossible" << std::endl;
    else
        std::cout << i << std::endl;

    // Float cast
    std::cout << "float : ";
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