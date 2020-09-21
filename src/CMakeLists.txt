cmake_minimum_required(VERSION 3.14)
project(src)

set(CMAKE_CXX_STANDARD 14)

include_directories(commands_module)
include_directories(conrollers)
include_directories(dna_module)
include_directories(myTools)
include_directories(myTools/readers)
include_directories(myTools/writers)
include_directories(view)

add_executable(src
        commands_module/commands.h
        commands_module/dup.h
        commands_module/find.h
        commands_module/len.h
        commands_module/load.h
        commands_module/name_genaration.h
        commands_module/new_cmd.h
        commands_module/save.h
        commands_module/slice.h
        conrollers/command_collection.cpp
        conrollers/command_collection.h
        conrollers/ICommand.h
        conrollers/system_controller.h
        dna_module/dna_data_base.cpp
        dna_module/dna_data_base.h
        dna_module/dna_info.cpp
        dna_module/dna_info.h
        dna_module/dna_sequence.cpp
        dna_module/dna_sequence.h
        dna_module/my_exception.h
        myTools/readers/console_reader.h
        myTools/readers/file_reader.h
        myTools/readers/IReader.h
        myTools/writers/console_writher.h
        myTools/writers/file_writer.h
        myTools/writers/IWrither.h
        myTools/SharedPointer.h
        view/Icommand_line.h
        view/UI.h
        main.cpp commands_module/find_all.h commands_module/count.h commands_module/rename.h commands_module/list.h)
