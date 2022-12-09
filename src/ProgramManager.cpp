//==============================================================================
// Name        : ProgramManager.cpp
// Author      : Jorge
// Copyright   : https://creativecommons.org/licenses/by/4.0/
// Description : Manager of the program.
//==============================================================================

// System includes
#include <iostream>
#include <filesystem>
#include <vector>

// Local includes
#include "ProgramManager.h"
#include "LogManager.h"
#include "FileManager.h"

//==============================================================================
/* Manager */
//==============================================================================

namespace wordconverter
{
    /*--------------------------------------------------------------------------
     * Initialize the program by parsing the program arguments.
     */
    int ProgramManager::initialization(int argc, char *argv[])
    {
        // Define the usage string printed to console.
        std::string usage {
            "Usage is: WordConverter_run -i <input_file> [-o] [<output_file>"
        };

        // Construct a vector of arguments.
        const std::vector<std::string> args(argv + 1, argv + argc);

        // Check if the number of arguments is less than 2 or the first
        // argument is not "-i".
        if (argc < 2 || args.at(0) != "-i")
        {
            std::cout << usage << std::endl;
            return EXIT_FAILURE;
        }

        // Check if the input file exists and is a regular file.
        const std::string inputFile = args.at(1);
        if (!std::filesystem::exists(inputFile) ||
            std::filesystem::file_type::regular != std::filesystem::status(inputFile).type())
        {
            std::cout << usage << std::endl;
            std::cout << "Invalid input file: " << inputFile << std::endl;
            return EXIT_FAILURE;
        }

        FileManager::getInstance().initInputFile(inputFile);

        // If there are at least 4 arguments and the third argument is "-o",
        // use the fourth argument as the output file.
        if (args.size() >= 4 && args.at(2) == "-o")
        {
            FileManager::getInstance().initOutputFile(args.at(3));
        }

        return EXIT_SUCCESS;
    }

    /*--------------------------------------------------------------------------
     * Startup the program services.
     */
    void ProgramManager::startUp()
    {
        Manager::setType("ProgramManager");
        LogManager::getInstance().startUp();
        LogManager::getInstance().writeLog(Level::Debug, "Starting services...");
        FileManager::getInstance().startUp();
        started = LogManager::getInstance().isStarted() and
                  FileManager::getInstance().isStarted();
    }

    /*--------------------------------------------------------------------------
     * Shut down the program services.
     */
    void ProgramManager::shutDown()
    {
        FileManager::getInstance().shutDown();
        LogManager::getInstance().writeLog(Level::Debug, "Closing services...");
        LogManager::getInstance().shutDown();
    }

    /*--------------------------------------------------------------------------
     * Run program loop.
     */
    void ProgramManager::run()
    {
        LogManager::getInstance().writeLog(Level::Debug, "Starting program...");

        FileManager::getInstance().convertFile();

        LogManager::getInstance().writeLog(Level::Debug, "Ending program...");
    }
}
