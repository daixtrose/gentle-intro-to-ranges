#include <catch.hpp>

#include <range/v3/all.hpp>

#include <vector>
#include <list>
#include <type_traits>

TEST_CASE("conversion to vector", "[conversion]")
{
    auto timesTwo = [](auto const v) { return 2 * v; };
    auto plusTen = [](auto const v) { return v + 10; };

    std::vector<int> foo{1, 2, 3, 4};

    using ranges::view::transform;
    using ranges::to_vector;
    
    auto bar =
        foo 
        | transform(timesTwo) 
        | transform(plusTen) 
        // Here we go!
        | to_vector;

    // compile-time test 
    static_assert(std::is_same_v<decltype(bar), std::vector<int>>);

    using ranges::equal;
    REQUIRE(equal(bar, std::vector<int>{12, 14, 16, 18}));
}

TEST_CASE("conversion to list", "[conversion]")
{
    std::vector<int> foo{1, 2, 3, 4};

    using ranges::to_;
    auto l = foo | to_<std::list>();

    static_assert(std::is_same_v<decltype(l), std::list<int>>);

    using ranges::equal;
    REQUIRE(equal(l, foo));
}

TEST_CASE("conversion to vector<long>", "[conversion]")
{
    std::vector<int> foo{1, 2, 3, 4};
    
    using ranges::to_;
    auto v = foo | to_<std::vector<long>>();
    
    static_assert(std::is_same_v<decltype(v), std::vector<long>>);

    using ranges::equal;
    REQUIRE(equal(v, std::vector<long>{1L, 2L, 3L, 4L}));
}

