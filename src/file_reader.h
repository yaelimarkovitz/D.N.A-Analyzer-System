//
// Created by mby on 02/08/2020.
//

#ifndef UNTITLED_FILE_READER_H
#define UNTITLED_FILE_READER_H
#include <fstream>
#include <iostream>
#include <string>
#include "IReader.h"


class FileReader :public IReader{

public:

    FileReader(const std::string& name);
    ~FileReader(){};
    std::string read ();

private:

    std::string m_fileName;
};

inline FileReader::FileReader(const std::string &name):m_fileName(name)
{}

inline std::string FileReader::read()
{

    std::fstream newFile;
    newFile.open(m_fileName,std::ios::in);
    std::string buffer;
    if(newFile.is_open())
    {
        getline(newFile,buffer);
        newFile.close();
    }
    return buffer;

}

#endif //UNTITLED_FILE_READER_H
