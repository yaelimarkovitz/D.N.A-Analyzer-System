//
// Created by mby on 11/10/2020.
//

#ifndef UNTITLED_REPLACE_H
#define UNTITLED_REPLACE_H

#include "../conrollers/ICommand.h"
#include "../dna_module/dna_data_base.h"

class Replace :public ICommand{
public:
    ~Replace() override{};
    /*virtual*/std::string execute(std::vector<std::string> params) override;

private:
    static const int    s_minNumOfParams = 4;
    static const int    s_indexOfSeq = 1;

    std::string     cutSign(const std::string& name);
    std::string     convertToName(const std::string &seq);
    std::string     provideNewSeq(const std::vector<std::string> &params);
    std::string     changeCurrSeq(const std::vector<std::string> &params);
    std::string     getName(const std::vector<std::string>& params);
    bool            isProvideNewSeq(const std::vector<std::string> &params);

    SharedPointer<DnaSequence> concatAllSeqs(const std::vector<std::string> &params, int size);
};

inline  std::string Replace::execute(std::vector<std::string> params) 
{
    if (params.size()< s_minNumOfParams)
        throw TooLittleParams();

    return "hi";
    
}
#endif //UNTITLED_REPLACE_H
