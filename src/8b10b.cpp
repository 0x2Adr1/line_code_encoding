#include <cstdio>
#include <cstdlib>
#include <limits>

#include <fmt/core.h>

#include <cassert>

#include "8b10b.hpp"

/*
 * Constraints:
 * - Maximum of five same consecutive bits
 * - The difference between the count of zeros and ones is not more than two
 */

bool check_consecutive_bits(Symbol symbol)
{
    int i = 0;

    while (i < 10) {
        int consecutive = 0;

        const uint8_t bit = symbol & 1;

        while (i < 10 && bit == (symbol & 1)) {
            consecutive++;

            i++;
            symbol >>= 1;
        }

        if (consecutive > 5) {
            return false;
        }
    }

    return true;
}

bool check_count_zeros_ones(Symbol symbol)
{
    int one_count = 0;
    int zero_count = 0;

    for (int i = 0; i < 10; i++) {
        if (((symbol >> i) & 1) == 0) {
            zero_count++;
        } else {
            one_count++;
        }
    }

    return std::abs(one_count - zero_count) <= 2;
}

static bool backtracking(const uint8_t byte,
                         mapping_8b_to_10b_t& map,
                         mapping_10b_to_8b_t& map_reverse,
                         Symbol symbol = 0,
                         int depth = 0)
{
    if (depth == 9) {
        if (!check_consecutive_bits(symbol)) {
            return false;
        }

        if (!check_count_zeros_ones(symbol)) {
            return false;
        }

        if (map_reverse.count(symbol) != 0) {
            return false;
        }

        map[byte] = symbol;
        map_reverse[symbol] = byte;

        return true;
    }

    // Add a one to the symbol value
    if (backtracking(byte, map, map_reverse, symbol | (1 << (depth + 1)), depth + 1)) {
        return true;
    }

    // Add a zero to the symbol value
    if (backtracking(byte, map, map_reverse, symbol, depth + 1)) {
        return true;
    }

    return false;
}

mapping_8b_to_10b_t map_8b10b_create()
{
    mapping_8b_to_10b_t map;
    mapping_10b_to_8b_t map_reverse;

    for (size_t i = 0; i <= 0xFF; i++) {
        const uint8_t byte = i;

        const bool ret = backtracking(byte, map, map_reverse);

        if (!ret) {
            printf("error for %zu\n", i);
            return {};
        }
    }

    assert(map.size() == 256);

    return map;
}

void print_mapping(const mapping_8b_to_10b_t& map)
{
    for (const auto [k, v] : map) {
        fmt::print("{:02X} -> {:010b}\n", k, v);
    }
}
