//
// Created by mby on 14/07/2020.
//

#ifndef DNA_PROJECT_SYSTEM_CONTROLLER_H
#define DNA_PROJECT_SYSTEM_CONTROLLER_H


#include <iostream>


#include "../view/UI.h"
#include "command_collection.h"
#include "../myTools/writers/IWrither.h"
#include "../myTools/readers/IReader.h"
#include "../myTools/callback.h"



class SystemController {

public:

    typedef std::string (*callBack)(const std::string&,std::vector<std::string>);

    explicit SystemController(UI * userView);
    ~SystemController();

    static void initSystem();
    void run();
    static void quitSystem();

private:

    UI * m_userView;
    static std::string makeCallBack(const std::string&, std::vector<std::string> );

};

inline SystemController::SystemController( UI * userView):m_userView(userView)
{
    initSystem();
}

inline SystemController::~SystemController()
{
}

inline void SystemController::initSystem()
{
    std::cout<<"start system"<<std::endl;
}

inline void SystemController::run()
{
    callBack funcToExe = makeCallBack;
    m_userView-> run( funcToExe );
    quitSystem();
}

inline void SystemController::quitSystem()
{
    printf("finish system\n");
}

inline std::string SystemController::makeCallBack(const std::string& command, std::vector<std::string> params)
{
    return CommandCollection::getCmd(command)->execute(params);
}

#endif //DNA_PROJECT_SYSTEM_CONTROLLER_H
