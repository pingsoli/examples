cmake_minimum_required( VERSION 3.4.1 )

set( CMAKE_CXX_STANDARD 11 )
set( CMAKE_CXX_STANDARD_REQUIRED ON )
set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall" )

set( CPPCMS_INCLUDE_PATH "/usr/local/include" )
set( CPPCMS_LIBRARY_PATH "/usr/local/lib" )

include_directories(${CPPCMS_INCLUDE_PATH})
link_directories(${CPPCMS_LIBRARY_PATH})

add_executable(json_test json_test.cpp)

target_link_libraries(json_test
  libcppcms.a
  libbooster.a
  dl)
