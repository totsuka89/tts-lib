//
// Created by rairear89 on 24. 9. 7.
//

#include <gtest/gtest.h>

#include "../google/GoogleTts.h"
#include "../include/TtsService.h"

using namespace RAIREAR::TTS;

#define GOOGLE_TTS_API_KEY "input_custom_key"

class GoogleTtsTest : public ::testing::Test {
   protected:
    void SetUp() override {
        tts = new GoogleTts();

        ParameterBuilder builder;
        const auto parameter = builder.setLanguage("en-US")
                                   .setText("test message")
                                   .set("api_key", GOOGLE_TTS_API_KEY)
                                   .build();
        tts->setParameter(parameter);
    }

    void TearDown() override { delete tts; }

    GoogleTts* tts;
};

TEST_F(GoogleTtsTest, GoogleTtsTest) { EXPECT_NO_FATAL_FAILURE(tts->synthesis()); }

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}