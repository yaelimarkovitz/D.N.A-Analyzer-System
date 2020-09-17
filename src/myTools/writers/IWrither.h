//
// Created by mby on 16/07/2020.
//

#ifndef UNTITLED_IWRITHER_H
#define UNTITLED_IWRITHER_H

struct IWriter{

    virtual ~IWriter(){};
    virtual void write (const std::string &) = 0;
};

#endif //UNTITLED_IWRITHER_H
