cmake_minimum_required(VERSION 3.15)

set(PROJECT_NAME triggertest)
file(GLOB Sources CONFIGURE_DEPENDS "*.h" "*.cpp")
# set(Sources
#     main.cpp
#     )
add_executable(${PROJECT_NAME} ${Sources})
target_link_libraries(${PROJECT_NAME} PUBLIC
    gtest_main
    trigger
)

add_test(
    NAME ${PROJECT_NAME}
    COMMAND ${PROJECT_NAME}
)