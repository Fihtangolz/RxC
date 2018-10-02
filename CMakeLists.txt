cmake_minimum_required(VERSION 3.9)

project(RxC)

set(CMAKE_C_STANDARD 11)

set(Boost_INCLUDE_DIR /usr/local/Cellar/boost/1.65.0/include/)
set(Boost_LIBRARY_DIR /usr/local/Cellar/boost/1.65.0/lib/)
find_package(Boost 1.40 COMPONENTS program_options REQUIRED )

include_directories(/usr/local/include ${Boost_INCLUDE_DIR} )
add_executable(RxC main2.c src/observer.h src/creating/creating.h src/rxc_filtering.h src/observer.c src/rxc_filtering.c src/creating/creating.c src/creating/range.c)
target_link_libraries( RxC ffcall ${CMAKE_THREAD_LIBS_INIT} ${Boost_LIBRARIES} ${Boost_SYSTEM_LIBRARY} ${Boost_PROGRAM_OPTIONS_LIBRARY} )