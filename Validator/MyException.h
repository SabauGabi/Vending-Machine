//
// Created by Gabi on 5/25/2025.
//

#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H
#include <stdexcept>
#include <string>

class MyException : public std::exception {
private:
    std::string message;
public:
    explicit MyException(const std::string& msg) : message(msg) {}
    const char* what() const noexcept override {
        return message.c_str();
    }
};
#endif //MYEXCEPTION_H
