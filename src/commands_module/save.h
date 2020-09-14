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
    std::string         cutAt(const std::string& name);//todo check what happen if ther is no dna with that name
    std::string         m_fileName;
};

inline std::string Save::execute(std::vector<std::string> params) {


    if ( params.size() < numOfParams)
        return "sorry, but you enter too little params";

    if (params.size() == numOfParams){
        m_fileName = params[s_indexOfFileName];
    }
    else
        m_fileName =NameGeneration<Save>::create(cutAt(params[s_indexOfDnaSeq]));

    IWriter * writer = new FileWriter(m_fileName);

    DnaDataBase::findByName(cutAt(params[s_indexOfDnaSeq]))->getDna().output(writer);//TODO add option to insert id

    return "None";
}

inline std::string Save::cutAt(const std::string &name)
{
    return name.substr(1,name.size()-1);
}


#endif //UNTITLED_SAVE_H
