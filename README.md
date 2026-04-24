# Benchmarking `static constexpr`

The aim of this project is to compare the performance implications of creating a `constexpr` object with automatic and static duration.
[Nanobench](https://github.com/martinus/nanobench) was used for benchmarking.

## Dependencies

* MSVC compiler
* CMake
* VCPKG

## How to build the project

```shell
cmake --preset base
cmake --build --preset <debug|release>
```

The debug configuration does not have optimization switched on.
The release one has optimization set to `O2`.

## Results for small object

For an array of size 36 bytes, `static constexpr` yields faster results for the unoptimized (debug) build, whereas there is no difference for the optimized (release) build.

### Debug

|               ns/op |                op/s |    err% |     total | benchmark
|--------------------:|--------------------:|--------:|----------:|:----------
|                9.65 |      103,595,169.18 |    2.0% |      0.01 | `auto`


|               ns/op |                op/s |    err% |     total | benchmark
|--------------------:|--------------------:|--------:|----------:|:----------
|                3.15 |      317,292,318.70 |    0.4% |      0.01 | `static`

### Release

|               ns/op |                op/s |    err% |     total | benchmark
|--------------------:|--------------------:|--------:|----------:|:----------
|                0.23 |    4,358,021,593.23 |    0.4% |      0.01 | `auto`


|               ns/op |                op/s |    err% |     total | benchmark
|--------------------:|--------------------:|--------:|----------:|:----------
|                0.23 |    4,433,736,809.98 |    0.1% |      0.01 | `static`


## Results for big object

For an array of size 1024 bytes, `static constexpr` yields faster results for both  unoptimized (debug) optimized (release) builds.

### Debug

|               ns/op |                op/s |    err% |     total | benchmark
|--------------------:|--------------------:|--------:|----------:|:----------
|              131.70 |        7,592,840.74 |    0.5% |      0.01 | `auto`


|               ns/op |                op/s |    err% |     total | benchmark
|--------------------:|--------------------:|--------:|----------:|:----------
|                3.23 |      309,234,946.65 |    1.0% |      0.01 | `static`

### Release

|               ns/op |                op/s |    err% |     total | benchmark
|--------------------:|--------------------:|--------:|----------:|:----------
|                8.27 |      120,954,838.71 |    0.5% |      0.01 | `auto`


|               ns/op |                op/s |    err% |     total | benchmark
|--------------------:|--------------------:|--------:|----------:|:----------
|                0.23 |    4,434,337,853.67 |    0.1% |      0.01 | `static`