#include <gtest/gtest.h>

#include "../src/Converter.h"

// Declaring this map used in one test.
std::map<std::string, int> mapWords =
    {
        {"zero", 0},
        {"one", 1},
        {"two", 2},
        {"three", 3},
        {"four", 4},
        {"five", 5},
        {"six", 6},
        {"seven", 7},
        {"eight", 8},
        {"nine", 9},
        {"ten", 10},
        {"eleven", 11},
        {"twelve", 12},
        {"thirteen", 13},
        {"fourteen", 14},
        {"fifteen", 15},
        {"sixteen", 16},
        {"seventeen", 17},
        {"eighteen", 18},
        {"nineteen", 19},
        {"twenty", 20},
        {"thirty", 30},
        {"forty", 40},
        {"fifty", 50},
        {"sixty", 60},
        {"seventy", 70},
        {"eighty", 80},
        {"ninety", 90}
    };

using namespace wordconverter;

TEST(TestConverter, convertToNumber)
{
    for (auto word : mapWords)
    {
        EXPECT_EQ(std::to_string(word.second)+".", Converter::getInstance().convertToNumber(word.first));
    }
}

TEST(TestConverter, maxNumberInt)
{
    // Max 32 bits signed value 2,147,483,647
    std::string str{
        "two billion one hundred forty-seven million four hundred eighty-three thousand six hundred forty-seven."};
    std::string output = "2147483647.";
    EXPECT_EQ(output, Converter::getInstance().convertToNumber(str));
}

TEST(TestConverter, maxNumberUnsignedInt)
{
    // Max 32 bits unsigned value 4,294,967,295
    std::string str{
        "four billion two hundred ninety-four million nine hundred sixty-seven thousand two hundred ninety-five."};
    std::string output = "4294967295.";
    EXPECT_EQ(output, Converter::getInstance().convertToNumber(str));
}

TEST(TestConverter, mixedExample)
{
    // Max 32 bits unsigned value 4,294,967,295
    std::string str{"I have one hundred apples."};
    std::string output = "I have 100 apples.";
    EXPECT_EQ(output, Converter::getInstance().convertToNumber(str));
}

TEST(TestConverter, mixedBlankSpaces)
{
    // Max 32 bits unsigned value 4,294,967,295
    std::string str{"I have one hundred apples       and one dog     ."};
    std::string output = "I have 100 apples and 1 dog.";
    EXPECT_EQ(output, Converter::getInstance().convertToNumber(str));
}
