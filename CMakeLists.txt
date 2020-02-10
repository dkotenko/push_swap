cmake_minimum_required(VERSION 3.14)
project(push_swap C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(push_swap
        bubble_sort.c
        commands.c
        main.c
        push_swap.h
        quick_sort.c
        swap.c
        t_push_swap.c
        t_stack.c t_node.c)
