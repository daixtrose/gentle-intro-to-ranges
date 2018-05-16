#include <catch.hpp>
#include <range/v3/all.hpp>
#include <vector>
#include <list>
#include <iostream>

TEST_CASE("at", "[element access]")
{
    std::vector<int> vi{1,2,3,4};
    
    CHECK(ranges::index(vi, 0) == 1);
    CHECK(ranges::index(vi, 1) == 2);
    CHECK(ranges::index(vi, 2) == 3);
    CHECK(ranges::index(vi, 3) == 4);
    
    CHECK(ranges::at(vi, 0) == 1);
    CHECK(ranges::at(vi, 1) == 2);
    CHECK(ranges::at(vi, 2) == 3);
    CHECK(ranges::at(vi, 3) == 4);

    std::list<int> li{1,2,3,4};   
    auto rng = li | ranges::view::all;

    // Does not compile if random access iterator not available
    // CHECK(ranges::at(li, 0) == 1);
    // CHECK(ranges::at(li, 1) == 2);
    // CHECK(ranges::at(li, 2) == 3);
    // CHECK(ranges::at(li, 3) == 4);
}