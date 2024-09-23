//
// Created by rairear89 on 24. 9. 21.
//

#ifndef TTSAPI_H
#define TTSAPI_H

#if defined(__cplusplus)

extern "C" {
#endif

#if !defined(TTS_API_decl)
#if defined(WIN32) || defined(_WIN32) || defined(WINCE)
#define TTS_API_decl __declspec(dllexport)
#include <stdlib.h>
#else
#define TTS_API_decl extern
#endif
#endif

namespace RAIREAR::TTS {
class TtsService;
}

typedef enum TTS_TYPE { GOOGLE } TtsType;
typedef RAIREAR::TTS::TtsService* TTS_SERVICE_HANDLE;
typedef void (*TTS_LOG_CALLBACK)(const char*, const char*);

TTS_API_decl TTS_SERVICE_HANDLE TTS_API_CreateHandle(TtsType type);
TTS_API_decl void TTS_API_ReleaseHandle(TTS_SERVICE_HANDLE handle);

TTS_API_decl void TTS_API_SetParameter(TTS_SERVICE_HANDLE handle, const char* key,
                                       const char* value);
TTS_API_decl void TTS_API_Synthesis(TTS_SERVICE_HANDLE handle);
TTS_API_decl const char* TTS_API_GetResult(TTS_SERVICE_HANDLE handle, size_t* size);

TTS_API_decl void TTS_API_SetLogCallback(TTS_LOG_CALLBACK callback);

#if defined(__cplusplus)
}
#endif
#endif /* TTSAPI_H */