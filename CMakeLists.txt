cmake_minimum_required(VERSION 3.15)

if(${CMAKE_VERSION} VERSION_LESS 3.20)
	cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
else()
    cmake_policy(VERSION 3.20) # For older MSVC
endif()

set(PROJECT_NAME trigger)
project(${PROJECT_NAME} LANGUAGES CXX)
# set( MC_CMAKE_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR} )
# set( MC_CMAKE_BINARY_DIR ${CMAKE_CURRENT_BINARY_DIR} )
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

file(TO_CMAKE_PATH "${PROJECT_BINARY_DIR}/CMakeLists.txt" LOC_PATH)
if(EXISTS "${LOC_PATH}")
    message(FATAL_ERROR "You cannot build in a source directory (or any directory with a CMakeLists.txt file). Please make a build subdirectory. Feel free to remove CMakeCache.txt and CMakeFiles.")
endif()

# Git submodules
find_package(Git QUIET)
if(GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.git")
# Update submodules as needed
    option(GIT_SUBMODULE "Check submodules during build" ON)
    if(GIT_SUBMODULE)
        message(STATUS "Submodule update")
        execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
                        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                        RESULT_VARIABLE GIT_SUBMOD_RESULT)
        if(NOT GIT_SUBMOD_RESULT EQUAL "0")
            message(FATAL_ERROR "git submodule update --init failed with ${GIT_SUBMOD_RESULT}, please checkout submodules")
        endif()
    endif()
endif()

if(NOT EXISTS "${PROJECT_SOURCE_DIR}/thirdparty/googletest/CMakeLists.txt")
    message(FATAL_ERROR "The submodules were not downloaded! GIT_SUBMODULE was turned off or failed. Please update submodules and try again.")
endif()

# set_property(GLOBAL PROPERTY USE_FOLDERS ON)
enable_testing()
set (gtest_force_shared_crt ON CACHE BOOL "MSVC defaults to shared CRT" FORCE)
add_subdirectory(thirdparty/googletest)
include_directories(
	"${CMAKE_SOURCE_DIR}/thirdparty/googletest"
)
# target_compile_definitions(gtest
#   PUBLIC
#     GTEST_LANG_CXX20
#     GTEST_HAS_TR1_TUPLE=0
# )

file(GLOB Headers CONFIGURE_DEPENDS "include/*.h")
file(GLOB Sources CONFIGURE_DEPENDS "src/*.cpp")
add_library(${PROJECT_NAME} STATIC ${Sources} ${Headers})
add_subdirectory(test)