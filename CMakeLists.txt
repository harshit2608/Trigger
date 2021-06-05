cmake_minimum_required(VERSION 3.10)

set(PROJECT_NAME trigger)
project(${PROJECT_NAME} C CXX)

# set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_C_STANDARD 98)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# if(MSVC)
#   set(CMAKE_CXX_FLAGS "/permissive- /std:c++17 ${CMAKE_CXX_FLAGS} /utf-8 /wd4530 /wd4577")
#   set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /manifestuac:NO /ignore:4099 /ignore:4098")
#   add_definitions(-D_UNICODE -DUNICODE -DWIN32_LEAN_AND_MEAN -DNOMINMAX)
#   add_definitions(-D_CRT_SECURE_NO_DEPRECATE -D_CRT_NONSTDC_NO_DEPRECATE -D_ATL_SECURE_NO_DEPRECATE)
#   add_definitions(-D_CRT_SECURE_NO_WARNINGS -D_SCL_SECURE_NO_WARNINGS)
#   add_definitions(-DWINVER=0x0A00 -D_WIN32_WINNT=0x0A00)
# else()
#   set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror -Wno-unused -Wno-unused-parameter")
#   set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-omit-frame-pointer -fdiagnostics-absolute-paths -fcolor-diagnostics")
#   set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -pthread")
#   link_libraries(c++experimental)
# endif()

# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fopenmp -o3")
enable_testing()
set (gtest_force_shared_crt ON CACHE BOOL "MSVC defaults to shared CRT" FORCE)
add_subdirectory(thirdparty/googletest)
target_compile_definitions(gtest
  PUBLIC
    GTEST_LANG_CXX20
    GTEST_HAS_TR1_TUPLE=0
)
# set_target_properties(tests PROPERTIES COMPILE_FLAGS "${cxx_strict}")
# target_link_libraries(tests gtest gtest_main Core)
# if(MSVC)
#   set_property(GLOBAL PROPERTY USE_FOLDERS ON)
#   set_property(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER build)
#   set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})
#   set_target_properties(${PROJECT_NAME} PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
# else()
#   set(CMAKE_EXPORT_COMPILE_COMMANDS 1)
# endif()

file(GLOB Headers CONFIGURE_DEPENDS "include/*.h")
file(GLOB Sources CONFIGURE_DEPENDS "src/*.cpp")
add_library(${PROJECT_NAME} STATIC ${Sources} ${Headers})
add_subdirectory(test)