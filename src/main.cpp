//
// Created by mby on 14/07/2020.
//
#include "myTools/readers/console_reader.h"
#include "myTools/writers/console_writher.h"
#include "controllers/system_controller.h"
#include "view/Icommand_line.h"

int main(){
    IWriter*  writer= new ConsoleWriter;
    IReader* reader = new ConsoleReader;
    UI * CLI = new CommandLine(writer, reader);

    SystemController mySystem(CLI);
    mySystem.run();

    delete CLI;
    delete writer;
    delete reader;

    return 1;
}