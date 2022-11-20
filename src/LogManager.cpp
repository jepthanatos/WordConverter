//==============================================================================
// Name        : LogManager.cpp
// Author      : Jorge
// Copyright   : https://creativecommons.org/licenses/by/4.0/
// Description : Manager of the logfile.
//==============================================================================

#include "LogManager.h"

// Sytem includes
#include <chrono>
#include <iomanip>
#include <sstream>
#include <iostream>

//==============================================================================
/* Manager */
//==============================================================================

namespace wordconverter
{
    /*--------------------------------------------------------------------------
     * Constructor.
     */
    LogManager::LogManager()
    {
        Manager::setType("LogManager");
    }

    /*--------------------------------------------------------------------------
     * Destructor.
     */
    LogManager::~LogManager()
    {
        if (logFile.is_open())
            logFile.close();
    }

    /*--------------------------------------------------------------------------
     * Get the one and only instance of the LogManager.
     */
    LogManager &LogManager::getInstance()
    {
        static LogManager instance;
        return instance;
    }

    /*--------------------------------------------------------------------------
     * Start up the LogManager (open logfile).
     */
    void LogManager::startUp()
    {
        try
        {
            logFile.open(LOGFILE_NAME, std::ofstream::out);
            logLevel = E_LEVEL::DEBUG;
            started = true;
        }
        catch (std::ofstream::failure e)
        {
            std::cerr << "Log file creation failed." << std::endl;
            std::cerr << e.what() << std::endl;
        }
    }

    /*--------------------------------------------------------------------------
     * Shut down the LogManager (close logfile).
     */
    void LogManager::shutDown()
    {
        logFile.close();
    }

    /*--------------------------------------------------------------------------
     * Write to logfile.
     */
    void LogManager::writeLog(int level, const std::string message)
    {
        // Lambda to generate pretty time for logs.
        auto prettyTime = []()
        {
            const auto now = std::chrono::system_clock::now();
            const auto nowAsTimeT = std::chrono::system_clock::to_time_t(now);
            const auto nowMs =
                std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()) % 1000;
            std::stringstream nowSs;
            nowSs
                << std::put_time(std::localtime(&nowAsTimeT), "%a %b %d %Y %T")
                << '.' << std::setfill('0') << std::setw(3) << nowMs.count();
            return nowSs.str();
        };

        if (level >= logLevel)
            logFile << prettyTime() << " : " << message << std::endl;
    }

    /*--------------------------------------------------------------------------
     * Get the log level.
     */
    int LogManager::getLevel()
    {
        return logLevel;
    }

    /*--------------------------------------------------------------------------
     * Set the log level.
     */
    void LogManager::setLevel(int value)
    {
        logLevel = value;
    }
}
