#include <catch.hpp>
#include <range/v3/all.hpp>
#include <vector>

TEST_CASE("composition", "[basic stuff]")
{
    auto timesTwo = [](auto const v) { return 2 * v; };
    auto plusTen = [](auto const v) { return v + 10; };

    std::vector<int> foo{1, 2, 3, 4};

    using ranges::view::transform;

    auto bar =
        foo | transform(timesTwo) | transform(plusTen);

    using ranges::equal;
    REQUIRE(equal(bar, std::vector<int>{12, 14, 16, 18}));
}
