#include <iostream>
#include "src/core/requests.hxx"
//todo: create a test util file and utils dir


int main() {
    Requester requester;
    std::string url = "https://www.example.com";  // Replace with your desired URL
    int statusCode = requester.status_code(url);

    if (statusCode != -1) {
        std::cout << "HTTP Status Code: " << statusCode << std::endl;
    } else {
        std::cerr << "Failed to retrieve HTTP status code." << std::endl;
    }

    return 0;
}