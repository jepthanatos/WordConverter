//==============================================================================
// Name        : FileManager.cpp
// Author      : Jorge
// Copyright   : https://creativecommons.org/licenses/by/4.0/
// Description : Manager of the database files.
//==============================================================================

#include "FileManager.h"

// Local includes
#include "LogManager.h"
#include "Converter.h"

//==============================================================================
/* Manager */
//==============================================================================

namespace wordconverter
{
    /*--------------------------------------------------------------------------
     * Constructor.
     */
    FileManager::FileManager()
    {
        Manager::setType("FileManager");
    }

    /*--------------------------------------------------------------------------
     * Get the one and only instance of the FileManager.
     */
    FileManager &FileManager::getInstance()
    {
        static FileManager instance;
        return instance;
    }

    /*--------------------------------------------------------------------------
     * Start up the FileManager (open files).
     */
    void FileManager::startUp(const std::string &input, const std::string &output)
    {
        // Open the input file.
        try
        {
            inputFile.open(input);
            started = true;
        }
        catch (std::ofstream::failure e)
        {
            LogManager::getInstance().writeLog(E_LEVEL::DEBUG, "Error opening the input file");
            LogManager::getInstance().writeLog(E_LEVEL::DEBUG, e.what());
            std::cerr << e.what() << std::endl;
        }

        // Open the output file.
        if (output != "")
        {
            try
            {
                outputFile.open(output);
            }
            catch (std::ofstream::failure e)
            {
                LogManager::getInstance().writeLog(E_LEVEL::DEBUG, "Error opening the output file");
                LogManager::getInstance().writeLog(E_LEVEL::DEBUG, e.what());
                std::cerr << e.what() << std::endl;
            }
        }
    }

    /*--------------------------------------------------------------------------
     * Shut down the FileManager (close files).
     */
    void FileManager::shutDown()
    {
        if (inputFile.is_open())
            inputFile.close();
        if (outputFile.is_open())
            outputFile.close();
    }

    /*--------------------------------------------------------------------------
     * Function to convert a file with written numbers to digital numbers.
     * If output file is defined the result will be stored there.
     */
    void FileManager::convertFile()
    {
        std::string line;
        std::string result;

        while (std::getline(inputFile, line))
        {
            result = Converter::getInstance().convertToNumber(line);
            std::cout << result << std::endl;
            if (outputFile.is_open())
            {
                outputFile << result << std::endl;
            }
        }
    }
}
