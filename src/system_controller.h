//
// Created by mby on 14/07/2020.
//

#ifndef DNA_PROJECT_SYSTEM_CONTROLLER_H
#define DNA_PROJECT_SYSTEM_CONTROLLER_H

#include <iostream>
#include <vector>
//#include "Icommand_line.h"
#include "dna_data_base.h"
#include "cmd_factory.h"

class SystemController {
public:
    static void initSystem();
    static void run();
    static void quitSystem();
private:
    static Icommand * m_curCmd;
//    ICommandLine * m_cmd;
};
inline void SystemController::initSystem() {
    std::cout<<"start system"<<std::endl;
    run();
}

inline void SystemController::run() {
    std::string buffer;
    std::vector<std::string> params;
    int len=0;
    std::cout<<"<<cmd< ";
    std::getline(std::cin,buffer,'\n');
    while(buffer!="quit"){
        for (size_t i = 0; i < buffer.size() ; ++i) {
            if(buffer[i]==' '){
                params.push_back(buffer.substr(i-len,len));
                len=0;
            }
            len++;
        }
        params.push_back(buffer.substr(buffer.size()-len,len));
        m_curCmd = CmdFactory::createCommand(params[0]);
        buffer = m_curCmd->execute(params);
        std::cout<<buffer<<std::endl;
        std::cout<<"<<cmd< ";
        std::getline(std::cin,buffer,'\n');
        params.clear();
        len = 0;
    }
    quitSystem();
}

inline void SystemController::quitSystem() {
    printf("finish system\n");
}
#endif //DNA_PROJECT_SYSTEM_CONTROLLER_H
