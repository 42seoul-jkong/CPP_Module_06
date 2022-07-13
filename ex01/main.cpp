/* Any copyright is dedicated to the Public Domain.
 * https://creativecommons.org/publicdomain/zero/1.0/ */

#include "Data.hpp"
#include <iostream>

int main()
{
    Data d = {0xBADC0FFEE0DDF00Dl, 0xBAADF00D, 0xBEEFCACE, "9016-8C--0FF1CE"};

    std::cout << std::hex;

    std::cout << d.rvalue << std::endl;
    std::cout << d.evalue1 << std::endl;
    std::cout << d.evalue2 << std::endl;
    std::cout << d.svalue << std::endl;
    std::cout << std::endl;

    Data* d_ptr = &d;
    std::cout << d_ptr << std::endl;
    std::cout << d_ptr->rvalue << std::endl;
    std::cout << d_ptr->evalue1 << std::endl;
    std::cout << d_ptr->evalue2 << std::endl;
    std::cout << d_ptr->svalue << std::endl;
    std::cout << std::endl;

    uintptr_t ptr = serialize(d_ptr);
    std::cout << ptr << std::endl;
    std::cout << std::endl;

    Data* e_ptr = deserialize(ptr);
    std::cout << e_ptr << std::endl;
    std::cout << e_ptr->rvalue << std::endl;
    std::cout << e_ptr->evalue1 << std::endl;
    std::cout << e_ptr->evalue2 << std::endl;
    std::cout << e_ptr->svalue << std::endl;
    std::cout << std::endl;

    return 0;
}
