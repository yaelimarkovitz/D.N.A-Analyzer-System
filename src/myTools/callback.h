//
// Created by mby on 13/10/2020.
//

#ifndef UNTITLED_CALLBACK_H
#define UNTITLED_CALLBACK_H

#include <string>

class CallBackBase {

public:

    virtual ~CallBackBase(){};
    virtual char operator ()(std::string) = 0;
};

template <typename T>
class CharCBString :public CallBackBase{

public:
    CharCBString(T object, char(*T::*ptr)(std::string));
    char operator()(std::string);

private:

    char (*T::*m_funcPtr)(std::string);
    T  m_object;

};

template <typename T>
inline CharCBString<T>::CharCBString(T object, char (*T::*ptr)(std::string)) : m_funcPtr(ptr),m_object(object)
{
}

template <typename T>
inline char CharCBString<T>::operator()(std::string)
{
    (*m_object.*m_funcPtr());
}
#endif //UNTITLED_CALLBACK_H
