# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\HomeInventoryGUI_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\HomeInventoryGUI_autogen.dir\\ParseCache.txt"
  "HomeInventoryGUI_autogen"
  )
endif()
