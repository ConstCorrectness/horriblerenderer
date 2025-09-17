add_executable(horrible_renderer
  main.cc
)

target_link_libraries(horrible_renderer PRIVATE webgpu)


target_copy_webgpu_binaries(horrible_renderer)

if (MSVC)
	target_compile_options(horrible_renderer PRIVATE /W4)
else()
	target_compile_options(horrible_renderer PRIVATE -Wall -Wextra -pedantic)
endif()

if (XCODE)
	set_target_properties(horrible_renderer PROPERTIES
		XCODE_GENERATE_SCHEME ON
		XCODE_SCHEME_ENABLE_GPU_FRAME_CAPTURE_MODE "Metal"
	)
endif()

# Options that are specific to Emscripten
if (EMSCRIPTEN)
	# Generate a full web page rather than a simple WebAssembly module
	set_target_properties(horrible_renderer PROPERTIES SUFFIX ".html")
endif()