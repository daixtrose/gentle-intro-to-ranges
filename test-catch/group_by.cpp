#include <catch.hpp>
#include <range/v3/all.hpp>
#include <string>
#include <vector>
#include <iostream>

struct Person {
    std::string firstname;
    std::string surname;
    int year;
};

std::ostream & operator<<(std::ostream & os, Person const & person)
{
    os << person.surname << ", " << person.firstname << " was born in " << person.year; 
    return os;
}

SCENARIO("group_by and join work well together", "[set operations]")
{
    GIVEN("a set of people")
    {
        std::vector<Person> people{
            { "Jared", "Kushner", 1981 },
            { "Melania", "Trump", 1970 },
            { "Donald", "Trump", 1946 },
            { "Ivana", "Trump", 1949 },
        };
        
        WHEN("group_by is called")
        {
            using ranges::view::group_by; 
            
            auto surname_is_equal = [](auto const & p1, auto const & p2) 
                { return p1.surname == p2.surname; };
            
            auto groups =
                people | group_by(surname_is_equal);
            
            THEN("the result is a nested structure")
            {
                for (auto const & group : groups)
                { 
                    std::cout << "-------\n";
                    ranges::copy(group, ranges::ostream_iterator<Person>(std::cout, "\n")); 
                }

                using ranges::view::transform;
                using ranges::view::all;
                using ranges::view::join;
                using ranges::sort;

                std::cout << "\n------------------------------------------------------------------------\n";
                std::cout << "--> joined:\n";    
                ranges::copy(join(groups), ranges::ostream_iterator<Person>(std::cout, "\n"));

                std::cout << "\n------------------------------------------------------------------------\n";
                std::cout << "--> sorted by age, then joined:\n";

                auto is_younger = [](auto const & p1, auto const & p2) { return p2.year < p1.year; };

                auto each_group_sorted_by_age = groups 
                    | transform([=](auto g) { sort(g, is_younger); return g; });     
                
    	        ranges::copy(join(each_group_sorted_by_age), ranges::ostream_iterator<Person>(std::cout, "\n"));

                std::cout << "\n------------------------------------------------------------------------\n";
                std::cout << "--> Eldest in every family:\n";

                auto eldest_in_each_group = 
                    groups 
                    | transform([=](auto const & g) {return ranges::max(g, is_younger); });     
                
    	        ranges::copy(eldest_in_each_group, 
                    ranges::ostream_iterator<Person>(std::cout, "\n"));

                // or TODO: testen!
                //std::cout << persons | view::transform(view::all) << std::endl;
            }
        }
    }
}
