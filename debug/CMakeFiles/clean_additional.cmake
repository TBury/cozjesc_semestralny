# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\cozjesc_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\cozjesc_autogen.dir\\ParseCache.txt"
  "cozjesc_autogen"
  )
endif()
