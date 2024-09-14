#ifndef LOGGER_H
#define LOGGER_H

#include <ctime>
#include <iomanip>

#include "StringFormatter.h"

namespace Debug
{
const std::string DEFAULT_COLOR = "\033[0m";

const std::string WHITE_COLOR = "\033[1;37;40m";
const std::string RED_COLOR = "\033[1;31;40m";
const std::string GREEN_COLOR = "\033[1;32;40m";
const std::string BLUE_COLOR = "\033[1;36;40m";
const std::string YELLOW_COLOR = "\033[1;33;40m";
const std::string PURPLE_COLOR = "\033[1;35;40m";

class Logger
{
  public:
    enum LOG_PRIORITY
    {
        NONE = 0,
        LOG = 1,
        WARNING = 2,
        ERROR = 3,
        ALL = 4
    };

    enum LOG_COLOR
    {
        WHITE = 0,
        RED = 1,
        GREEN = 2,
        BLUE = 3,
        YELLOW = 4,
        PURPLE = 5,
    };

    template <typename... TParameters>
    static void LogColor(const LOG_COLOR color, const std::string &message, TParameters... parameters)
    {
        std::string target_color;

        switch (color)
        {
        case WHITE:
            target_color = WHITE_COLOR;
            break;
        case RED:
            target_color = RED_COLOR;
            break;
        case GREEN:
            target_color = GREEN_COLOR;
            break;
        case BLUE:
            target_color = BLUE_COLOR;
            break;
        case YELLOW:
            target_color = YELLOW_COLOR;
            break;
        case PURPLE:
            target_color = PURPLE_COLOR;
            break;

        default:
            target_color = WHITE_COLOR;
            break;
        }

        PrintMessage(LOG, target_color, message, parameters...);
    }

    template <typename... TParameters> static void Log(const std::string &message, TParameters... parameters)
    {
        PrintMessage(LOG, WHITE_COLOR, message, parameters...);
    }

    template <typename... TParameters> static void Warning(const std::string &message, TParameters... parameters)
    {
        PrintMessage(WARNING, YELLOW_COLOR, message, parameters...);
    }

    template <typename... TParameters> static void Error(const std::string &message, TParameters... parameters)
    {
        PrintMessage(ERROR, RED_COLOR, message, parameters...);
    }

  private:
    template <typename... TParameters>
    static void PrintMessage(const LOG_PRIORITY priority, const std::string &color_code, const std::string &message,
                             TParameters... parameters)
    {
        std::string priority_tag_text;

        switch (priority)
        {
        case LOG:
            priority_tag_text = "[LOG] ";
            break;
        case WARNING:
            priority_tag_text = "[WARNING] ";
            break;
        case ERROR:
            priority_tag_text = "[ERROR] ";
            break;

        default:
            priority_tag_text = "[NONE] ";
            break;
        }
        const auto current_time = GetCurrentTime();

        const std::string time = "[" + current_time + "] ";

        std::cout << time << color_code << priority_tag_text << StringFormatter::Combine(message, parameters...)
                  << DEFAULT_COLOR << "\n";
    }

    static std::string GetCurrentTime()
    {
        time_t current_time;
        struct tm *time_info;

        time(&current_time);
        time_info = localtime(&current_time);

        const int hours = time_info->tm_hour;
        const int minutes = time_info->tm_min;
        const int seconds = time_info->tm_sec;

        std::ostringstream formatted_time_stream;

        formatted_time_stream << std::setfill('0') << std::setw(2) << hours << ":" << std::setfill('0') << std::setw(2)
                              << minutes << ":" << std::setfill('0') << std::setw(2) << seconds;

        return formatted_time_stream.str();
    }
};
} // namespace Debug

#endif // !LOGGER_H
