ke_minimum_required(VERSION 3.10)
project(Nexlify)

set(CMAKE_CXX_STANDARD 17)
find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_executable(Nexlify src/main.cpp)
target_link_libraries(Nexlify Qt5::Widgets)
