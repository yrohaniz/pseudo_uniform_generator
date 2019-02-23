cmake_minimum_required(VERSION 3.7)
project(pseudo_uniform_generator)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES
        main.c
        UniPRNG.h
        sample_mean_calc.c
        PRNG_uniform.c
        histogram_generator.c
        sort_compare.c
        sample_variance_calc.c
        )

add_executable(pseudo_uniform_generator ${SOURCE_FILES})

target_link_libraries(pseudo_uniform_generator m)

