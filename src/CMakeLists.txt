# The Flutter tooling requires that developers have CMake 3.10 or later
# installed. You should not increase this version, as doing so will cause
# the plugin to fail to compile for some customers of the plugin.
cmake_minimum_required(VERSION 3.10)

project(rtk_mavlink_library VERSION 0.0.1 LANGUAGES C)

add_library(rtk_mavlink SHARED
  "rtk_mavlink.c"
)

set_target_properties(rtk_mavlink PROPERTIES
  PUBLIC_HEADER rtk_mavlink.h
  
  OUTPUT_NAME "rtk_mavlink"
)

target_compile_definitions(rtk_mavlink PUBLIC DART_SHARED_LIB)
