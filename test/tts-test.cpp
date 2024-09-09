//
// Created by rairear89 on 24. 9. 7.
//

#include <gtest/gtest.h>

#include "../include/TtsApi.h"

using namespace RAIREAR::TTS;

#define GOOGLE_TTS_API_KEY "input_custom_key"

class GoogleTtsTest : public ::testing::Test {
   protected:
    void SetUp() override {
        hTts = TTS_API_CreateHandle(GOOGLE);

        TTS_API_SetParameter(hTts, std::string("language").c_str(), std::string("en-US").c_str());
        TTS_API_SetParameter(hTts, std::string("text").c_str(),
                             std::string("test message").c_str());
        TTS_API_SetParameter(hTts, std::string("api_key").c_str(),
                             std::string(GOOGLE_TTS_API_KEY).c_str());
        TTS_API_Synthesis(hTts);
    }

    void TearDown() override { TTS_API_ReleaseHandle(hTts); }

    TTS_SERVICE_HANDLE hTts = nullptr;
};

TEST_F(GoogleTtsTest, GoogleTtsTest) { EXPECT_NE(TTS_API_GetResult(hTts), ""); }

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}