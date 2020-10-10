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
    void            printStartMessage() const;
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
    printStartMessage();
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
        catch (const exception& e)
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


inline void CommandLine::printStartMessage() const
{
    m_writer->write("Welcome to D.N.A Analyzer System\nhere some rules that helps you use this product\n"
                    "1. Reference to the sequence number is done using th hash charcter : #\n"
                    "2. Reference to the sequence name is done using th at charcter : @\n"
                    "3 . To shut down the system use the command quit\n"
                    "4. To get all the commands type help\n"
                    "Good Luck:)");
}
#endif //UNTITLED_ICOMMANDLINE_H
