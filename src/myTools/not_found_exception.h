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
    return "Sorry, this dna not exists please try again \nPlease check if you type the feet sign";
}
#endif //UNTITLED_NOT_FOUND_EXCEPTION_H
