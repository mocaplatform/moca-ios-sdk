//
//  MOCALog.h
//
//  MOCA iOS SDK
//  Version 1.1.0
//
//  This module is part of InnoQuant MOCA Platform.
//
//  Copyright (c) 2012-2014 InnoQuant Strategic Analytics, S.L.
//  All rights reserved.
//
//  All rights to this software by InnoQuant are owned by InnoQuant
//  and only limited rights are provided by the licensing or contract
//  under which this software is provided.
//
//  Any use of the software for any commercial purpose without
//  the written permission of InnoQuant is prohibited.
//  You may not alter, modify, or in any way change the appearance
//  and copyright notices on the software. You may not reverse compile
//  the software or publish any protected intellectual property embedded
//  in the software. You may not distribute, sell or make copies of
//  the software available to any entities without the explicit written
//  permission of InnoQuant.
//

/**
 * Log level definitions.
 */
typedef enum _MOCALogLevel
{
    Off,
    Error,
    Warning,
    Info,
    Debug,
    Trace
} MOCALogLevel;

/*
 * Current log level.
 */
extern MOCALogLevel _logLevel;

/*
 * Macros to easily write log messages.
 */

#if DEBUG
    #define MOCA_LOG(level, levelStr, formatStr, ...) \
        do { \
            if ((_logLevel != Off) && (_logLevel >= level)) { \
                NSLog((@"%@ (%s %s:%d) " formatStr), levelStr, __PRETTY_FUNCTION__, __FILE__, __LINE__, ##__VA_ARGS__); \
            } \
        } while(0)
#else
    #define MOCA_LOG(level, levelStr, formatStr, ...) \
        do { \
            if ((_logLevel != Off) && (_logLevel >= level)) { \
                NSLog((@"%@ (%s) " formatStr), levelStr, __PRETTY_FUNCTION__, ##__VA_ARGS__); \
            } \
        } while(0)
#endif // DEBUG

#define MOCA_LOG_ERROR(formatStr, ...) MOCA_LOG(Error, @"ERROR", formatStr, ##__VA_ARGS__)
#define MOCA_LOG_WARNING(formatStr, ...) MOCA_LOG(Warning, @"WARNING", formatStr, ##__VA_ARGS__)
#define MOCA_LOG_INFO(formatStr, ...) MOCA_LOG(Info, @"INFO", formatStr, ##__VA_ARGS__)
#define MOCA_LOG_DEBUG(formatStr, ...) MOCA_LOG(Debug, @"DEBUG", formatStr, ##__VA_ARGS__)
#define MOCA_LOG_TRACE(formatStr, ...) MOCA_LOG(Trace, @"TRACE", formatStr, ##__VA_ARGS__)
