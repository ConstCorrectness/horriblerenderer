add_executable(horrible_renderer
  main.cc
)


target_compile_definitions(horrible_renderer PRIVATE GLFW_INCLUDE_NONE)

target_link_libraries(horrible_renderer PRIVATE glad glfw)


set_target_properties(horrible_renderer PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})