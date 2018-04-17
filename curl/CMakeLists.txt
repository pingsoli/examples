cmake_minimum_required(VERSION 3.0)
project(main.out)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE Debug)

set(CURL_ROOT "/usr/local/curl")
set(SSL_ROOT  "/usr/local/ssl")

file(GLOB_RECURSE SOURCES "*.cpp")

include_directories(
  /usr/local/json/include
  ${INCLUDE_DIR}/include
  ${CURL_ROOT}/include
)

link_directories(
  ${CURL_ROOT}/lib
  ${SSL_ROOT}/lib
)

set(CURL_LIBS curl ssl crypto z dl pthread)
set(EXECUTABLE_OUTPUT_PATH "../bin")

add_executable(${PROJECT_NAME}
  ${SOURCES})

target_link_libraries(${PROJECT_NAME}
  ${CURL_LIBS})
