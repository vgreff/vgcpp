include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.11.0
)
FetchContent_MakeAvailable(googletest)

add_library(GTest::GTest INTERFACE IMPORTED)
target_link_libraries(GTest::GTest INTERFACE gtest_main)

add_executable(sample3_unittest sample3_unittest.cpp)

target_link_libraries(sample3_unittest
 PRIVATE
  GTest::GTest
  )

add_test(sample3_gtests sample3_unittest)
