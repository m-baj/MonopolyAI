//
// Created by adrwal on 11/6/24.
//

#ifndef BOARDEXCEPTIONS_H
#define BOARDEXCEPTIONS_H

#include <stdexcept>
#include <string>

class InvalidMoveException : public std::runtime_error {
public:
    explicit InvalidMoveException(const std::string& message)
        : std::runtime_error(message) {}
};


#endif//BOARDEXCEPTIONS_H
