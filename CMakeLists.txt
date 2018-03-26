cmake_minimum_required(VERSION 3.1)


project(sound_maker)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED on)

set(SOURCES
    ${SOURCES}
    ${CMAKE_CURRENT_SOURCE_DIR}/sound_maker.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/example.cpp
    )


set(HEADERS
    ${HEADERS}
    ${CMAKE_CURRENT_SOURCE_DIR}/sound_maker.hpp
    )


add_executable(run ${SOURCES} ${HEADERS})

