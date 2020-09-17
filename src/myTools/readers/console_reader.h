//
// Created by mby on 16/07/2020.
//

#ifndef UNTITLED_CONSOLE_READER_H
#define UNTITLED_CONSOLE_READER_H

#include <iostream>
#include "IReader.h"
class ConsoleReader :public IReader{

public:
    std::string read();
};

inline std::string ConsoleReader::read() {

    std::cout<<"cmd>>"<<std::endl;
    std::string input;
    std::getline(std::cin,input,'\n');
    return input;
}




#endif //UNTITLED_CONSOLE_READER_H
