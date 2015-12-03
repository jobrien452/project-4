cmake_minimum_required(VERSION 3.2)
project(QtMarkup CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_FLAGS "-std=c++11 -pthread")
find_package(Qt4 REQUIRED QtTest)
INCLUDE(${QT_USE_FILE})

#QT4_WRAP_CPP(MOCSrcs window.h parse.h)

include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR})

add_executable(pong main.cpp model.cpp engine.cpp view.cpp) # ${MOCSrcs})
add_executable(pongTest mytest.cpp model.cpp engine.cpp view.cpp snapshot.cpp)

target_link_libraries(pong Qt4::QtGui)
target_link_libraries(pongTest Qt4::QtGui Qt4::QtTest)

enable_testing()

add_test(ptest pongTest)
