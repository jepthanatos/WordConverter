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
     * Default constructor.
     */
    ProgramManager::ProgramManager()
    {
        Manager::setType("ProgramManager");
    }

    /*--------------------------------------------------------------------------
     * Get the singleton instance of the ProgramManager.
     */
    ProgramManager &ProgramManager::getInstance()
    {
        static ProgramManager instance;
        return instance;
    }

    /*--------------------------------------------------------------------------
     * Initialize the program by parsing the program arguments.
     */
    int ProgramManager::initialization(int argc, char *argv[])
    {
        // Define the usage string printed to console.
        std::string usage {
            "Usage is: WordConverter_run -i <input_file> [-o] [<output_file]"
        };

        // Check if the number of arguments include the input file, if not exit.
        if (argc < 2)
        {
            std::cout << usage << std::endl;
            return EXIT_FAILURE;
        }

        // Construct a vector of arguments.
        const std::vector<std::string_view> args(argv + 1, argv + argc);

        // If the first argument is not "-i" then exit.
        if (args.at(0) != "-i")
        {
            std::cout << usage << std::endl;
            return EXIT_FAILURE;
        }

        // Check if the input file exist, else exit.
        if (!std::filesystem::exists(args.at(1)))
        {
            std::cout << usage << std::endl;
            std::cout << "No such file: " + std::string(args.at(1)) << std::endl;
            return EXIT_FAILURE;
        }
        else
        {
            // Check if the file is a regular one (not a directory, etc).
            if (std::filesystem::file_type::regular !=
                std::filesystem::status(args.at(1)).type())
            {
                std::cout << "Introduced file is not a regular file: " +
                    std::string(args.at(1)) << std::endl;
                return EXIT_FAILURE;
            }
            else
            {
                FileManager::getInstance().initInputFile(std::string(args.at(1)));
            }
        }

        // Check the size of the given arguments to parse the output file.
        if (args.size() >= 4)
        {
            // If third argument is not "-o" then exit.
            if (args.at(2) != "-o")
            {
                std::cout << usage << std::endl;
                return EXIT_FAILURE;
            }
            else
            {
                FileManager::getInstance().initOutputFile(std::string(args.at(3)));
            }
        }

        return EXIT_SUCCESS;
    }

    /*--------------------------------------------------------------------------
     * Startup the program services.
     */
    void ProgramManager::startUp()
    {
        LogManager::getInstance().startUp();
        LogManager::getInstance().writeLog(E_LEVEL::DEBUG, "Starting services...");
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
        LogManager::getInstance().writeLog(E_LEVEL::DEBUG, "Close program");
        LogManager::getInstance().shutDown();
    }

    /*--------------------------------------------------------------------------
     * Run program loop.
     */
    void ProgramManager::run()
    {
        LogManager::getInstance().writeLog(E_LEVEL::DEBUG, "Starting program...");

        FileManager::getInstance().convertFile();

        LogManager::getInstance().writeLog(E_LEVEL::DEBUG, "Ending program...");
    }
}
