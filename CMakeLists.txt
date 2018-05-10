cmake_minimum_required(VERSION 3.9)

project(RxC)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_COMPILER  "/usr/bin/g++-7")

find_package( Boost 1.40 COMPONENTS program_options REQUIRED )
include_directories( ${Boost_INCLUDE_DIR} )
add_executable( RxC main.c src/rxc_creating.h)
target_link_libraries( RxC ${CMAKE_THREAD_LIBS_INIT} ${Boost_LIBRARIES} ${Boost_SYSTEM_LIBRARY} ${Boost_PROGRAM_OPTIONS_LIBRARY} )