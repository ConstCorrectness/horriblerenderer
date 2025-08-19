add_executable(horrible_tests 
  horrible_window_test.cc
)

target_link_libraries(horrible_tests PRIVATE glad glfw gtest gtest_main)


add_test(NAME horrible_tests COMMAND horrible_tests)