#include "catch.hpp"
#include "PalindromeFinder.hpp"

TEST_CASE( "Test allUnique method", "[PalindromeFinder]" )
{
    INFO("Hint: Check if a given phrase/sentence contains duplicated word(s) in it. The string is case in-sensitive!");
    PalindromeFinder f;

    REQUIRE(f.allUnique("Hello world"));
    REQUIRE(f.allUnique("1Hel3lo wo13!rld"));
    REQUIRE_FALSE(f.allUnique("12321 12321"));
    REQUIRE_FALSE(f.allUnique("12321 312"));
    REQUIRE_FALSE(f.allUnique("HELLO hello"));
    REQUIRE_FALSE(f.allUnique("HELLO124 78643782hello"));
    REQUIRE_FALSE(f.allUnique("Wow 2021 Wow!!! 2022"));
}

TEST_CASE("Test processString", "[PalindromeFinder]") {
    PalindromeFinder f;
    REQUIRE(f.processString("PROcEsS") == "process");
    REQUIRE(f.processString("PR0c3s5") == "prcs");
    REQUIRE(f.processString("Hello world") == "helloworld");
    REQUIRE(f.processString("213_! &$&#@^").empty());
}

TEST_CASE("Test isPalindrome", "[PalindromeFinder]") {
    PalindromeFinder f;
    REQUIRE(f.isPalindrome(""));    // Empty string
    REQUIRE(f.isPalindrome("a"));   // Single character string
    REQUIRE(f.isPalindrome("212738"));  // Empty string after processing

    REQUIRE(f.isPalindrome("Taco cat"));
    REQUIRE(f.isPalindrome("ABBA"));
    REQUIRE_FALSE(f.isPalindrome("ABAB"));
    REQUIRE(f.isPalindrome("he3l1l1o0 olleh"));
    REQUIRE(f.isPalindrome("ABABA"));
    REQUIRE(f.isPalindrome("'Was it a car or a cat I saw?'"));
    REQUIRE(f.isPalindrome("SAIPPUAKIVIKAUPPIAS"));
    REQUIRE(f.isPalindrome("Xyz, sis, zyx,"));
    REQUIRE(f.isPalindrome("Amore, Roma!"));
}

TEST_CASE("test checkPalindrome", "[PalindromeFinder]") {
    PalindromeFinder f;
    REQUIRE(f.checkPalindrome("Taco cat"));
    REQUIRE(f.checkPalindrome("ABBA"));
    REQUIRE_FALSE(f.checkPalindrome("ABAB"));
    REQUIRE(f.checkPalindrome("he3l1l1o0 olleh"));
    REQUIRE(f.checkPalindrome("ABABA"));
    REQUIRE(f.checkPalindrome("'Was it a car or a cat I saw?'"));
    REQUIRE(f.checkPalindrome("SAIPPUAKIVIKAUPPIAS"));
    REQUIRE(f.checkPalindrome("Xyz, sis, zyx,"));
    REQUIRE(f.checkPalindrome("Amore, Roma!"));
}

TEST_CASE("Test printResult", "[PalindromeFinder]") {
    PalindromeFinder f;
    REQUIRE(f.printResult("string", "string") == "\"string\" string");
}