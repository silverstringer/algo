cmake_minimum_required(VERSION 3.5)
project(common)

set(CMAKE_CXX_STANDARD 14)

set(PROGS anagrams twosum)

foreach(item ${PROGS})
    add_executable(${item} "${item}.cpp" )
endforeach(item)

