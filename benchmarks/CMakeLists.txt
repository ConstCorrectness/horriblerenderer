add_executable(horrible_benchmark horrible_bench.cc)

target_link_libraries(horrible_benchmark PRIVATE benchmark::benchmark)
