#include <catch.hpp>
#include <range/v3/all.hpp>
#include <vector>
#include <iostream>

TEST_CASE("distinct", "[set operations]")
{
    std::vector<int> numbers{3, 1, 2, 3, 3, 4, 3, 5, 6};

    using ranges::action::unique;
    using ranges::action::sort;

    numbers |= sort | unique;

    using ranges::equal;

    ranges::copy(numbers, ranges::ostream_iterator<int>(std::cout, "\n")); 
    REQUIRE(equal(numbers, std::vector<int>{1, 2, 3, 4, 5, 6}));
}

TEST_CASE("set_difference", "[set operations]")
{
    std::vector<int> v1{1, 2, 3, 4};
    std::vector<int> v2{3, 4, 5};

    using ranges::view::set_difference;

    auto v = set_difference(v1, v2);

    using ranges::equal;
    REQUIRE(equal(v, std::vector<int>{1, 2}));
}

TEST_CASE("set_symmetric_difference", "[set operations]")
{
    std::vector<int> v1{1, 2, 3, 4};
    std::vector<int> v2{3, 4, 5};

    using ranges::view::set_symmetric_difference;

    auto v = set_symmetric_difference(v1, v2);

    using ranges::equal;
    REQUIRE(equal(v, std::vector<int>{1, 2, 5}));    
}

TEST_CASE("set_intersection", "[set operations]")
{
    std::vector<int> v1{1, 2, 3, 4};
    std::vector<int> v2{3, 4, 5};

    using ranges::view::set_intersection;

    auto v = set_intersection(v1, v2);

    using ranges::equal;
    REQUIRE(equal(v, std::vector<int>{3, 4}));
}

TEST_CASE("set_union", "[set operations]")
{
    std::vector<int> v1{1, 2, 3, 4};
    std::vector<int> v2{3, 4, 5};

    using ranges::view::set_union;

    auto v = set_union(v1, v2);

    using ranges::equal;
    REQUIRE(equal(v, std::vector<int>{1, 2, 3, 4, 5}));
}

// TEST_CASE("elegant output", "[misc]")
// {
//     std::vector<int> v{1, 2, 3, 4};
//     std::cout << ranges::view::transform(v, ranges::view::all) << std::endl;
// }
