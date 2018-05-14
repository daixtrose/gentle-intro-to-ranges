#include <catch.hpp>
#include <range/v3/all.hpp>
#include <vector>
#include <iostream>

TEST_CASE("skip", "[set operations]")
{
    std::vector<int> numbers{1, 2, 3, 4, 5, 6};

    using ranges::view::drop;
    // 'skip' is called 'drop' here
    auto result = numbers | drop(3);

    using ranges::equal;
    REQUIRE(equal(result, std::vector<int>{4, 5, 6}));
}

TEST_CASE("skip_n", "[set operations]")
{
    std::vector<int> numbers{1, 2, 3, 4, 5, 6};

    using ranges::view::drop_exactly;
    auto result = numbers | drop_exactly(3);

    using ranges::equal;
    REQUIRE(equal(result, std::vector<int>{4, 5, 6}));
}

TEST_CASE("skip_while", "[set operations]")
{
    std::vector<int> numbers{1, 2, 3, 4, 5, 6};

    using ranges::view::drop_while;
    auto result = numbers | drop_while([](int i) { return i < 4; });

    using ranges::equal;
    REQUIRE(equal(result, std::vector<int>{4, 5, 6}));
}


TEST_CASE("take", "[set operations]")
{
    std::vector<int> numbers{1, 2, 3, 4, 5, 6};

    using ranges::view::take;
    auto result = numbers | take(3);

    using ranges::equal;
    REQUIRE(equal(result, std::vector<int>{1, 2, 3}));
}

TEST_CASE("take_n", "[set operations]")
{
    std::vector<int> numbers{1, 2, 3, 4, 5, 6};

    using ranges::view::take_exactly;
    auto result = numbers | take_exactly(3);

    using ranges::equal;
    REQUIRE(equal(result, std::vector<int>{1, 2, 3}));
}

TEST_CASE("take_while", "[set operations]")
{
    std::vector<int> numbers{1, 2, 3, 4, 5, 6};

    using ranges::view::take_while;
    auto result = numbers | take_while([](int i) { return i < 4; });

    using ranges::equal;
    REQUIRE(equal(result, std::vector<int>{1, 2, 3}));
}
