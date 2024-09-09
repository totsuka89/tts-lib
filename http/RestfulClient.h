//
// Created by rairear89 on 24. 9. 3.
//

#ifndef RESTFULCLIENT_H
#define RESTFULCLIENT_H

#include <curl/curl.h>

#include <string>

namespace RAIREAR::Http {
enum class Method { REST_GET, REST_POST, REST_PUT, REST_DELETE };

class RestfulClient final {
   public:
    RestfulClient();

    ~RestfulClient();

    [[nodiscard]] std::string request(Method method, std::string_view url,
                                      std::string_view body) const;

   private:
    static size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* userp);

    CURL* m_curl = nullptr;
};
}  // namespace RAIREAR::Http

#endif  // RESTFULCLIENT_H
