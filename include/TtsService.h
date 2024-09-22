//
// Created by rairear89 on 24. 8. 23.
//

#ifndef TTSSERVICE_H
#define TTSSERVICE_H

#include <cmath>
#include <cstdint>
#include <map>
#include <string>
#include <variant>

namespace RAIREAR {
namespace TTS {
using Parameters = std::map<std::string, std::variant<std::string, int32_t, float_t>>;

class TtsService {
   public:
    virtual ~TtsService() = default;

    virtual void synthesis() = 0;

    void setParameter(const std::string key, const std::string value) { m_parameters[key] = value; }

    std::string& getResult() { return m_result; }

    friend class TtsServiceFactory;

   protected:
    TtsService() = default;

    Parameters m_parameters;

    std::string m_result;
};
}  // namespace TTS
}  // namespace RAIREAR

#endif  // TTSSERVICE_H
