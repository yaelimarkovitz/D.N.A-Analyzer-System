cmake_minimum_required(VERSION 3.14)
project(src)

set(CMAKE_CXX_STANDARD 11)

include_directories(controllers)
include_directories(model/commands_module)
include_directories(model/dna_module)
include_directories(myTools)
include_directories(myTools/readers)
include_directories(myTools/writers)
include_directories(view)

add_executable(src
        controllers/command_collection.cpp
        controllers/command_collection.h
        controllers/ICommand.h
        controllers/system_controller.h
        model/commands_module/commands.h
        model/commands_module/concat.h
        model/commands_module/count.h
        model/commands_module/dup.h
        model/commands_module/find.h
        model/commands_module/find_all.h
        model/commands_module/len.h
        model/commands_module/list.h
        model/commands_module/load.h
        model/commands_module/name_genaration.h
        model/commands_module/new_cmd.h
        model/commands_module/pair.h
        model/commands_module/rename.h
        model/commands_module/replace.h
        model/commands_module/save.h
        model/commands_module/show.h
        model/commands_module/slice.h
        model/dna_module/dna_data_base.cpp
        model/dna_module/dna_data_base.h
        model/dna_module/dna_info.cpp
        model/dna_module/dna_info.h
        model/dna_module/dna_sequence.cpp
        model/dna_module/dna_sequence.h
        model/dna_module/my_exception.h
        myTools/readers/console_reader.h
        myTools/readers/file_reader.h
        myTools/readers/IReader.h
        myTools/writers/console_writher.h
        myTools/writers/file_writer.h
        myTools/writers/IWrither.h
        myTools/not_found_command.h
        myTools/not_found_exception.h
        myTools/SharedPointer.h
        myTools/too_little_params_exception.h
        view/Icommand_line.h
        view/UI.h
        main.cpp)
