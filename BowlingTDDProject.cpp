#include "catch/catch.hpp"
#include "BowlingGame.h"

TEST_CASE("Simple_once") {
    BowlingGame bg;
    bg.roll(4);
    REQUIRE( bg.getScore() == 4);
}
TEST_CASE("Simple_round") {
    BowlingGame bg;
    bg.roll(4);
    bg.roll(5);
    REQUIRE( bg.getScore() == 9);
}
TEST_CASE("Two rounds") {
    BowlingGame bg;
    bg.roll(4);
    bg.roll(5);
    bg.roll(4);
    bg.roll(5);
    REQUIRE( bg.getScore() == 18);
}
TEST_CASE("Strike") {
    BowlingGame bg;
    bg.roll(10);
    REQUIRE( bg.getScore() == 10);
}
TEST_CASE("Spare") {
    BowlingGame bg;
    bg.roll(5);
    bg.roll(5);
    REQUIRE( bg.getScore() == 10);
}
TEST_CASE("Spare boost") {
    BowlingGame bg;
    bg.roll(5);
    bg.roll(5);
    bg.roll(5);
    bg.roll(1);
    REQUIRE( bg.getScore() == 21);
}
TEST_CASE("Strike boost") {
    BowlingGame bg;
    bg.roll(10);
    bg.roll(5);
    bg.roll(5);
    REQUIRE( bg.getScore() == 30);
}
TEST_CASE("Strike full boost") {
    BowlingGame bg;
    bg.roll(10);
    bg.roll(10);
    bg.roll(10);
    bg.roll(0);
    bg.roll(0);
    REQUIRE( bg.getScore() == 60);
}
TEST_CASE("Strike full boost 10 rounds") {
    BowlingGame bg;
    for (int i=0;i<12;i++)
    {
        bg.roll(10);
    }
    REQUIRE( bg.getScore() == 300);
}
TEST_CASE("10x10 + 2 + 8") {
    BowlingGame bg;
    for (int i=0;i<10;i++)
    {
        bg.roll(10);
    }
    bg.roll(2);
    bg.roll(8);
    REQUIRE( bg.getScore() == 282);
}
TEST_CASE("11x10 + 0") {
    BowlingGame bg;
    for (int i=0;i<11;i++)
    {
        bg.roll(10);
    }
    bg.roll(0);
    REQUIRE( bg.getScore() == 290);
}
TEST_CASE("10x10 + 0 + 0") {
    BowlingGame bg;
    for (int i=0;i<10;i++)
    {
        bg.roll(10);
    }
    bg.roll(0);
    bg.roll(0);
    REQUIRE( bg.getScore() == 270);
}
TEST_CASE("9x10 + 8 + 2 + 1") {
    BowlingGame bg;
    for (int i=0;i<9;i++)
    {
        bg.roll(10);
    }
    bg.roll(8);
    bg.roll(2);
    bg.roll(1);
    REQUIRE( bg.getScore() == 269);
}