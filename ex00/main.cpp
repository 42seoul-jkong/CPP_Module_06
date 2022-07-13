/* Any copyright is dedicated to the Public Domain.
 * https://creativecommons.org/publicdomain/zero/1.0/ */

#include <cctype>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>

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

    char c = static_cast<char>(lVal);
    std::cout << "char: ";
    if (pBegin == pLongEnd || c != lVal)
    {
        std::cout << "impossible";
    }
    else if (std::isprint(c))
    {
        std::cout << "\'" << c << "\'";
    }
    else
    {
        std::cout << "Non displayable";
    }
    std::cout << std::endl;

    int i = static_cast<int>(lVal);
    std::cout << "int: ";
    if (pBegin == pLongEnd || i != lVal)
    {
        std::cout << "impossible";
    }
    else
    {
        std::cout << i;
    }
    std::cout << std::endl;

    float f = static_cast<float>(dVal);
    std::cout << "float: ";
    if (pBegin == pDblEnd)
    {
        std::cout << "impossible";
    }
    else
    {
        std::cout << f << "f";
    }
    std::cout << std::endl;

    std::cout << "double: ";
    if (pBegin == pDblEnd)
    {
        std::cout << "impossible";
    }
    else
    {
        std::cout << dVal;
    }
    std::cout << std::endl;

    return EXIT_SUCCESS;
}
