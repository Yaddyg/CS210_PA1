cmake_minimum_required(VERSION 4.3)
project(PA1)

set(CMAKE_CXX_STANDARD 20)

add_executable(PA1 main.cpp
        Stack.h
        Node.h
        List.h
        LinkedList.h
        ArrayList.h
        Data.h)
