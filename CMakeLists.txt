cmake_minimum_required (VERSION 3.5)

project(algo)
set(CMAKE_CXX_STANDARD 11)
SET(CMAKE_CXX_FLAGS -pthread)

add_subdirectory(bracketgen)
add_subdirectory(consecutive)

set(PROGS anagrams
        )

foreach(item ${PROGS})
    add_executable(${item} "${item}.cpp")
endforeach(item)
