#include <iostream>
#include <stdexcept>



class FailedToRetriveHttpCodeStatus : public std::exception{
    explicit FailedToRetriveHttpCodeStatus(const std::string& message) : std::runtime_error(message) {}
}

template <typename T>
concept MyConcept = /* Requirements for T */;
