#include <TtsApi.h>
#include <TtsService.h>
#include <TtsServiceFactory.h>

using namespace RAIREAR::TTS;

TTS_API_decl TTS_SERVICE_HANDLE TTS_API_CreateHandle(const TtsType type) {
    return TtsServiceFactory::create(type).release();
}

TTS_API_decl void TTS_API_ReleaseHandle(TTS_SERVICE_HANDLE handle) { delete handle; }

TTS_API_decl void TTS_API_SetParameter(TTS_SERVICE_HANDLE handle, const char* key,
                                       const char* value) {
    handle->setParameter(key, value);
}

TTS_API_decl void TTS_API_Synthesis(TTS_SERVICE_HANDLE handle) { handle->synthesis(); }

const char* TTS_API_GetResult(TTS_SERVICE_HANDLE handle) { return handle->getResult().c_str(); }
