//
// Created by mby on 16/07/2020.
//

#ifndef UNTITLED_IREADER_H
#define UNTITLED_IREADER_H

struct IReader{

    virtual ~IReader(){};
    virtual std::string read () = 0;
};
#endif //UNTITLED_IREADER_H
