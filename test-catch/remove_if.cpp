#include <catch.hpp>
#include <range/v3/all.hpp>
#include <vector>
#include <iostream>

TEST_CASE("remove_if on sequence", "[filtering]")
{
    std::vector<int> numbers{1, 2, 3, 4, 5, 6};

    using ranges::view::remove_if;
    using ranges::view::filter;
    using ranges::not_fn;

    auto is_odd = [](int i) { 
        std::cout << " checking if " << i << " is odd.\n";
        return i % 2 != 0; 
        };

    auto odd_numbers = numbers | filter(is_odd);
    auto odd_numbers_alt = numbers | remove_if(not_fn(is_odd));
    auto even_numbers = numbers | remove_if(is_odd);

    using ranges::equal;
    ranges::copy(odd_numbers, ranges::ostream_iterator<int>(std::cout, "\n")); 
    REQUIRE(equal(odd_numbers, std::vector<int>{1, 3, 5}));
    REQUIRE(equal(odd_numbers_alt, std::vector<int>{1, 3, 5}));
    REQUIRE(equal(even_numbers, std::vector<int>{2, 4, 6}));
    
}