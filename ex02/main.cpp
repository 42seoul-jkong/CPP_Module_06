/* Any copyright is dedicated to the Public Domain.
 * https://creativecommons.org/publicdomain/zero/1.0/ */

#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"
#include <iostream>
#include <random>

std::mt19937* g_rand;

Base* generate()
{
    switch ((*g_rand)() & 3)
    {
    case 0:
        std::cout << "Generated A" << std::endl;
        return new A();
    case 1:
        std::cout << "Generated B" << std::endl;
        return new B();
    case 2:
        std::cout << "Generated C" << std::endl;
        return new C();
    default:
        std::cout << "Retry . . ." << std::endl;
        return generate();
    }
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
    {
        std::cout << "A" << std::endl;
    }
    else if (dynamic_cast<B*>(p))
    {
        std::cout << "B" << std::endl;
    }
    else if (dynamic_cast<C*>(p))
    {
        std::cout << "C" << std::endl;
    }
    else
    {
        // No-OP: Not Found
    }
}

void identify(Base& p)
{
    try
    {
        (void)&dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
    }
    catch (const std::exception& e)
    {
        try
        {
            (void)&dynamic_cast<B&>(p);
            std::cout << "B" << std::endl;
        }
        catch (const std::exception& e)
        {
            try
            {
                (void)&dynamic_cast<C&>(p);
                std::cout << "C" << std::endl;
            }
            catch (const std::exception& e)
            {
                // No-OP: Not Found
            }
        }
    }
}

int main()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    g_rand = &gen;

    Base* p = generate();
    std::cout << "Identify pointer: ";
    identify(p);
    std::cout << "Identify reference: ";
    identify(*p);

    return 0;
}
