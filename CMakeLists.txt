cmake_minimum_required(VERSION 3.10)

project(static-constexpr-test)

find_package(nanobench CONFIG REQUIRED)

add_executable(constexpr constexpr.cpp)
target_link_libraries(constexpr PRIVATE nanobench::nanobench)
target_compile_options(constexpr PRIVATE
    $<$<CONFIG:Debug>:/Od> # no optimization in debug configuration
    $<$<CONFIG:Release>:/O2>
)

add_executable(static_constexpr static-constexpr.cpp)
target_link_libraries(static_constexpr PRIVATE nanobench::nanobench)
target_compile_options(static_constexpr PRIVATE
    $<$<CONFIG:Debug>:/Od> # no optimization in debug configuration
    $<$<CONFIG:Release>:/O2>
)