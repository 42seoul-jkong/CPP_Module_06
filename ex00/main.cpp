/* Any copyright is dedicated to the Public Domain.
 * https://creativecommons.org/publicdomain/zero/1.0/ */

#include <cctype>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <limits>

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        if (argc > 0)
        {
            std::cout << "usage: " << argv[0] << " <int, float or double literal in decimal notation>" << std::endl;
        }
        return EXIT_FAILURE;
    }

    char *pBegin = argv[1], *pDblEnd, *pLongEnd;
    double dVal = std::strtod(pBegin, &pDblEnd);
    long lVal = std::strtol(pBegin, &pLongEnd, 10);

    if (std::strcmp(pDblEnd, "f") == 0 || std::strcmp(pDblEnd, "F") == 0)
    {
        dVal = static_cast<double>(static_cast<float>(dVal));
    }
    else if (std::strlen(pDblEnd) != 0)
    {
        std::cout << "parse error near `" << pDblEnd << "'" << std::endl;
        return EXIT_FAILURE;
    }

    std::cout << std::fixed << std::setprecision(1);

    std::cout << "char: ";
    if (pBegin == pLongEnd || lVal < std::numeric_limits<char>::min() || lVal > std::numeric_limits<char>::max())
    {
        std::cout << "impossible";
    }
    else
    {
        char c = static_cast<char>(lVal);
        if (std::isprint(c))
        {
            std::cout << "\'" << c << "\'";
        }
        else
        {
            std::cout << "Non displayable";
        }
    }
    std::cout << std::endl;

    std::cout << "int: ";
    if (pBegin == pLongEnd || lVal < std::numeric_limits<int>::min() || lVal > std::numeric_limits<int>::max())
    {
        std::cout << "impossible";
    }
    else
    {
        std::cout << static_cast<int>(lVal);
    }
    std::cout << std::endl;

    std::cout << "float: ";
    std::cout << static_cast<float>(dVal) << "f";
    std::cout << std::endl;

    std::cout << "double: ";
    std::cout << dVal;
    std::cout << std::endl;

    return EXIT_SUCCESS;
}
