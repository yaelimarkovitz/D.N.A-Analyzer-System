//
// Created by mby on 14/07/2020.
//

#ifndef UNTITLED_ICOMMANDLINE_H
#define UNTITLED_ICOMMANDLINE_H
#include <vector>
#include <string>
#include <sstream>
#include "../conrollers/command_collection.h"
#include "../conrollers/ICommand.h"
#include "../IWrither.h"
#include "../IReader.h"
#include "../SharedPointer.h"

class ICommandLine{

public:

    ICommandLine(IWriter*,IReader*);
    ~ICommandLine();

    typedef std::vector <std::string> ParamsList;

    void            run();
    ParamsList      parseCommand(const std::string& str);
    std::string     executeCmd(ParamsList);

private:

    SharedPointer<CommandCollection>  m_cmdCollection;
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
{}

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
    std::istringstream my(str);
    std::string cuter;
    while(getline(my,cuter,' '))
    {
        params.push_back(cuter.c_str());
    }
    return params;
}

inline std::string ICommandLine::executeCmd(ParamsList params)
{
    m_curCmd  = ((m_cmdCollection))->getCmd(params[0]);

    if (m_curCmd==NULL)
        return "sorry, there is no command with this name please try again";

    return m_curCmd->execute(params);
}

#endif //UNTITLED_ICOMMANDLINE_H
