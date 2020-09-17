//
// Created by mby on 16/07/2020.
//

#ifndef UNTITLED_LOAD_H
#define UNTITLED_LOAD_H

#include "../conrollers/ICommand.h"
#include "../dna_module/dna_data_base.h"
#include "../dna_module/dna_info.h"
#include "myTools/readers/file_reader.h"

class Load : public ICommand {

public:
    ~Load();
    /*virtual*/std::string execute(std::vector<std::string> params);

private:
    std::string         fileName;
    static const int    s_numOfParams = 2;
    static const int    s_indexOfFile = 1;
    static const int    s_indexOfName = 2;

    std::string     cutAt(const std::string& name);
};

inline Load::~Load()
{

}

inline std::string Load::execute(std::vector<std::string> params)
{
    if  (params.size() < s_numOfParams)
        return "sorry, but you enter too little params";

    DnaInfo * m_seq;
    IReader* file_reader = new FileReader(params[s_indexOfFile]);
    std::string name;

    if (params.size() == s_numOfParams+1)
        name = cutAt(params[s_indexOfName]);
    else
        name = NameGeneration<Load>::create(params[s_indexOfFile]);

    m_seq = new DnaInfo(file_reader,name);

    delete file_reader;
    return m_seq->getInfo();
}

inline std::string Load::cutAt(const std::string &name)
{
    return name.substr(1,name.size()-1);
}


#endif //UNTITLED_LOAD_H
