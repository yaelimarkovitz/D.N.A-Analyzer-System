//
// Created by mby on 14/07/2020.
//

#ifndef DNA_PROJECT_SYSTEM_CONTROLLER_H
#define DNA_PROJECT_SYSTEM_CONTROLLER_H

#include <iostream>


#include "../view/Icommand_line.h"
#include "command_collection.h"
#include "myTools/writers/IWrither.h"
#include "myTools/readers/IReader.h"

class SystemController {

public:

    SystemController(IWriter* write , IReader* read);
    ~SystemController();

    void initSystem();
    void run();
    void quitSystem();

private:

    ICommandLine * m_cmd;
};

inline SystemController::SystemController( IWriter *write, IReader *read):m_cmd(new ICommandLine(write,read))
{
    initSystem();
}

inline SystemController::~SystemController()
{
    delete m_cmd;
}

inline void SystemController::initSystem()
{
    std::cout<<"start system"<<std::endl;
}

inline void SystemController::run()
{
    m_cmd->run();
    quitSystem();
}

inline void SystemController::quitSystem()
{
    printf("finish system\n");
}
#endif //DNA_PROJECT_SYSTEM_CONTROLLER_H
