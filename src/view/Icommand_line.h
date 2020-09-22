//
// Created by mby on 14/07/2020.
//

#ifndef UNTITLED_ICOMMANDLINE_H
#define UNTITLED_ICOMMANDLINE_H
#include <vector>
#include <string>
#include <sstream>
#include "../myTools/writers/IWrither.h"
#include "../myTools/readers/IReader.h"
#include "UI.h"

class CommandLine : public UI{

public:


    CommandLine(IWriter*, IReader*);
    ~CommandLine();

    typedef std::vector <std::string> ParamsList;

    void            run(callBack exeFunc);
    ParamsList      parseCommand(const std::string& str);

private:

    IWriter* m_writer;
    IReader* m_reader;

};

inline CommandLine::CommandLine(IWriter * write, IReader * read):m_writer(write),m_reader(read)
{}

inline CommandLine::~CommandLine()
{}

inline void CommandLine::run(callBack exeFunc)
{
    std::string command;

    while (true)
    {
        command = m_reader->read();

        if (command.empty())
            continue;
        if (command=="quit")
            break;

        ParamsList params = parseCommand(command);
        try
        {
            std::string output = exeFunc (params[0], params);
            if(output!="None")
            {
                m_writer->write(output);
            }
        }
        catch (exception& e)
        {
            m_writer->write(e.what());
        }
    }
}

inline CommandLine::ParamsList CommandLine::parseCommand(const std::string &str)
{
    ParamsList params;
    std::istringstream my(str);
    std::string cuter;
    while(getline(my,cuter,' '))
    {
        params.push_back(cuter.c_str());
    }
    return params;
}



#endif //UNTITLED_ICOMMANDLINE_H
