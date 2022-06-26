#pragma once

#include <cstdint>
#include <unordered_map>

using Symbol = uint16_t;

using mapping_8b_to_10b_t = std::unordered_map<uint8_t, Symbol>;
using mapping_10b_to_8b_t = std::unordered_map<Symbol, uint8_t>;

bool check_consecutive_bits(Symbol symbol);
bool check_count_zeros_ones(Symbol symbol);
