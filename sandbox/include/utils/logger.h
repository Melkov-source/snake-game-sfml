#pragma once

#include <cstdio>

namespace utils
{
    enum LOG_PRIORITY
    {
        TRACE_PRIORITY = 0,
        DEBUG_PRIORITY = 1,
        INFO_PRIORITY = 2,
        WARN_PRIORITY = 3,
        ERROR_PRIORITY = 4,
        CRITICAL_PRIORITY = 5,
        NONE_PRIORITY = 6
    };

    static LOG_PRIORITY priority_;

    template <typename... Args>
        static void trace(const char* message, Args... args)
    {
        if (priority_ > TRACE_PRIORITY) return;

        printf("[Trace]\t");
        printf(message, args...);
        printf("\n");
    }
        
    template <typename... Args>
    static void debug(const char* message, Args... args)
    {
        if (priority_ > DEBUG_PRIORITY) return;

        printf("[Debug]\t");
        printf(message, args...);
        printf("\n");
    }
        
    template <typename... Args>
    static void info(const char* message, Args... args)
    {
        if (priority_ > INFO_PRIORITY) return;

        printf("[Info]\t");
        printf(message, args...);
        printf("\n");
    }
        
    template <typename... Args>
    static void warn(const char* message, Args... args)
    {
        if (priority_ > WARN_PRIORITY) return;

        printf("[Warn]\t");
        printf(message, args...);
        printf("\n");
    }
        
    template <typename... Args>
    static void error(const char* message, Args... args)
    {
        if (priority_ > ERROR_PRIORITY) return;

        printf("[Error]\t");
        printf(message, args...);
        printf("\n");
    }
        
    template <typename... Args>
    static void critical(const char* message, Args... args)
    {
        if (priority_ > CRITICAL_PRIORITY) return;

        printf("[Critical]\t");
        printf(message, args...);
        printf("\n");
    }

    static void set_priority(const LOG_PRIORITY priority)
    {
        priority_ = priority;
    }

    static LOG_PRIORITY get_priority()
    {
        return priority_;
    }
    
}
