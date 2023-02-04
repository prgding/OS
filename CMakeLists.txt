cmake_minimum_required(VERSION 3.24)
project(OS C)

set(CMAKE_C_STANDARD 23)

add_executable(OS main.c thread.h monte_carlo.h monte_carlo_multitasks.h monte_carlo_multithreads.h ticket_lock.h ticket_semaphore.h)
