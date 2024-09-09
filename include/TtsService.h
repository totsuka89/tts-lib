//
// Created by rairear89 on 24. 8. 23.
//

#ifndef TTSSERVICE_H
#define TTSSERVICE_H

#include <cmath>
#include <functional>
#include <map>
#include <memory>
#include <string>
#include <variant>

namespace RAIREAR {
namespace TTS {
using Parameter = std::map<std::string, std::variant<std::string, int32_t, float_t>>;

enum class TtsType { GOOGLE };

class TtsService {
   public:
    virtual ~TtsService() = default;

    [[nodiscard]] virtual std::string synthesis() const = 0;

    void setParameter(const Parameter& parameter);

    friend class TtsServiceFactory;

   protected:
    TtsService() = default;

    Parameter m_parameter;
};

class TtsServiceFactory final {
   public:
    static std::unique_ptr<TtsService> create(TtsType ttsType);
};

class ParameterBuilder final {
   public:
    ParameterBuilder& setLanguage(std::string_view language);

    ParameterBuilder& setText(std::string_view text);

    ParameterBuilder& setFile(std::string_view file);

    ParameterBuilder& set(std::string_view key, std::string_view value);

    [[nodiscard]] Parameter build();

   private:
    Parameter m_parameter;
};
}  // namespace TTS

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

#endif  // TTSSERVICE_H
