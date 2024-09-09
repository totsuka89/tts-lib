//
// Created by rairear89 on 24. 8. 27.
//

#include <GoogleTts.h>
#include <TtsService.h>

#include <stdexcept>

void RAIREAR::TTS::TtsService::setParameter(const Parameter& parameter) { m_parameter = parameter; }

std::unique_ptr<RAIREAR::TTS::TtsService> RAIREAR::TTS::TtsServiceFactory::create(
    const TtsType ttsType) {
    switch (ttsType) {
        case TtsType::GOOGLE:
            Logger::Logger::getInstance().log("INFO", "Create Google TTS Service");
            return std::make_unique<GoogleTts>();
        default:
            throw std::invalid_argument("Invalid TtsType");
    }
}

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
        logCallback(std::string(level), message);
    }
}
