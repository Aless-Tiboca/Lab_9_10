//
// Created by alext on 17/05/2022.
//

#ifndef LAB_9_10_EXCEPTION_H
#define LAB_9_10_EXCEPTION_H

#include <exception>

class Exception : public std::exception {
private:
    const char *message;
public:
    /**
     * Constructor
     */
    Exception(const char *message) : message(message) {}

    /**
     * Getter for exception message
     */
    const char *what() const noexcept override {
        return message;
    }
};

#endif //LAB_9_10_EXCEPTION_H
