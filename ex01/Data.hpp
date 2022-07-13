/* Any copyright is dedicated to the Public Domain.
 * https://creativecommons.org/publicdomain/zero/1.0/ */

#pragma once

#include <stdint.h>

struct Data
{
    int64_t rvalue;
    int32_t evalue1;
    int32_t evalue2;
    char svalue[16];
};

uintptr_t serialize(Data* ptr);
Data* deserialize(uintptr_t raw);
