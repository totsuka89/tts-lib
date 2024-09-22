# TTS 라이브러리 TTS Library

## 개요 Overview

**TTSService** 라이브러리는 텍스트를 음성으로 변환하는(TTS) 기능을 제공합니다.  
The TTSService library provides text-to-speech (TTS) functionality.  

이 라이브러리는 언어, 텍스트 등의 다양한 매개변수를 설정할 수 있으며, TTS 서비스 팩토리를 통해 다양한 TTS 서비스의 인스턴스를 사용할 수 있습니다.  
This library allows you to configure various parameters such as language and text, and utilize instances of different TTS services through the TTS service factory.

## 주요 클래스 Classes

- **RAIREAR::TTS::TtsService**  
    텍스트를 음성으로 변환하는(TTS) 기능을 제공합니다.  
    Provides text-to-speech (TTS) functionality.
    - Google  
    Google 클라우드 API를 사용한 TTS 서비스. 적절한 API 키가 필요함.  
    TTS service using Google Cloud API. Requires a valid API key.  
    (https://cloud.google.com/text-to-speech)

    - Mozilla  
    추후 업데이트 예정.  
    Planned for future updates.  

- **RAIREAR::TTS::TtsServiceFactory**  
    TtsService의 인스턴스를 생성하는 팩토리 클래스입니다.  
    A factory class for creating instances of TtsService.  

- **RAIREAR::TTS::ParameterBuilder**  
    언어, 텍스트 등의 매개변수를 설정하고 관리하는 빌더 클래스입니다.  
    A builder class for setting and managing parameters such as language and text.  

- **RAIREAR::Logger::Logger**  
    사용자 정의 콜백으로 로그를 처리할 수 있는 간단한 로깅 클래스입니다.  
    A simple logging class that can process logs using custom callbacks.  

## 요구 사항 Requirements

- **C++20** 또는 그 이상
- **C++20** or higher

## 외부 라이브러리 External Libraries

  - [nlohmann/json](https://github.com/nlohmann/json)  
      JSON 처리 라이브러리.  
      JSON processing library.  
  - [libcurl](https://curl.se/libcurl/)  
      네트워크 통신을 위한 라이브러리.  
      A library for network communication.  
  - [gtest](https://github.com/google/googletest)  
      유닛 테스트를 위한 Google Test 프레임워크.  
      Google Test framework for unit testing.

## 예제 Example

1. **TTS 서비스 핸들 생성 Creating a handle of TTS Service**  
   `TTS_API_CreateHandle()`를 통해 TTS 서비스의 핸들을 생성할 수 있습니다.  
   You can create a handle of TTS service through `TTS_API_CreateHandle()`.
   ```cpp
   TTS_SERVICE_HANDLE hTts = TTS_API_CreateHandle(GOOGLE);
   ```

2. **매개변수 설정 Setting Parameters**  
   `TTS_API_SetParameter()`를 사용하여 매개변수를 설정합니다.  
   Use `TTS_API_SetParameter()` to set the parameters.  
   ```cpp
   // Example of setting the language.
   TTS_API_SetParameter(hTts, std::string("language").c_str(), std::string("en-US").c_str());
   // Example of setting the text for speech.
   TTS_API_SetParameter(hTts, std::string("text").c_str(), std::string("test message").c_str());
   // Example of setting the api key for google cloud service.
   TTS_API_SetParameter(hTts, std::string("api_key").c_str(), std::string("GOOGLE_TTS_API_KEY").c_str());
   ```

3. **음성 합성 Speech Synthesis**  
   `TTS_API_Synthesis()` 함수를 호출하여 음성을 생성합니다.  
   Call the `TTS_API_Synthesis()` function to generate speech.
   ```cpp
   TTS_API_Synthesis(hTts);
   ```

4. **결과 가져오기 Get Result**  
   `TTS_API_GetResult()` 함수를 호출하여 결과를 가져옵니다.  
   Call the `TTS_API_GetResult()` function to get result.
   ```cpp
   TTS_API_GetResult(hTts);
   ```

5. **TTS 서비스 핸들 해제 Releasing a handle of TTS Service**  
   `TTS_API_ReleaseHandle()` 함수를 호출하여 핸들을 해제합니다..  
   Call the `TTS_API_ReleaseHandle()` function to release handle.
   ```cpp
   TTS_API_GetResult(hTts);
   ```

6. **로깅 Logging**  
   사용자 정의 콜백으로 로거를 설정할 수 있습니다.  
   You can set the logger with a custom callback.  
   ```cpp
    Logger::Logger::getInstance().setCallback(
        [](std::string_view level, std::string_view message) {
            std::cout << "[" << level << "] " << message << std::endl;
        }
    );
    Logger::Logger::getInstance().log("INFO", "TTS 합성 시작");
    ```

## 클래스 다이어그램 Class Diagram
![](https://github.com/totsuka89/tts-lib/blob/main/classDiagram.png?raw=true)

## 라이센스 License
[LISENCE](https://github.com/totsuka89/tts-lib?tab=License-1-ov-file#readme)
