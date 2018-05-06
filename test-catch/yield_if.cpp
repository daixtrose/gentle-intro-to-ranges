#include <catch.hpp>
#include <range/v3/all.hpp>
#include <vector>
#include <iostream>

TEST_CASE("yield_if on sequence", "[filtering]")
{
    std::vector<int> numbers{1, 2, 3, 4, 5, 6};

    using ranges::view::for_each;
    using ranges::yield_if;

    auto is_odd = [](int i) { 
        // std::cout << "checking if " << i << " is odd.\n";
        return i % 2 != 0; 
        };

    auto odd_numbers = for_each(numbers, [=](int i) { 
        return yield_if(is_odd(i), i);
        });

    using ranges::equal;
    ranges::copy(odd_numbers, ranges::ostream_iterator<int>(std::cout, "\n")); 
    REQUIRE(equal(odd_numbers, std::vector<int>{1, 3, 5}));
}