//
// Created by mby on 14/07/2020.
//

#ifndef UNTITLED_ICOMMANDLINE_H
#define UNTITLED_ICOMMANDLINE_H
#include <vector>
#include <string>
#include "command_collection.h"
#include "Icommand.h"
#include "IWrither.h"
#include "IReader.h"

class ICommandLine{
public:
    ICommandLine(IWrither*,IReader*);
    void run();
    std::vector<std::string> parseCommand(const std::string& str);
    std::string executeCmd(std::vector<std::string> params);
private:
    CommandCollection* m_cmdCollection;
    IWrither* m_writher;
    IReader* m_reader;
    Icommand* m_curCmd;
};

inline ICommandLine::ICommandLine( IWrither * write, IReader * read):m_cmdCollection(new CommandCollection()),m_writher(write),m_reader(read),m_curCmd(NULL) {
}

inline void ICommandLine::run() {
    std::string command , output;
    std::vector<std::string> params;
    command = m_reader->read();
    while(command!="quit"){
        params = parseCommand(command);
        output = executeCmd(params);
        m_writher->write(output);
        command = m_reader->read();
    }
}

inline std::vector<std::string> ICommandLine::parseCommand(const std::string &str) {
    std::vector<std::string> params;
    int len = 0;
    for (size_t i = 0; i < str.size() ; ++i) {
        if(str[i]==' '){
            params.push_back(str.substr(i-len,len));
            len=0;
        }
        len++;
    }
    params.push_back(str.substr(str.size()-len,len));
    return params;
}

inline std::string ICommandLine::executeCmd(std::vector<std::string> params) {
    m_curCmd= m_cmdCollection->getCmd(params[0]);
    return m_curCmd->execute(params);
}

#endif //UNTITLED_ICOMMANDLINE_H
