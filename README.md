push_swap – 42 School Project
## Overview

push_swap is an algorithmic project from the 42 curriculum focused on sorting data using a constrained set of operations.

The objective is to sort a list of integers using two stacks and a limited set of predefined instructions, while minimizing the total number of operations performed.

The project emphasizes algorithm design, efficiency, and problem decomposition under strict constraints.

## Project Scope

The project includes:

·  Parsing and validating integer input

·  Implementing two stacks (A and B)

·  Implementing the allowed operations:

    sa, sb, ss

    pa, pb

    ra, rb, rr

    rra, rrb, rrr

·  Designing a sorting strategy optimized for operation count

·  Handling edge cases (duplicates, overflow, invalid input)

·  Ensuring correct memory management

Implemented in:

·  C

## Project Focus

push_swap focuses on:

·  Designing efficient sorting strategies under operational constraints

·  Analyzing time and move complexity

·  Choosing appropriate data structures

·  Breaking a complex problem into smaller deterministic steps

·  Optimizing for performance rather than brute-force solutions

## Technical Scope

The project explores algorithmic problem-solving in a restricted environment. Since traditional sorting functions cannot be used, the solution must be built around stack manipulation logic.

Common approaches involve:

·  Indexing and normalization

·  Chunk-based sorting strategies

·  Variations of radix sort

·  Cost calculation for optimal element movement

The emphasis is on balancing correctness, efficiency, and move optimization within strict rules.

## Build & Run
    make
    ./push_swap 4 67 3 87 23
