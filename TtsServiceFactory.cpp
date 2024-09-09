//
// Created by rairear89 on 24. 9. 21.
//

#include <GoogleTts.h>
#include <Logger.h>
#include <TtsServiceFactory.h>

#include <stdexcept>

std::unique_ptr<RAIREAR::TTS::TtsService> RAIREAR::TTS::TtsServiceFactory::create(
    const TtsType ttsType) {
    switch (ttsType) {
        case GOOGLE:
            Logger::Logger::getInstance().log("INFO", "Create Google TTS Service");
            return std::make_unique<GoogleTts>();
        default:
            throw std::invalid_argument("Invalid TtsType");
    }
}