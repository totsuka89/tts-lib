//
// Created by rairear89 on 24. 9. 21.
//

#ifndef TTSSERVICEFACTORY_H
#define TTSSERVICEFACTORY_H

#include <memory>

#include "TtsApi.h"

namespace RAIREAR {
namespace TTS {
class TtsServiceFactory final {
   public:
    static std::unique_ptr<TtsService> create(TtsType ttsType);
};
}  // namespace TTS
}  // namespace RAIREAR

#endif