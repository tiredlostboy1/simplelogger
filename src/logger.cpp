#include "../include/logger.hpp"

Logger::Logger(const std::string &file, LogLevel level) : level_(level)
{
    file_.open(file, std::ios_base::app);
    if (!(file_.is_open()))
    {
        std::cerr << "Failed to open log file" << std::endl;
    }
}

void Logger::Log(const std::string &message, LogLevel level)
{
    if (level < level_)
    {
        return;
    }

    std::lock_guard<std::mutex> lock(mutex_);

    std::cout << TimeStamp() << " [" << LeveltoString(level) << "] " << message << std::endl;

    if (file_.is_open())
    {
        file_ << TimeStamp() << " [" << LeveltoString(level) << "] " << message << std::endl;
    }
}

std::string Logger::LeveltoString(LogLevel level)
{
    switch (level)
    {
    case LOG_LEVEL_DEBUG:
        return "DEBUG";
    case LOG_LEVEL_INFO:
        return "INFO";
    case LOG_LEVEL_WARNING:
        return "WARNING";
    case LOG_LEVEL_ERROR:
        return "ERROR";
    default:
        return "UNKNOWN";
    }
}

std::_Put_time<char> Logger::TimeStamp()
{
    auto now = std::chrono::system_clock::now();
    auto now_c = std::chrono::system_clock::to_time_t(now);
    return std::put_time(std::localtime(&now_c), "%F %T");
}