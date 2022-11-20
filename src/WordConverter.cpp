//==============================================================================
// Name        : WordConverter.cpp
// Author      : Jorge
// Copyright   : https://creativecommons.org/licenses/by/4.0/
// Description : Main program of a running journal.
//==============================================================================

// Includes.
//#include <unistd.h>
//#include <vector>
//#include <iostream>
//#include <chrono>
//#include <thread>
//#include <filesystem>

// Local includes.
#include "ProgramManager.h"

//==============================================================================
/* WordConverter */
//==============================================================================

/*------------------------------------------------------------------------------
 * Main program
 */
using namespace wordconverter;

int main(int argc, char *argv[])
{
    // First check the arguments, if they are wrong exit the program.
    if (ProgramManager::getInstance().initialization(argc, argv) == EXIT_FAILURE)
        return EXIT_FAILURE;

    // Run the services of the program.
    ProgramManager::getInstance().startUp();

    // Check if the program has started.
    if (ProgramManager::getInstance().isStarted())
    {
        ProgramManager::getInstance().run();
    }

    // Shut down the services of the program.
    ProgramManager::getInstance().shutDown();

    return EXIT_SUCCESS;
}

//==============================================================================
