//
// Created by mby on 14/07/2020.
//

#ifndef DNA_PROJECT_SYSTEM_CONTROLLER_H
#define DNA_PROJECT_SYSTEM_CONTROLLER_H

#include <iostream>


#include "Icommand_line.h"
#include "command_collection.h"
#include "IWrither.h"
#include "IReader.h"

class SystemController {

public:
    SystemController(IWrither* write , IReader* read);
    ~SystemController();
    void initSystem();
    void run();
    void quitSystem();
private:

    ICommandLine * m_cmd;
};

inline SystemController::SystemController( IWrither *write, IReader *read):m_cmd(new ICommandLine(write,read)) {
}

inline SystemController::~SystemController() {
    delete m_cmd;
}

inline void SystemController::initSystem() {
    std::cout<<"start system"<<std::endl;
    run();
}

inline void SystemController::run() {
    m_cmd->run();
    quitSystem();
}

inline void SystemController::quitSystem() {
    printf("finish system\n");
}
#endif //DNA_PROJECT_SYSTEM_CONTROLLER_H
