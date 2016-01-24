cmake_minimum_required (VERSION 2.6)
project (Google-benchmark)

set(THREADS_PREFER_PTHREAD_FLAG ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
find_package(Threads REQUIRED)

set(EXTERNAL_LIBS ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++14")


file(GLOB Benchmark_src
  ${CMAKE_SOURCE_DIR}/benchmark_src/*.c*
  ${CMAKE_SOURCE_DIR}/benchmark_src/*.h*
  )

#message("\nbenchmark_src: " ${benchmark_src} "\n" )

add_executable(Benchmark ${Benchmark_src})
target_link_libraries(Benchmark ${EXTERNAL_LIBS}/libbenchmark.a Threads::Threads)

file(GLOB Test_src
  ${CMAKE_SOURCE_DIR}/test_src/*.c*
  ${CMAKE_SOURCE_DIR}/test_src/*.h*
  )

add_executable(Tests ${Test_src})
target_link_libraries(Tests ${EXTERNAL_LIBS}/libgoogle_gtest.a Threads::Threads)