message(STATUS "flame include directories:  ${flame_INCLUDE_DIR}")


# should already be handled by thor_scsi / flame
find_package(Boost 1.52.0 REQUIRED COMPONENTS
  prg_exec_monitor
  unit_test_framework
  )

# should already be handled by thor_scsi
find_package(Armadillo REQUIRED)

# should already be handled by thor_scsi
find_package(flame REQUIRED COMPONENTS core)
message(DEBUG "FLAME found ${flame_FOUND}")
get_target_property(flame_CORE_LIBRARY flame::flame_core IMPORTED_LOCATION_RELEASE)
message(STATUS "FLAME core include dirs '${flame_INCLUDE_DIRECTORIES}' library '${flame_CORE_LIBRARY}'")


message(STATUS "Loading thor scsi")
find_package(thor_scsi REQUIRED COMPONENTS core tpsa_lin)
get_target_property(thor_scsi_CORE_LIBRARY thor_scsi::thor_scsi_core IMPORTED_LOCATION_RELEASE)
get_target_property(thor_scsi_TPSA_LIN_LIBRARY thor_scsi::tpsa_lin IMPORTED_LOCATION_RELEASE)
message(STATUS "THOR SCSI core library '${thor_scsi_CORE_LIBRARY}'")
message(STATUS "THOR SCSI tpsa_lin library '${thor_scsi_TPSA_LIN_LIBRARY}'")


add_executable(test_export
    test_export.cpp
)


target_link_libraries(test_export
    ${flame_CORE_LIBRARY}
    ${Boost_PRG_EXEC_MONITOR_LIBRARY}
    ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
)
add_test(export test_export)

add_executable(test_export2
    test_export2.cpp
)
target_link_libraries(test_export2
    ${flame_CORE_LIBRARY}
    ${Boost_PRG_EXEC_MONITOR_LIBRARY}
    ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
)


include_directories(
    ${flame_INCLUDE_DIR}
)


add_executable(test_combination
    test_combination.cpp
)
add_test(combination test_combination)
target_link_libraries(test_combination
    ${thor_scsi_CORE_LIBRARY}
    ${thor_scsi_TPSA_LIN_LIBRARY}
    ${flame_CORE_LIBRARY}
    ${ARMADILLO_LIBRARIES}
    ${Boost_PRG_EXEC_MONITOR_LIBRARY}
    ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
)


add_executable(test_drift
    test_drift.cpp
)
add_test(drift test_drift)
target_link_libraries(test_drift
    ${thor_scsi_CORE_LIBRARY}
    ${thor_scsi_TPSA_LIN_LIBRARY}
    ${flame_CORE_LIBRARY}
    ${ARMADILLO_LIBRARIES}
    ${Boost_PRG_EXEC_MONITOR_LIBRARY}
    ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
)

# flame  ---
# add_executable(test_config
#  test_config.cpp
# )
