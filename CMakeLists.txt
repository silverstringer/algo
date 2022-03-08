cmake_minimum_required (VERSION 3.5)

project(algo)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS -pthread)

#BUILD
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY  ${CMAKE_BINARY_DIR}/lib)

set(DEPS_CMAKE_ARGS -DCMAKE_BUILD_TYPE =${CMAKE_BUILD_TYPE})

option(TESTING  "Build  tests"  ON)

message(status "-DTESTING=${TESTING}")
message(status "-DCMAKE_BUILD_TYPE= ${CMAKE_BUILD_TYPE}")

add_subdirectory(bracketgen)
add_subdirectory(consecutive)
add_subdirectory(RangeSeq)
add_subdirectory(tests)

set(PROGS anagrams)

foreach(item ${PROGS})
    add_executable(${item} "${item}.cpp")
endforeach(item)
