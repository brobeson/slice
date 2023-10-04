cmake_minimum_required(VERSION 3.21)
project(slice)
add_library(slice INTERFACE)
target_sources(slice INTERFACE slice.h)
target_compile_features(slice INTERFACE cxx_std_11)
add_library(slice::slice ALIAS slice)

enable_testing()
include(FetchContent)
fetchcontent_declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.4.0
)
fetchcontent_makeavailable(Catch2)
list(APPEND CMAKE_MODULE_PATH "${catch2_SOURCE_DIR}/extras")
include(Catch)
add_executable(slice_test slice_test.cpp)
target_link_libraries(slice_test PRIVATE Catch2::Catch2WithMain slice::slice)
catch_discover_tests(slice_test)
