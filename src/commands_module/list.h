//
// Created by mby on 21/09/2020.
//

#ifndef UNTITLED_LIST_H
#define UNTITLED_LIST_H
#include "../conrollers/ICommand.h"

class List :public ICommand{
public:
    ~List(){};
    /*virtual*/std::string execute(std::vector<std::string> params);

private:
    static const int  s_nunOfParams = 1;
};

inline std::string List::execute(std::vector<std::string> params)
{
    if (params.size() < s_nunOfParams)
        throw TooLittleParams();


}
#endif //UNTITLED_LIST_H
