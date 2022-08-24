cmake_minimum_required(VERSION 3.15)
project(aheadfork-gui
    DESCRIPTION "GUI aheadfork"
    LANGUAGES CXX
    VERSION 0.1
    )

cmake_policy(SET CMP0097 NEW)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

include(cmake/CPM.cmake)

add_executable(aheadfork src/main.cpp)

if(CMAKE_GENERATOR STREQUAL "Ninja")
    message("Enabling color in Ninja color")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fdiagnostics-color=always")
endif()

include_directories("include")

#find_package(glfw3)
#if(glfw3_FOUND)
#    CPMAddPackage(
#	    NAME "nanogui"
#	    GITHUB_REPOSITORY "mitsuba-renderer/nanogui"
#	    GIT_TAG "abd03f651b2e8fd168c30a5301d5348712198776"
#	    OPTIONS "NANOGUI_BUILD_EXAMPLES OFF" "NANOGUI_BUILD_GLFW OFF" "NANOGUI_BUILD_SHARED OFF" "NANOGUI_BUILD_PYTHON OFF" "NANOGUI_INSTALL OFF"
#	    )
#    target_link_libraries(worldlinesim PRIVATE glfw)
#else()
CPMAddPackage(
	NAME "nanogui"
	GITHUB_REPOSITORY "mitsuba-renderer/nanogui"
	GIT_TAG "abd03f651b2e8fd168c30a5301d5348712198776"
	OPTIONS "NANOGUI_BUILD_EXAMPLES OFF" "NANOGUI_BUILD_SHARED OFF" "NANOGUI_BUILD_PYTHON OFF" "NANOGUI_INSTALL OFF"
	)
#endif()

#add_custom_command(
#        COMMAND g++ -std=c++20 -fmodules-ts -xc++-system-header iostream
#        OUTPUT iostream.gcm
#        )

target_link_libraries(aheadfork PRIVATE nanogui)

