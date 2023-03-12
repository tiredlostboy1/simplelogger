#include "../include/logger.hpp"

int main()
{
    Logger logger("log.txt", LOG_LEVEL_DEBUG);
    logger.Log("Debug message", LOG_LEVEL_DEBUG);
    logger.Log("Info message", LOG_LEVEL_INFO);
    logger.Log("Warning message", LOG_LEVEL_WARNING);
    logger.Log("Error message", LOG_LEVEL_ERROR);

    return 0;
}