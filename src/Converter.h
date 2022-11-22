//==============================================================================
// Name        : Converter.h
// Author      : Jorge
// Copyright   : https://creativecommons.org/licenses/by/4.0/
// Description : Class to define a Converter.
//==============================================================================

#ifndef __Converter_H__
#define __Converter_H__

// System includes
#include <string>
#include <map>

//==============================================================================
/* Converter */
//==============================================================================

/*------------------------------------------------------------------------------
 * Class to define a Converter.
 */
namespace wordconverter
{
    /*
     * A Converter translates numbers as words into digital numbers.
     */
    class Converter
    {
    private:
        // Maps used in "convertToNumber" function.
        std::map<std::string, int> mapWords;
        std::map<std::string, unsigned int> multipliers;

    public:
        // Default constructor.
        Converter();

        // Destroy Converter.
        virtual ~Converter(){};

        // Converts the numbers as words of a sentence into digital numbers.
        std::string convertToNumber(std::string str);
    };
}
//------------------------------------------------------------------------------
#endif /* __Converter_H__ */
