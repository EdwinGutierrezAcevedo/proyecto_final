# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\kingOFTheHill_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\kingOFTheHill_autogen.dir\\ParseCache.txt"
  "kingOFTheHill_autogen"
  )
endif()
