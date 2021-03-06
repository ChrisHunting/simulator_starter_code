/**
 * memory.h
 *
 * RISC-V 32-bit Instruction Level Simulator
 *
 * ECE 18-447
 * Carnegie Mellon University
 *
 * This file contains the interface to the memory backend for the simulator. The
 * backend handles abstracting the processor memory from the core simulator
 * functions.
 *
 * Specifically, this file contains the interface that is only used by the
 * shell. These functions should not be invoked by the core simulator.
 *
 * Authors:
 *  - 2016 - 2017: Brandon Perez
 **/

/*----------------------------------------------------------------------------*
 *                          DO NOT MODIFY THIS FILE!                          *
 *          You should only add or change files in the src directory!         *
 *----------------------------------------------------------------------------*/

#ifndef MEMORY_SHELL_H_
#define MEMORY_SHELL_H_

// Standard Includes
#include <stdbool.h>            // Boolean type and definitions
#include <stdint.h>             // Fixed-size integral types

// 18-447 Simulator Includes
#include <sim.h>                // Definition of cpu_state_t

/*----------------------------------------------------------------------------
 * Interface
 *----------------------------------------------------------------------------*/

/**
 * Initializes the memory subsystem part of the CPU state.
 *
 * This loads the memory segments from the specified program into the CPU
 * memory, and initializes them to the values specified in their respective data
 * files. Program name should be the path to the executable file (it has no
 * extension).
 **/
int mem_load_program(cpu_state_t *cpu_state, const char *program_path);

/**
 * Unloads a program previously loaded by mem_load_program.
 *
 * This cleans up and frees the allocated memory for the processor's memory
 * segments.
 **/
void mem_unload_program(cpu_state_t *cpu_state);

/**
 * Checks if the given memory range from start to end (inclusive) is valid.
 *
 * Namely, this means that all addresses between start and end are valid.
 **/
bool mem_range_valid(const cpu_state_t *cpu_state, uint32_t start_addr,
        uint32_t end_addr);

/**
 * Finds the segment in memory that contains the given address.
 *
 * If the address is not contained within any segment (and is therefore
 * invalid), then NULL is returned.
 **/
mem_segment_t *mem_find_segment(const cpu_state_t *cpu_state, uint32_t addr);

/**
 * Writes the specified value out to the given address in the segment in
 * little-endian order.
 *
 * The address must lie inside the specified segment. Any parts of the word
 * which lie outside of the segment are not written.
 **/
void mem_write_word(mem_segment_t *segment, uint32_t addr, uint32_t value);

#endif /* MEMORY_SHELL_H_ */
