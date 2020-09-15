//
// Created by mby on 16/07/2020.
//

#ifndef UNTITLED_SAVE_H
#define UNTITLED_SAVE_H

#include "../dna_module/dna_data_base.h"
#include "../conrollers/ICommand.h"
#include "../file_writer.h"
#include <iostream>

class Save : public ICommand {

public:

    ~Save(){};
    /*virtual*/std::string execute(std::vector<std::string> params);

private:
    static const int    numOfParams = 3;
    static const int    s_indexOfFileName = 2;
    static const int    s_indexOfDnaSeq = 1;
    std::string         cutSign(const std::string& name);//todo check what happen if ther is no dna with that name
    std::string         m_fileName;
};

inline std::string Save::execute(std::vector<std::string> params) {


    if ( params.size() < numOfParams)
        return "sorry, but you enter too little params";

    if (params.size() == numOfParams){
        m_fileName = params[s_indexOfFileName];
    }
    else
        m_fileName  = NameGeneration<Save>::create(cutSign(params[s_indexOfDnaSeq]));

    IWriter * writer = new FileWriter(m_fileName);
    std::string help = cutSign(params[s_indexOfDnaSeq]);

    switch (params[s_indexOfDnaSeq][0])
    {
        case s_nameSign: DnaDataBase::findDna(cutSign(params[s_indexOfDnaSeq]))->getDna().output(writer);
            break;
        case s_idSign: DnaDataBase::findDna(atoi(help.c_str()))->getDna().output(writer);
            break;
    }

    return "None";
}

inline std::string Save::cutSign(const std::string &name)
{
    return name.substr(1,name.size()-1);
}


#endif //UNTITLED_SAVE_H
