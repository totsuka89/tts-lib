//
// Created by rairear89 on 24. 9. 21.
//

#ifndef LOGGER_H
#define LOGGER_H

#include <functional>
#include <string>

namespace RAIREAR {
namespace Logger {
class Logger {
   public:
    using LogCallback = std::function<void(std::string_view, std::string_view)>;

    static Logger& getInstance();

    void setCallback(LogCallback callback);

    void log(std::string_view level, std::string_view message) const;

   private:
    Logger() = default;

    Logger(const Logger& other) = delete;

    Logger& operator=(const Logger& other) = delete;

    Logger(Logger&& other) = delete;

    Logger& operator=(Logger&& other) = delete;

    LogCallback logCallback;
};
}  // namespace Logger
}  // namespace RAIREAR

#endif