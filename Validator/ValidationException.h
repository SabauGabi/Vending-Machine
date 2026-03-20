//
// Created by Gabi on 5/25/2025.
//

#ifndef VALIDATIONEXCEPTION_H
#define VALIDATIONEXCEPTION_H
#include <string>
#include <stdexcept>

class ValidationException : public std::runtime_error {
public:
    explicit ValidationException(const std::string& msg) : std::runtime_error(msg) {}
};
#endif //VALIDATIONEXCEPTION_H
