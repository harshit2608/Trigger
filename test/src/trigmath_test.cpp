#include "lib/math/trigmath.h"
#include "catch.hpp"

using namespace Trigger;

TEST_CASE("Number of digits are computed", "[numofdigits]")
{
    REQUIRE(numofdigits(1) == 1);
    REQUIRE(numofdigits(194354) == 6);
    REQUIRE(numofdigits(5.0) == 1);
}

TEST_CASE("Factorial computed", "[factorial]")
{
    REQUIRE(factorial(0) == 1);
    REQUIRE(factorial(1) == 1);
    REQUIRE(factorial(5) == 120);
    REQUIRE(factorial(10) == 3628800);
    REQUIRE(factorial(171) == 0);
}
