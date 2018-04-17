cmake_minimum_required(VERSION 3.0)
project(main.out)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE Debug)

file(GLOB_RECURSE SOURCES "*.cpp")

set(PROTO_ROOT "/usr/local/protobuf")

include_directories(
  ${PROTO_ROOT}/include
  ../proto
)

link_directories(
  ${PROTO_ROOT}/lib
)

add_executable(${PROJECT_NAME}
  ${SOURCES}
  ../proto/addressbook.pb.cc
)


target_link_libraries(${PROJECT_NAME}
  libprotobuf.a
)
