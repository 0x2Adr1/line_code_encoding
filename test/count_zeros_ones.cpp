#include "8b10b.hpp"

#include <cassert>

int main()
{
    assert(!check_count_zeros_ones(0));
    assert(check_count_zeros_ones(0b1010101010));
    assert(check_count_zeros_ones(0b1111100000));
    assert(check_count_zeros_ones(0b0111100000));
    assert(!check_count_zeros_ones(0b0011100000));

    return 0;
}
