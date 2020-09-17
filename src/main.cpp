//
// Created by mby on 14/07/2020.
//
#include "myTools/readers/console_reader.h"
#include "myTools/writers/console_writher.h"
#include "conrollers/system_controller.h"
int main(){
    IWriter*  writer= new ConsoleWriter;
    IReader* reader = new ConsoleReader;

    SystemController mySystem(writer,reader);
    mySystem.run();

    delete writer;
    delete reader;

    return 1;
}