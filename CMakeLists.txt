cmake_minimum_required(VERSION 3.10)
project(MyConsoleUtil)

set(CMAKE_C_STANDARD 11)

# Добавляем исполняемый файл
add_executable(pr2 main2.c users.c processes.c help.c log_PATH.c errors_PATH.c)

