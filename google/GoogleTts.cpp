//
// Created by rairear89 on 24. 8. 27.
//

#include "GoogleTts.h"

#include <RestfulClient.h>
#include <base64.h>

#include <iostream>

using namespace std;
using json = nlohmann::json;

namespace RAIREAR::TTS {
string GoogleTts::synthesis() const {
    const string url = makeUrl();
    const json jsonBody = makeJson();

    const Http::RestfulClient client;
    const json response =
        json::parse(client.request(Http::Method::REST_POST, url, jsonBody.dump()));
    const string result = base64_decode(response["audioContent"]);

    return result;
}

string GoogleTts::makeUrl() const {
    string apiKey;

    try {
        apiKey = get<string>(m_parameter.at("api_key"));
    } catch (const exception& e) {
        cerr << "Error: Exception occurred - " << e.what() << endl;
        return "";
    }

    std::string url =
        "https://texttospeech.googleapis.com/v1/"
        "text:synthesize?key=" +
        apiKey;

    Logger::Logger::getInstance().log("INFO", "URL : " + url);

    return url;
}

nlohmann::json GoogleTts::makeJson() const {
    string language;
    string text;

    try {
        language = get<string>(m_parameter.at("language"));
        text = get<string>(m_parameter.at("text"));
    } catch (const exception& e) {
        cerr << "Error: Exception occurred - " << e.what() << endl;
        return {};
    }

    json json;
    json["voice"]["languageCode"] = language;
    json["input"]["text"] = text;
    json["audioConfig"]["audioEncoding"] = "mp3";

    Logger::Logger::getInstance().log("INFO", "json : " + json.dump(4));

    return json;
}
}  // namespace RAIREAR::TTS
