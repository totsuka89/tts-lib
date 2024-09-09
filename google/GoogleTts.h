//
// Created by rairear89 on 24. 8. 27.
//

#ifndef GOOGLETTS_H
#define GOOGLETTS_H

#include <TtsService.h>

#include <nlohmann/json.hpp>

namespace RAIREAR::TTS {
class GoogleTts final : public TtsService {
   public:
    GoogleTts() : TtsService() {}

    ~GoogleTts() override = default;

    [[nodiscard]] std::string synthesis() const override;

   private:
    [[nodiscard]] std::string makeUrl() const;

    [[nodiscard]] nlohmann::json makeJson() const;
};
}  // namespace RAIREAR::TTS

#endif  // GOOGLETTS_H
