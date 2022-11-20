//==============================================================================
// Name        : Converter.cpp
// Author      : Jorge
// Copyright   : https://creativecommons.org/licenses/by/4.0/
// Description : Class to define an Converter.
//==============================================================================

#include "Converter.h"
#include "LogManager.h"

// System includes
#include <string>
#include <sstream>
#include <iterator>
#include <functional>

//==============================================================================
/* Converter */
//==============================================================================

namespace wordconverter
{
    /*--------------------------------------------------------------------------
     * Default constructor.
     */
    Converter::Converter()
    {
        mapWords =
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

        multipliers =
            {
                {"hundred", 100},
                {"thousand", 1000},
                {"million", 1000000},
                {"billion", 1000000000},
                // The next are not used, future improvement.
                {"trillion", 1000000000000},
                {"quadrillion", 1000000000000000},
                {"quintillion", 1000000000000000000}
            };
    }

    /*--------------------------------------------------------------------------
     * Get the singleton instance of the Converter.
     */
    Converter &Converter::getInstance()
    {
        static Converter instance;
        return instance;
    }

    /*--------------------------------------------------------------------------
     * Converts the numbers as words of a sentence into digital numbers.
     */
    std::string Converter::convertToNumber(std::string str)
    {
        LogManager::getInstance().writeLog(E_LEVEL::DEBUG, "Sentence to be converted: " + str);

        // String to be returned.
        std::string finalString;

        // Check if the sentence is empty and return an empty string.
        if (str.size() == 0)
            return finalString;

        // Replace in the sentence all the '-' by a blank space.
        std::replace(str.begin(), str.end(), '-', ' ');

        // Replace the last '.' by a blank space.
        std::replace(str.end() - 1, str.end(), '.', ' ');

        // Resulting number.
        unsigned int cookedNumber = 0;
        unsigned int finalNumber = 0;

        // Convert the incoming string to a vector.
        std::istringstream iss(str);
        std::vector<std::string> tokens;
        std::copy(std::istream_iterator<std::string>(iss),
                  std::istream_iterator<std::string>(),
                  std::back_inserter(tokens));

        // Flag to know if when you get a word the previous was a number.
        bool previousIsNumber = false;

        // Iterate over the sentence.
        for (auto &t : tokens)
        {
            if (multipliers.find(t) != multipliers.end())
            {
                if (multipliers.at(t) == 100)
                {
                    cookedNumber = cookedNumber * multipliers.at(t);
                }
                else
                {
                    finalNumber += cookedNumber * multipliers.at(t);
                    cookedNumber = 0;
                }
                previousIsNumber = true;
            }
            else
            {
                try
                {
                    cookedNumber += mapWords.at(t);
                    previousIsNumber = true;
                }
                catch (const std::out_of_range &oor)
                {
                    if (previousIsNumber)
                    {
                        finalNumber += cookedNumber;
                        finalString += std::to_string(finalNumber) + " " + t + " ";
                        previousIsNumber = false;
                        finalNumber = 0;
                        cookedNumber = 0;
                    }
                    else
                        finalString += t + " ";
                }
            }
        }

        finalNumber += cookedNumber;

        if (previousIsNumber)
            finalString += std::to_string(finalNumber);
        else
            finalString.erase(finalString.end() - 1, finalString.end());

        LogManager::getInstance().writeLog(E_LEVEL::DEBUG, "Result: " + finalString);

        return finalString + ".";
    }
}
