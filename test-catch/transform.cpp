#include <catch.hpp>
#include <vector>
#include <range/v3/all.hpp>

SCENARIO("transform yields data conversion", "[basic stuff]")
{
    GIVEN("a vector of integers")
    {
        std::vector<int> foo{1, 2, 3, 4};
        
        WHEN("transform  is called")
        {
            using ranges::view::transform; 
            
            auto bar =
                foo | transform([](auto const v) { return 2 * v; });
            
            THEN("the result is a vector of double values")
            {
                // use equal to check the values
                using ranges::equal;
                REQUIRE(equal(bar, std::vector<int>{2, 4, 6, 8}));   
                
                // or test all one-o-one
                REQUIRE(bar[0] == 2);
                REQUIRE(bar[1] == 4);
                REQUIRE(bar[2] == 6);
                REQUIRE(bar[3] == 8);
            }
        }
    }
}
