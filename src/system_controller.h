//
// Created by mby on 14/07/2020.
//

#ifndef DNA_PROJECT_SYSTEM_CONTROLLER_H
#define DNA_PROJECT_SYSTEM_CONTROLLER_H

#include <iostream>
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
    std::cout<<"<<cmd< ";
    std::getline(std::cin,buffer,'\n');
    while(buffer!="quit"){
        m_curCmd = CmdFactory::createCommand(buffer);
        buffer = m_curCmd->execute();
        std::cout<<buffer<<std::endl;
        std
        std::cout<<"<<cmd< ";
        std::getline(std::cin,buffer,'\n');
    }
    quitSystem();
}

inline void SystemController::quitSystem() {
    printf("finish system\n");
}
#endif //DNA_PROJECT_SYSTEM_CONTROLLER_H
