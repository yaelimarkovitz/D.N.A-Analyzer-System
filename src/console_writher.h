//
// Created by mby on 16/07/2020.
//

#ifndef UNTITLED_CONSOLE_WRITHER_H
#define UNTITLED_CONSOLE_WRITHER_H

#include <iostream>
#include "IWrither.h"

class ConsoleWrither: public IWrither {
public:
    void write(const std::string&);
};

inline void ConsoleWrither::write(const std::string & output) {
    std::cout<< output<<std::endl;
}


#endif //UNTITLED_CONSOLE_WRITHER_H
