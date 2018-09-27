cmake_minimum_required(VERSION 3.9)

project(RxC)

set(CMAKE_C_STANDARD 11)

set(Boost_INCLUDE_DIR /usr/local/Cellar/boost/1.65.0/include/)
set(Boost_LIBRARY_DIR /usr/local/Cellar/boost/1.65.0/lib/)
find_package(Boost 1.40 COMPONENTS program_options REQUIRED )

include_directories( ${Boost_INCLUDE_DIR} )
add_executable( RxC main.c src/c_lambda.h)
target_link_libraries( RxC ${CMAKE_THREAD_LIBS_INIT} ${Boost_LIBRARIES} ${Boost_SYSTEM_LIBRARY} ${Boost_PROGRAM_OPTIONS_LIBRARY} )