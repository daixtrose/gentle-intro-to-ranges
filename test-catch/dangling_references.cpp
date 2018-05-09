#include <catch.hpp>
#include <range/v3/all.hpp>
#include <vector>
#include <iostream>

TEST_CASE("using get_unsafe", "[dangling references]")
{
    auto doub = [](int i) { return 2 * i; };
    auto is_six = [](int i) { return i == 6; };
    
    using ranges::view::ints;
    using ranges::view::transform;
    using ranges::find_if;

    auto e = find_if( ints(1) | transform(doub), is_six );
    REQUIRE(*e.get_unsafe() == 6);
}


TEST_CASE("avoiding unsafe", "[dangling references]")
{
    auto doub = [](int i) { return 2 * i; };
    auto is_six = [](int i) { return i == 6; };
    
    using ranges::view::ints;
    using ranges::view::transform;
    using ranges::find_if;

    auto values = ints(1) | transform(doub);
    auto e = find_if( values, is_six );
    
    REQUIRE(*e == 6);
}
