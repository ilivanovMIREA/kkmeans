cmake_minimum_required(VERSION 2.8.12)

project(kkmeans)



find_package(dlib REQUIRED)

add_executable(
   kkmeans
   kkmeans/main.cpp
)

target_link_libraries(kkmeans dlib::dlib)