message(STATUS "flame include directories:  ${flame_INCLUDE_DIR}")

include_directories(
    ${flame_INCLUDE_DIR}
)

add_executable(test_combination
    test_combination.cpp
)

target_link_libraries(test_combination
    ${Boost_PRG_EXEC_MONITOR_LIBRARY}
    ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
)
