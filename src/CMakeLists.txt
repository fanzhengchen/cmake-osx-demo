cmake_minimum_required(VERSION 3.4.1)

include_directories(${CMAKE_SOURCE_DIR}/include)

FILE(GLOB SOURCE *.cpp)

add_library(foo SHARED ${SOURCE} jni_main.cpp demo_jvm.cpp)

#set_target_properties(foo PROPERTIES SUFFIX .so)

