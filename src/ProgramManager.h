//==============================================================================
// Name        : ProgramManager.h
// Author      : Jorge
// Copyright   : https://creativecommons.org/licenses/by/4.0/
// Description : Manager of the program.
//==============================================================================

#ifndef __PROGRAM_MANAGER_H__
#define __PROGRAM_MANAGER_H__

// System includes.
#include <string>

// Engine includes.
#include "Manager.h"

//==============================================================================
/* ProgramManager */
//==============================================================================

/*------------------------------------------------------------------------------
 * Manager of the program.
 */
namespace wordconverter
{
    class ProgramManager : public Manager
    {
    private:
        ProgramManager();
        ProgramManager(ProgramManager const &){};
        void operator=(ProgramManager const &){};

    public:
        ~ProgramManager(){};

        // Get the singleton instance of the ProgramManager.
        static ProgramManager &getInstance();

        // Initialize the program by parsing the program arguments.
        int initialization(int argc, char *argv[]);

        // Startup the program services.
        void startUp();

        // Shut down the program services.
        void shutDown();

        // Run program loop.
        void run();
    };
}
//------------------------------------------------------------------------------
#endif // __PROGRAM_MANAGER_H__
