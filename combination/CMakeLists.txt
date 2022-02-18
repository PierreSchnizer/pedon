message(STATUS "flame include directories:  ${flame_INCLUDE_DIR}")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(Boost 1.52.0 REQUIRED COMPONENTS
  prg_exec_monitor
  unit_test_framework
  )

find_package(flame  REQUIRED COMPONENTS core)
message(DEBUG "FLAME found ${flame_FOUND}")
get_target_property(flame_CORE_LIBRARY flame::flame_core IMPORTED_LOCATION_RELEASE)
message(STATUS "FLAME core include dirs '${flame_INCLUDE_DIRECTORIES}' library '${flame_CORE_LIBRARY}'")

find_package(thor_scsi  REQUIRED COMPONENTS thor tpsa_lin)


add_executable(test_export
    test_export.cpp
)
target_link_libraries(test_export
    ${flame_CORE_LIBRARY}
    ${Boost_PRG_EXEC_MONITOR_LIBRARY}
    ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
)
add_test(export test_export)

include_directories(
    ${flame_INCLUDE_DIR}
)

add_executable(test_combination
    test_combination.cpp
)
add_test(combination test_combination)


target_link_libraries(test_combination
    ${flame_CORE_LIBRARY}
    ${Boost_PRG_EXEC_MONITOR_LIBRARY}
    ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
)

# flame  ---
# add_executable(test_config
#  test_config.cpp
# )
