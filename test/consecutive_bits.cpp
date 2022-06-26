#include "8b10b.hpp"

#include <cassert>

int main()
{
    assert(!check_consecutive_bits(0b1111110000));
    assert(check_consecutive_bits(0b1111100000));
    assert(!check_consecutive_bits(0));

    return 0;
}
