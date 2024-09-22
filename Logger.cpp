//
// Created by rairear89 on 24. 9. 21.
//

#include <Logger.h>

RAIREAR::Logger::Logger& RAIREAR::Logger::Logger::getInstance() {
    static Logger instance;
    return instance;
}

void RAIREAR::Logger::Logger::setCallback(LogCallback callback) {
    logCallback = std::move(callback);
}

void RAIREAR::Logger::Logger::log(const std::string_view level,
                                  const std::string_view message) const {
    if (logCallback) {
        logCallback(level.data(), message.data());
    }
}