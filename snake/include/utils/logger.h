#pragma once

#include <cstdio>



namespace utils
{
   
    enum LOG_PRIORITY
    {
        TRACE_PRIORITY,
        DEBUG_PRIORITY,
        INFO_PRIORITY,
        WARN_PRIORITY,
        ERROR_PRIORITY,
        CRITICAL_PRIORITY
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
    
}
