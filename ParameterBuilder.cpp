//
// Created by rairear89 on 24. 8. 24.
//

#include <TtsService.h>

RAIREAR::TTS::ParameterBuilder& RAIREAR::TTS::ParameterBuilder::setLanguage(
    const std::string_view language) {
    m_parameter["language"] = std::string(language);
    return *this;
}

RAIREAR::TTS::ParameterBuilder& RAIREAR::TTS::ParameterBuilder::setText(
    const std::string_view text) {
    m_parameter["text"] = std::string(text);
    return *this;
}

RAIREAR::TTS::ParameterBuilder& RAIREAR::TTS::ParameterBuilder::setFile(
    const std::string_view file) {
    m_parameter["file"] = std::string(file);
    return *this;
}

RAIREAR::TTS::ParameterBuilder& RAIREAR::TTS::ParameterBuilder::set(const std::string_view key,
                                                                    const std::string_view value) {
    m_parameter[std::string(key)] = std::string(value);
    return *this;
}

RAIREAR::TTS::Parameter RAIREAR::TTS::ParameterBuilder::build() { return m_parameter; }
