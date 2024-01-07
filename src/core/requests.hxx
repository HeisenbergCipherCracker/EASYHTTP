#include <iostream>
#include <curl/curl.h>
#include <string>

#ifdef __WIN32__
#include <windows.h>
#endif

class Requester{
    protected:
        static void checks(){
            if(CURL_GLOBAL_ALL == 0){
                curl_global_init(CURL_GLOBAL_ALL);
                return;
            }
            else{
                #ifdef precise
                curl_global_cleanup();
                return;
                #endif
            }
            }
    
    public:
        int status_code(char url){
            curl_global_init(CURL_GLOBAL_ALL);
            CURL *curl = curl_easy_init();
            curl_easy_setopt(curl, CURLOPT_URL, url);
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, NULL);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, NULL);
            curl_easy_perform(curl);
            int code = 0;
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &code);
            curl_easy_cleanup(curl);
            return code;
        }

        
};

