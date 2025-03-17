add_subdirectory(extern)

add_executable(tests test.cpp)
target_link_libraries(tests ball GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(tests)
