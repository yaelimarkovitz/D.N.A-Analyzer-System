//
// Created by mby on 11/10/2020.
//

#ifndef UNTITLED_NOT_FOUND_COMMAND_H
#define UNTITLED_NOT_FOUND_COMMAND_H

#include <exception>
#include <iostream>

class NotFoundCommand : public std::exception{

    virtual const char* what() const throw();
};

inline const char* NotFoundCommand::what() const throw()
{
    return "Sorry,but this command not found";
}
#endif //UNTITLED_NOT_FOUND_COMMAND_H
