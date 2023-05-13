cmake_minimum_required(VERSION 3.10)
project(audiowave)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


find_package(SFML 2.5 COMPONENTS system window graphics audio REQUIRED)

# Add the flags for GCC and Clang compilers
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    add_compile_options(-Wall -Wextra -Wpedantic -Werror)
endif()


# Include the custom FindPortAudio module
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR})
include(FindPortAudio)

file(GLOB_RECURSE SOURCES "src/*.cpp")
add_executable(audiowave ${SOURCES})

target_link_libraries(audiowave PRIVATE sfml-system sfml-window sfml-graphics sfml-audio ${PORTAUDIO_LIBRARIES})
target_include_directories(audiowave PRIVATE ${PORTAUDIO_INCLUDE_DIRS})
target_compile_options(audiowave PRIVATE ${PORTAUDIO_CFLAGS_OTHER})

