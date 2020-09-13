//
// Created by mby on 16/07/2020.
//

#ifndef UNTITLED_LOAD_H
#define UNTITLED_LOAD_H

#include "../conrollers/ICommand.h"
#include "../dna_module/dna_data_base.h"
#include "../dna_module/dna_info.h"
#include "../file_reader.h"

class Load : public ICommand {

public:
    ~Load();
    /*virtual*/std::string execute(std::vector<std::string> params);

private:
    DnaInfo*            m_seq;
    std::string         fileName;
    static const int    s_numOfParams = 3;

    std::string     generateName(const std::string& fileName);
    std::string     itoa(int num);
    std::string     cutAt(const std::string& name);
};

inline Load::~Load()
{
    delete m_seq;
}

inline std::string Load::execute(std::vector<std::string> params)
{
    if  (params.size() < s_numOfParams)
        throw std::runtime_error("not enogh params");

    if(m_seq!=NULL)
        delete m_seq;

    IReader* file_reader = new FileReader(params[1]);
    std::string name;
    if (params.size() == s_numOfParams)
        name = cutAt(params[2]);
    else
        name = generateName(params[1]);

    m_seq = new DnaInfo(file_reader,name);
    delete file_reader;
    return m_seq->getInfo();
}

inline std::string Load::cutAt(const std::string &name)
{
    return name.substr(1,name.size()-1);
}

inline std::string Load::generateName(const std::string& fileName)
{
    static size_t number = 0;
    number++;
    return (fileName.substr(0,fileName.find("."))+itoa(number));
}

inline std::string Load::itoa(int num) {
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
#endif //UNTITLED_LOAD_H
