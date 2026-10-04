#include "bad_figure.h"

bad_figure::bad_figure(const std::string& message) 
    : std::domain_error(message), reason(message) {}

std::string bad_figure::get_reason() const {
    return reason;
}
