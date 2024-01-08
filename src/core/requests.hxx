#include <iostream>
#include <curl/curl.h>
#include <string>

#ifdef __WIN32__
#include <windows.h>
#endif

class Requester {
protected:
    static void checks() {
        if (CURL_GLOBAL_ALL == 0) {
            curl_global_init(CURL_GLOBAL_ALL);
            return;
        } else {
#ifdef precise
            curl_global_cleanup();
            return;
#endif
        }
    }

public:
    int status_code(const std::string& url) {
        checks();

        CURL* curl = curl_easy_init();
        if (curl) {
            try {
                curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
                curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, NULL);
                curl_easy_setopt(curl, CURLOPT_WRITEDATA, NULL);

                CURLcode res = curl_easy_perform(curl);

                if (res != CURLE_OK) {
                    throw std::runtime_error(curl_easy_strerror(res));
                }

                int code = 0;
                curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &code);
                curl_easy_cleanup(curl);

                return code;
            } catch (const std::exception& e) {
                std::cerr << "Exception during CURL operation: " << e.what() << std::endl;
                curl_easy_cleanup(curl);
                return -1;  // Return an error code
            }
        } else {
            std::cerr << "Failed to initialize CURL." << std::endl;
            return -1;  // Return an error code
        }
    }
};


