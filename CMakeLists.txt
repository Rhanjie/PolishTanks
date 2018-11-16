cmake_minimum_required(VERSION 3.12)

# Project Name
project(PolishTanks)
set(EXECUTABLE_NAME PolishTanks)

# Directories
set(DIR_SOURCE source)
set(DIR_BIN bin)

# Standard
set(CMAKE_CXX_STANDARD 17)

# Files
file(GLOB ALL_SOURCE_FILES
        "${DIR_SOURCE}/*"
        "${DIR_SOURCE}/Character/*"
        "${DIR_SOURCE}/Character/TankModules/*"
        "${DIR_SOURCE}/Character/Enemy/*"
        "${DIR_SOURCE}/Effects/*"
        "${DIR_SOURCE}/Effects/Particles/*"
        "${DIR_SOURCE}/System/*"
        "${DIR_SOURCE}/Terrain/*"
        "${DIR_SOURCE}/Interface/*"
)

add_executable(PolishTanks ${ALL_SOURCE_FILES})
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_LIST_DIR}/${DIR_BIN})
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake-modules" ${CMAKE_MODULE_PATH})
include(${CMAKE_CURRENT_LIST_DIR}/cmake-modules/Config.cmake)

# LUA
find_package(Lua51 REQUIRED)
include_directories(${LUA_ROOT})
target_link_libraries(${EXECUTABLE_NAME} ${LUA_LIBRARIES})

# Sol2 Library
include_directories(${SOL2_ROOT})

# SFML
include_directories("${CMAKE_CURRENT_LIST_DIR}/${SFML_ROOT}/include")
find_package(SFML COMPONENTS system window graphics network audio)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})
endif()