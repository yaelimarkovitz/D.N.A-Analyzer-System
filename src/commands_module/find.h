//
// Created by mby on 15/09/2020.
//

#ifndef UNTITLED_FIND_H
#define UNTITLED_FIND_H

#include "../conrollers/ICommand.h"

class Find:public ICommand{
public:
    ~Slice(){};
    /*virtual*/std::string execute(std::vector<std::string> params);

private:
    static const int    s_numOfParams = 3;
    static const int    s_numofSeq1 = 1;
    static const int    s_numOfSeq2 = 2;

    std::string     cutSign(const std::string& name);
    bool            isSign();
    std::string     findDna(int seq1,std::sring seq2);
    std::string     findDna(int seq1,int seq2);
    std::string     findDna(std::string seq1,int seq2);
    std::string     findDna(std::string seq1,std::sring seq2);
    std::string     findExpressed(std::string, std::string)
};

inline std::string Find::execute(std::vector<std::string> params)
{

    if (params.size() < s_numOfParams)
        return "sorry,but you enter too little params";

//    if (isSign(params[s_numOfSeq2]))
//        return findDnaS((params[s_numofSeq1]),(params[s_numOfSeq2]))
//
//    return findExpressed((params[s_numOfSeq1]),params[s_numofSeq2])

}



inline std::string Find::cutSign(const std::string &name)
{
    return name.substr(1,name.size()-1);
}
#endif //UNTITLED_FIND_H
