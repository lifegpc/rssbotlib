cmake_minimum_required(VERSION 3.11)

project(rssbotlib)

include(FindPkgConfig)

pkg_check_modules(LIBAVFORMAT REQUIRED libavformat>=58.65.101)
link_directories(${LIBAVFORMAT_LIBRARY_DIRS})
include_directories(${LIBAVFORMAT_INCLUDE_DIRS})
add_compile_options(${LIBAVFORMAT_CFLAGS_OTHER})

add_library(rssbot SHARED src/main/ffmpegtype.cpp src/main/getBasicInfo.cpp src/main/getInfo.cpp src/main/version.cpp)
target_link_libraries(rssbot ${LIBAVFORMAT_LIBRARIES})
