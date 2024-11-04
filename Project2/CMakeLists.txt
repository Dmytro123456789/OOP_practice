cmake_minimum_required(VERSION 3.29)
project(Project2)

set(CMAKE_CXX_STANDARD 14)

include_directories(Project)

add_executable(Project2
    Project/Base.cpp
    Project/Base.h
    Project/main.cpp
    Project/PassengerTrain.cpp
    Project/PassengerTrain.h
    Project/Plain.cpp
    Project/Plain.h
    Project/Vector.h
        Project/Vector.tpp
        Project/Vector.tpp)
