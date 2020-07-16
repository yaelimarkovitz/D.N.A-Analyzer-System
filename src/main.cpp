//
// Created by mby on 14/07/2020.
//
#include "console_reader.h"
#include "console_writher.h"
#include "system_controller.h"
int main(){
    IWrither*  write= new ConsoleWrither;
    IReader* reader = new ConsoleReader;
    write->write(reader->read());
    SystemController mySystem(write,reader);
    mySystem.initSystem();
    return 1;
}