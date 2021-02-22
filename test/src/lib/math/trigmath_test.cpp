#include "lib/math/trigmath.h"
#include "catch.hpp"

using namespace Trigger;

TEST_CASE("Number of digits are computed", "[numofdigits]")
{
    REQUIRE(numofdigits(1) == 1);
    REQUIRE(numofdigits(194354) == 6);
    REQUIRE(numofdigits(5.0) == 1);
}

TEST_CASE("Palindrome ", "[ispalindrome]")
{
    REQUIRE(ispalindrome(1) == true);
    REQUIRE(ispalindrome(0) == true);
    REQUIRE(ispalindrome(123321) == true);
    REQUIRE(ispalindrome(781) == false);
}

TEST_CASE("Factorial computed", "[factorial]")
{
    REQUIRE(factorial(0) == 1);
    REQUIRE(factorial(1) == 1);
    REQUIRE(factorial(5) == 120);
    REQUIRE(factorial(10) == 3628800);
    REQUIRE(factorial(171) == 0);
}

TEST_CASE("Trailing zeros in factorial", "[factorialtrailingzeros]")
{
    REQUIRE(factorialtrailingzeros(5) == 1);
    REQUIRE(factorialtrailingzeros(0) == 0);
    REQUIRE(factorialtrailingzeros(10) == 2);
    REQUIRE(factorialtrailingzeros(100) == 24);
    REQUIRE(factorialtrailingzeros(10000) == 2499);
}

TEST_CASE("GCD or HCF of two numbers", "[GCD]")
{
    REQUIRE(GCD(10, 15) == 5);
    REQUIRE(GCD(10, 1) == 1);
    REQUIRE(GCD(100, 200) == 100);
    REQUIRE(GCD(9, 81) == 9);
    REQUIRE(GCD(81, 9) == 9);
}

TEST_CASE("LCM of two numbers", "[LCM]")
{
    REQUIRE(LCM(4, 6) == 12);
    REQUIRE(LCM(12, 15) == 60);
    REQUIRE(LCM(3, 7) == 21);
}