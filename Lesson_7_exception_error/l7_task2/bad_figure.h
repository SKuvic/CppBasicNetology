#pragma once
#include <stdexcept>
#include <string>

class bad_figure : public std::domain_error {
private:
    std::string reason; 
public:
    bad_figure(const std::string& message);
    std::string get_reason() const; 
};
