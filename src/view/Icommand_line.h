//
// Created by mby on 14/07/2020.
//

#ifndef UNTITLED_ICOMMANDLINE_H
#define UNTITLED_ICOMMANDLINE_H
#include <vector>
#include <string>
#include "../conrollers/command_collection.h"
#include "../conrollers/ICommand.h"
#include "../IWrither.h"
#include "../IReader.h"

class ICommandLine{

public:

    ICommandLine(IWriter*,IReader*);
    ~ICommandLine();

    typedef std::vector <std::string> ParamsList;

    void            run();
    ParamsList      parseCommand(const std::string& str);
    std::string     executeCmd(ParamsList);

private:

    CommandCollection* m_cmdCollection;
    IWriter* m_writer;
    IReader* m_reader;
    ICommand* m_curCmd;
};

inline ICommandLine::ICommandLine( IWriter * write, IReader * read):
                m_cmdCollection(new CommandCollection()),
                m_writer(write),m_reader(read),
                m_curCmd(NULL)
{}

inline ICommandLine::~ICommandLine()
{
    delete m_cmdCollection;
}

inline void ICommandLine::run()
{

    std::string command = m_reader->read();

    while (command != "quit")
    {
        ParamsList params = parseCommand(command);
        std::string output = executeCmd(params);

        if(output!="None")
        {
            m_writer->write(output);
        }
        command = m_reader->read();
    }

}

inline ICommandLine::ParamsList ICommandLine::parseCommand(const std::string &str)
{
    ParamsList params;
    int len = 0;
    for (size_t i = 0; i < str.size() ; ++i)
    {
        if(str[i]==' ')
        {
            params.push_back(str.substr(((i-len)==0)? (0):(i-len+1),((i-len)==0)?len:len-1));
            len=0;
        }
        len++;
    }
    params.push_back(str.substr(str.size()-len+1,len-1));
    return params;
}

inline std::string ICommandLine::executeCmd(ParamsList params)
{
    m_curCmd  = m_cmdCollection->getCmd(params[0]);
    return m_curCmd->execute(params);
}

#endif //UNTITLED_ICOMMANDLINE_H
