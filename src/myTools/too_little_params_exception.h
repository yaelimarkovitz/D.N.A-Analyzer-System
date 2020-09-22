//
// Created by mby on 22/09/2020.
//

#ifndef UNTITLED_TOO_LITTLE_PARAMS_EXCEPTION_H
#define UNTITLED_TOO_LITTLE_PARAMS_EXCEPTION_H
#include <exception>
#include <iostream>

class TooLittleParams : public std::exception{

    virtual const char* what() const throw();
};

inline const char* TooLittleParams::what() const throw()
{
    return "sorry,but you enter too little params";;
}

#endif //UNTITLED_TOO_LITTLE_PARAMS_EXCEPTION_H
