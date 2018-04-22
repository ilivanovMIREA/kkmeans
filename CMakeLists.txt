cmake_minimum_required(VERSION 3.2)

project(kkmeans)

find_package(dlib REQUIRED)

add_executable(kkmeans main.cpp)

set_target_properties(kkmeans PROPERTIES
        CXX_STANDARD 14
        CXX_STANDARD_REQUIRED ON
        COMPILE_OPTIONS -Wpedantic -Wall -Wextra
        )

target_link_libraries(kkmeans dlib::dlib)

install(TARGETS kkmeans RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT ya.ilivanov@yandex.ru)

include(CPack)
