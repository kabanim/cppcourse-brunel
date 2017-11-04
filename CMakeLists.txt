cmake_minimum_required (VERSION 2.6)
project (Neuro_3)
set(CMAKE_CXX_FLAGS "-O3 -W -Wall -pedantic -std=c++11")



add_executable(simulation neuro.cpp network.cpp main.cpp)
add_subdirectory(gtest)
enable_testing()

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(networktest neuro.cpp network.cpp neuro_test.cpp)
add_executable(neuronetest neuro.cpp network.cpp neuro_test.cpp)
target_link_libraries(networktest gtest gtest_main)
target_link_libraries(neuronetest gtest gtest_main)
add_test(networktest networktest)
add_test(neuronetest neuronetest)

# add a target to generate API documentation with Doxygen
find_package(Doxygen)
if(DOXYGEN_FOUND)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile @ONLY)
add_custom_target(doc
${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile
WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
COMMENT "Generating API documentation with Doxygen" VERBATIM
)
endif(DOXYGEN_FOUND)

