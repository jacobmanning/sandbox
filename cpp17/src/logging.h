#pragma once
#ifndef SIMPLE_LOGGING_H_
#define SIMPLE_LOGGING_H_

#include <cstring>
#include <iostream>

#define _FILE \
    std::string(strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)

#define LOG(level, message)                                        \
    std::clog << "[" << level << "] " << _FILE << " (" << __LINE__ \
              << "): " << message << '\n';

#define LOG_DEBUG(message) LOG("DEBUG", message)

#define LOG_INFO(message) LOG("INFO", message)

#define LOG_WARN(message) LOG("WARN", message)

#define LOG_ERROR(message) LOG("ERROR", message)

#endif  // SIMPLE_LOGGING_H_
