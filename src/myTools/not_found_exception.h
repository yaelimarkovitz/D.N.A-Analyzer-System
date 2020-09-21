//
// Created by mby on 21/09/2020.
//

#ifndef UNTITLED_NOT_FOUND_EXCEPTION_H
#define UNTITLED_NOT_FOUND_EXCEPTION_H
#include <exception>
#include <iostream>
class NotExists : public std::exception{

    virtual const char* what() const throw();
};

inline const char* NotExists::what() const throw()
{
    return "sorry, this dna not exists please try again";
}
#endif //UNTITLED_NOT_FOUND_EXCEPTION_H
