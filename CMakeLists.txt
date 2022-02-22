cmake_minimum_required(VERSION 3.0.0)

project("pedon" C CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

if(CMAKE_COMPILER_IS_GNUCXX)
  message(STATUS "Enabling gxx debug preprocessor flags")
  add_definitions(-Wall -Wextra -Wno-unused-parameter -Wno-missing-field-initializers)
  add_definitions(
  -Wno-deprecated-copy
  )
  # flame relies on boost ... have to search if ubuntu has a version which supports
  # GNU extra flags ...
  # add_definitions(-D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC)
    add_definitions(-g -ggdb -pedantic -Wall -Wextra)
endif()

enable_testing()

# add_subdirectory(flame)
# add_subdirectory(thor_scsi)
add_subdirectory(combination)
