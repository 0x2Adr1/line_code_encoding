project('line_code_encoding',
        'cpp',
        default_options : [
            'cpp_std=c++17',
            'b_coverage=true',
            'b_lundef=false',
            'b_sanitize=address',
        ]
)

fmt_dep = dependency('fmt')

src_8b10b = files([
    'src/8b10b.cpp',
    'src/8b10b.hpp',
])

lib_8b10b = both_libraries(
    '8b10b',
    src_8b10b,
    dependencies: [ fmt_dep ],
)

lib_8b10b_dep = declare_dependency(link_with : lib_8b10b)

# The test variant of lib_8b10b adds 'src' to the include_directories so that the tests have access to private headers
lib_8b10b_test_dep = declare_dependency(
    link_with : lib_8b10b,
    include_directories : 'src'
)

test_consecutive_bits = executable(
    'test_consecutive_bits',
    [ 'test/consecutive_bits.cpp', ],
    dependencies : [ lib_8b10b_test_dep ],
)

test_count_zeros_ones = executable(
    'test_count_zeros_ones',
    [ 'test/count_zeros_ones.cpp' ],
    dependencies : [ lib_8b10b_test_dep ],
)

test('consecutive_bits', test_consecutive_bits)
test('consecutive_bits', test_count_zeros_ones)
