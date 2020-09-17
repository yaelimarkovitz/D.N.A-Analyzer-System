cmake_minimum_required(VERSION 3.14)
project(dna_analyzer_project_y_c_mby)

set(CMAKE_CXX_STANDARD 98)

include_directories(src)
include_directories(src/commands_module)
include_directories(src/conrollers)
include_directories(src/dna_module)
include_directories(src/view)

add_executable(dna_analyzer_project_y_c_mby
        src/commands_module/commands.h
        src/commands_module/dup.h
        src/commands_module/find.h
        src/commands_module/len.h
        src/commands_module/load.h
        src/commands_module/name_genaration.h
        src/commands_module/new_cmd.h
        src/commands_module/save.h
        src/commands_module/slice.h
        src/conrollers/command_collection.h
        src/conrollers/ICommand.h
        src/conrollers/system_controller.h
        src/dna_module/dna_data_base.cpp
        src/dna_module/dna_data_base.h
        src/dna_module/dna_info.cpp
        src/dna_module/dna_info.h
        src/dna_module/dna_sequence.cpp
        src/dna_module/dna_sequence.h
        src/dna_module/my_exception.h
        src/view/Icommand_line.h
        src/myTools/readers/console_reader.h
        src/myTools/writers/console_writher.h
        src/myTools/readers/file_reader.h
        src/myTools/writers/file_writer.h
        src/myTools/readers/IReader.h
        src/myTools/writers/IWrither.h
        src/main.cpp
        src/myTools/SharedPointer.h)
