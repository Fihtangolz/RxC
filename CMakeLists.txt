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
add_executable(RxC examples/ex2.c ${HEADER} ${SOURCES})
target_link_libraries(RxC ffcall ${CMAKE_THREAD_LIBS_INIT} ${Boost_LIBRARIES} ${Boost_SYSTEM_LIBRARY} ${Boost_PROGRAM_OPTIONS_LIBRARY} )



# first we can indicate the documentation build as an option and set it to ON by default
option(BUILD_DOC "Build documentation" ON)

# check if Doxygen is installed
find_package(Doxygen)
if (DOXYGEN_FOUND)
    # set input and output files
    set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/doc/Doxyfile.in)
    set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)

    # request to configure the file
    configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)
    message("Doxygen build started")

    # note the option ALL which allows to build the docs together with the application
    add_custom_target( doc_doxygen ALL
            COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
            WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
            COMMENT "Generating API documentation with Doxygen"
            VERBATIM )
else (DOXYGEN_FOUND)
    message("Doxygen need to be installed to generate the doxygen documentation")
endif (DOXYGEN_FOUND)