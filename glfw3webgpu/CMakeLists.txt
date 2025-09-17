add_library(glfw3webgpu STATIC glfw3webgpu.c)

target_link_libraries(glfw3webgpu PUBLIC glfw webgpu)

# Copy compile definitions that are PRIVATE in glfw
if (GLFW_BUILD_COCOA)
    target_compile_definitions(glfw3webgpu PRIVATE _GLFW_COCOA)
    target_compile_options(glfw3webgpu PRIVATE -x objective-c)
    target_link_libraries(glfw3webgpu PRIVATE "-framework Cocoa" "-framework CoreVideo" "-framework IOKit" "-framework QuartzCore")
endif()

