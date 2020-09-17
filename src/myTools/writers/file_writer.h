//
// Created by mby on 13/09/2020.
//

#ifndef UNTITLED_FILE_WRITER_H
#define UNTITLED_FILE_WRITER_H

#include <iostream>
#include <fstream>

#include "IWrither.h"
using namespace std;

class FileWriter : public IWriter{

public:
    FileWriter(std::string &name);
    ~FileWriter(){};
    /*virtual*/ void write (const std::string &);

private:
    std::string     m_fileName;

};

inline FileWriter::FileWriter(std::string &name): m_fileName(name)
{}

inline void FileWriter::write(const std::string &output)
{
    std::ofstream myfile;
    myfile.open((m_fileName).c_str());
    if (myfile.is_open())
    {
        myfile << output;
        myfile << "\n";
        myfile.close();
    }
    else
        std::cout <<"enabale to open file"<<std::endl;
}


#endif //UNTITLED_FILE_WRITER_H
