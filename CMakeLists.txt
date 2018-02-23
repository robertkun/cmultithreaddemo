cmake_minimum_required(VERSION 3.5)
project(cmultithreaddemo)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES source/main.cpp source/handleTrd.cpp include/handleTrd.h source/sendTrd.cpp include/sendTrd.h source/sendMgr.cpp include/sendMgr.h include/com.h)
add_executable(cmultithreaddemo ${SOURCE_FILES})