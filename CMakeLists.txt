cmake_minimum_required(VERSION 3.4.1)

set(JNI "/Library/Java/JavaVirtualMachines/jdk1.8.0_131.jdk/Contents/Home/include")
set(JNI_DARWIN "/Library/Java/JavaVirtualMachines/jdk1.8.0_131.jdk/Contents/Home/include/darwin")
set(PWD ${CMAKE_CURRENT_SOURCE_DIR})
set(CMAKE_CXX_FLAGS "-std=c++11")
include_directories(${PWD}/include)
include_directories(${JNI})
include_directories(${JNI_DARWIN})


add_subdirectory(${PWD}/src)

add_executable(main ${PWD}/main.cpp include/jni_main.h)
target_link_libraries(main foo)