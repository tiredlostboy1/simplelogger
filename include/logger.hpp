#ifndef LOGGER_H
#define LOGGER_H
#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <mutex>
#include <chrono>
#include <iomanip>

enum LogLevel
{
    LOG_LEVEL_DEBUG,
    LOG_LEVEL_INFO,
    LOG_LEVEL_WARNING,
    LOG_LEVEL_ERROR
};

class Logger
{
private:
    std::ofstream file_;
    std::mutex mutex_;
    LogLevel level_;

public:
    Logger(const std::string &file, LogLevel level);
    void Log(const std::string &message, LogLevel level);
    std::_Put_time<char> TimeStamp();
    std::string LeveltoString(LogLevel level);
};

#endif // LOGGER_H