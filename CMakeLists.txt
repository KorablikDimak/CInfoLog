cmake_minimum_required(VERSION 3.22)

project(CInfoLog)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_LIBRARIES "-static-libgcc -static-libstdc++ -lwsock32 -lws2_32 ${CMAKE_CXX_STANDARD_LIBRARIES}")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,-Bstatic,--whole-archive -lwinpthread -Wl,--no-whole-archive")

set(Headers Configuration.h FileSender.h ISender.h Logger.h LoggerFactory.h LogLevel.h)
set(Source Configuration.cpp FileSender.cpp ISender.cpp Logger.cpp LoggerFactory.cpp)

add_library(CInfoLog SHARED ${Headers} ${Source})