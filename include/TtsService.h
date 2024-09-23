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
using Result = std::pair<char*, size_t>;
    
class TtsService {
   public:
    virtual ~TtsService() { delete m_result.first; }

    virtual void synthesis() = 0;

    void setParameter(const std::string key, const std::string value) { m_parameters[key] = value; }

    [[nodiscard]] Result getResult() const { return m_result; }

    friend class TtsServiceFactory;

   protected:
    TtsService() = default;

    Parameters m_parameters;

    Result m_result;
};
}  // namespace TTS
}  // namespace RAIREAR

#endif  // TTSSERVICE_H
