cmake_minimum_required(VERSION 3.0)
project(remotery)

option(RMT_ENABLED 1)
set(SOURCE_FILES lib/Remotery.c include/remotery/Remotery.h)

add_library(remotery STATIC ${SOURCE_FILES})
if (USE_METAL)
    list(APPEND SOURCE_FILES lib/RemoteryMetal.mm)
endif()

target_include_directories(remotery INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include 
                                    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include/remotery)
set_target_properties(remotery PROPERTIES FOLDER Deps ${IOS_GENERAL_PROPERTIES})
