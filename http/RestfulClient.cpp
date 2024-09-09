//
// Created by rairear89 on 24. 9. 3.
//

#include "RestfulClient.h"

#include <iostream>

RAIREAR::Http::RestfulClient::RestfulClient() : m_curl(curl_easy_init()) {}

RAIREAR::Http::RestfulClient::~RestfulClient() {
    if (m_curl) {
        curl_easy_cleanup(m_curl);
    }
}

std::string RAIREAR::Http::RestfulClient::request(const Method method, const std::string_view url,
                                                  const std::string_view body) const {
    if (!m_curl) {
        std::cerr << "CURL is not initialized" << std::endl;
        return "";
    }

    curl_easy_setopt(m_curl, CURLOPT_URL, url.data());

    switch (method) {
        case Method::REST_GET:
            curl_easy_setopt(m_curl, CURLOPT_HTTPGET, 1L);
            break;

        case Method::REST_POST:
            curl_easy_setopt(m_curl, CURLOPT_POST, 1L);
            curl_easy_setopt(m_curl, CURLOPT_POSTFIELDS, body.data());
            break;

        case Method::REST_PUT:
            curl_easy_setopt(m_curl, CURLOPT_CUSTOMREQUEST, "PUT");
            curl_easy_setopt(m_curl, CURLOPT_POSTFIELDS, body.data());
            break;

        case Method::REST_DELETE:
            curl_easy_setopt(m_curl, CURLOPT_CUSTOMREQUEST, "DELETE");
            break;

        default:
            std::cerr << "Unsupported HTTP method" << std::endl;
            return "";
    }

    curl_slist* headers = nullptr;
    headers = curl_slist_append(headers, "Content-Type: application/json");
    curl_easy_setopt(m_curl, CURLOPT_HTTPHEADER, headers);

    std::string responseString;
    curl_easy_setopt(m_curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(m_curl, CURLOPT_WRITEDATA, &responseString);

    if (const CURLcode res = curl_easy_perform(m_curl); res != CURLE_OK) {
        std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
    }

    curl_slist_free_all(headers);

    return responseString;
}

size_t RAIREAR::Http::RestfulClient::WriteCallback(void* contents, const size_t size,
                                                   const size_t nmemb, std::string* userp) {
    const size_t totalSize = size * nmemb;
    userp->append(static_cast<char*>(contents), totalSize);
    return totalSize;
}
