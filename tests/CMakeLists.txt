cmake_minimum_required(VERSION 3.5)
project(tests)

set(CMAKE_CXX_STANDARD 14)

find_package(GTest REQUIRED )

include_directories(${GTEST_INCLUDE_DIRS})
include_directories(../RangeSeq)

set(HEADER_FILES testRange.h ../RangeSeq/RangeSEQ.h)
set(PROJECT_FILES main.cpp testRange.h)


add_executable(${PROJECT_NAME} ${PROJECT_FILES} ${HEADER_FILES})
target_link_libraries(${PROJECT_NAME} ${GTEST_LIBRARIES} pthread )
