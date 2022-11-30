//==============================================================================
// Name        : FileManager.h
// Author      : Jorge
// Copyright   : https://creativecommons.org/licenses/by/4.0/
// Description : Manager of the input and output files.
//==============================================================================

#ifndef __FILE_MANAGER_H__
#define __FILE_MANAGER_H__

// System includes.
#include <fstream>
#include <iostream>
#include <string>

// Engine includes.
#include "Manager.h"

//==============================================================================
/* FileManager */
//==============================================================================

/*------------------------------------------------------------------------------
 * Manager of the input and output files.
 */
namespace wordconverter
{
    class FileManager : public Manager
    {
    private:
        FileManager();
        FileManager(FileManager const &){};
        void operator=(FileManager const &){};

        // Name of the IO files.
        std::string inputFileName;
        std::string outputFileName;

        // IO Files.
        std::ifstream inputFile;
        std::ofstream outputFile;


    public:
        // If files are open, close them.
        ~FileManager(){};

        // Get the one and only instance of the FileManager.
        static FileManager &getInstance();

        // Initialize the input file before the start up.
        void initInputFile(const std::string &input);

        // Initialize the output file before the start up.
        void initOutputFile(const std::string &output);

        // Startup the FileManager (open files).
        void startUp();

        // Shut down the FileManager (close files).
        void shutDown();

        // Function to convert a file with written numbers to digital numbers.
        // If output file is defined the result will be stored there.
        void convertFile();
    };
}
//------------------------------------------------------------------------------
#endif // __FILE_MANAGER_H__
