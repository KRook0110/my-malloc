cmake_minimum_required(VERSION 3.0)
project(regalloc)

# compile_commands.json for clangd
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# include folder
include_directories(include/)

# add source files
add_executable(regalloc
    src/main.c
    src/utils.c
    src/regalloc.c
    src/container.c
    src/arena.c
)





