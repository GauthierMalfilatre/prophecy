cmake_minimum_required(VERSION 3.5)
project(prophecy LANGUAGES C)

if(CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_CURRENT_BINARY_DIR)
    message(FATAL_ERROR "Les builds dans le dossier source sont interdits. Créez un dossier build/.")
endif()

file(GLOB_RECURSE prophecy_SOURCES 
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.c"
)

add_library(prophecy-obj ${prophecy_SOURCES})

target_include_directories(prophecy-obj
    PUBLIC
        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

target_compile_options(prophecy-obj PRIVATE
    -Wall
    -Wextra
    -O3
)

add_library(prophecy-static STATIC
    $<TARGET_OBJECTS:prophecy-obj>
)

target_link_libraries(prophecy-static
    PUBLIC
        prophecy-obj
)

add_library(prophecy-shared SHARED
    $<TARGET_OBJECTS:prophecy-obj>
)

target_link_libraries(prophecy-shared
    PUBLIC
        prophecy-obj
)

add_library(prophecy ALIAS prophecy-static)

set_target_properties(prophecy-static PROPERTIES
    OUTPUT_NAME prophecy
)

set_target_properties(prophecy-shared PROPERTIES
    OUTPUT_NAME prophecy
)

set_target_properties(prophecy-obj PROPERTIES
    POSITION_INDEPENDENT_CODE ON
)
