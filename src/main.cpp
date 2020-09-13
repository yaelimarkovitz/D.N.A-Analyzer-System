//
// Created by mby on 14/07/2020.
//
#include "console_reader.h"
#include "console_writher.h"
#include "conrollers/system_controller.h"
int main(){
    IWriter*  write= new ConsoleWriter;
    IReader* reader = new ConsoleReader;

    SystemController mySystem(write,reader);
    mySystem.initSystem();

    delete write;
    delete reader;

    return 1;
}