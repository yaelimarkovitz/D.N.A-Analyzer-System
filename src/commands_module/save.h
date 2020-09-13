//
// Created by mby on 16/07/2020.
//

#ifndef UNTITLED_SAVE_H
#define UNTITLED_SAVE_H

#include "../dna_module/dna_data_base.h"
#include "../conrollers/ICommand.h"
#include "../file_writer.h"

class Save : public ICommand {

public:

    ~Save(){};
    /*virtual*/std::string execute(std::vector<std::string> params);

private:
    static const int    numOfParams = 3;
    static const int    s_indexOfFileName = 2;
    static const int    s_indexOfDnaSeq = 1;
    std::string         cutAt(const std::string& name);
    std::string         generateName(const std::string& seqName);
    std::string         itoa(int num);
    std::string         m_fileName;
};

inline std::string Save::execute(std::vector<std::string> params) {


    if ( params.size() < numOfParams)
        throw std::runtime_error("no valid params");

    if (params.size() == numOfParams){
        m_fileName = params[s_indexOfFileName];
    }
    else
        m_fileName = generateName(cutAt(params[s_indexOfDnaSeq]));

    IWriter * writer = new FileWriter(m_fileName);

    DnaDataBase::findByName(cutAt(params[s_indexOfDnaSeq]))->getDna().output(writer);

    return "None";
}

inline std::string Save::cutAt(const std::string &name)
{
    return name.substr(1,name.size()-1);
}

inline std::string Save::generateName(const std::string& seqName)
{
    static size_t number = 0;
    number++;
    return (seqName.substr(0,seqName.find("."))+itoa(number));
}

inline std::string Save::itoa(int num) {
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
#endif //UNTITLED_SAVE_H
