//
// Created by mby on 14/09/2020.
//

#ifndef UNTITLED_NAME_GENARATION_H
#define UNTITLED_NAME_GENARATION_H

#include <string>

template <typename T>
class NameGeneration{
public:
    static std::string create (const std::string &);
    static std::string itoa(int num);
};

template <typename T>
inline std::string NameGeneration<T>::create(const std::string &pattern)
{
    static size_t number = 0;
    number++;
    return (pattern.substr(0,pattern.find("."))+itoa(number));
}

template <typename T>
inline std::string NameGeneration<T>::itoa(int num) {
    std::string ss = "";
    while(num)
    {
        int x = num % 10;
        num /= 10;
        char i = '0';
        i = i + x ;
        ss = i + ss;
    }
    return ss;
}
#endif //UNTITLED_NAME_GENARATION_H
