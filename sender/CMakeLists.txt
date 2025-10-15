cmake_minimum_required(VERSION 3.14)

project(sender LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Network)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Network)

add_executable(sender
  main.cpp
  udphandler.cpp
  udphandler.h

)
target_link_libraries(sender Qt${QT_VERSION_MAJOR}::Network)


