#include "lib/math/prime.h"
#include "catch.hpp"

using namespace Trigger;

TEST_CASE("Checking if number is prime", "[isprime]")
{
    REQUIRE(isprime(1) == false);
    REQUIRE(isprime(2) == true);
    REQUIRE(isprime(13) == true);
    REQUIRE(isprime(1031) == true);
}

// TEST_CASE("Finding prime factors", "[primefactors]")
// {
//     REQUIRE(primefactors(450) == 2335);
//     REQUIRE(primefactors(84) == 2237);
// }

// TEST_CASE("Finding prime factors", "[primefactors]")
// {
//     REQUIRE(primefactors(450) == 2335);
//     REQUIRE(primefactors(84) == 2237);
// }
