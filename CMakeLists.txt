cmake_minimum_required(VERSION 3.9)

project(RxC)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_COMPILER  "/usr/local/Cellar/gcc/8.2.0/bin/gcc-8")

set(Boost_INCLUDE_DIR /usr/local/Cellar/boost/1.65.0/include/)
set(Boost_LIBRARY_DIR /usr/local/Cellar/boost/1.65.0/lib/)
find_package(Boost 1.40 COMPONENTS program_options REQUIRED )

include_directories(/usr/local/include ${Boost_INCLUDE_DIR} )

file(GLOB_RECURSE HEADER RELATIVE ${CMAKE_SOURCE_DIR} "src/*.h")
file(GLOB_RECURSE SOURCES RELATIVE ${CMAKE_SOURCE_DIR} "src/*.c")
add_executable(RxC main2.c ${HEADER} ${SOURCES} src/smart_pointer.h src/smart_pointer.c)
target_link_libraries( RxC ffcall ${CMAKE_THREAD_LIBS_INIT} ${Boost_LIBRARIES} ${Boost_SYSTEM_LIBRARY} ${Boost_PROGRAM_OPTIONS_LIBRARY} )