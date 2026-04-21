*This project has been created as part of the 42 curriculum by memalli, alpturan.*

# push_swap

## Description
push_swap is a sorting project from the 42 curriculum. The goal is to sort a list of integers using two stacks (A and B) and a restricted set of stack operations, while minimizing the total number of operations.

This repository contains:
- push_swap: the main program that outputs a valid sequence of operations to sort the input.
- checker (bonus): a validator that reads operations from standard input, applies them to the stacks, and prints OK or KO.

### Project Goals
- Parse and validate input safely (format, integer limits, duplicates).
- Build an efficient sorting strategy under operation constraints.
- Keep the implementation modular, testable, and easy to benchmark.

## Features
- Full argument parsing with support for quoted and space-separated numbers.
- Input validation for invalid tokens, integer overflow, and duplicates.
- Multiple sorting strategies:
  - Tiny sort for very small inputs.
  - Simple strategy.
  - Medium chunk-based strategy.
  - Complex cost-based strategy (Turk-style approach).
- Adaptive mode that selects strategy based on disorder level.
- Optional benchmark output with operation statistics.
- Bonus checker to validate operation sequences.

## Instructions
### Prerequisites
- C compiler (cc)
- make

### Compilation
From the repository root:

```bash
make
```

This builds:
- push_swap

Build bonus checker:

```bash
make bonus
```

This additionally builds:
- checker

Clean object files:

```bash
make clean
```

Remove objects and binaries:

```bash
make fclean
```

Rebuild from scratch:

```bash
make re
```

### Execution
Run push_swap with numbers:

```bash
./push_swap 3 2 1
```

Or with quoted arguments:

```bash
./push_swap "3 2 1"
```

Available flags:
- --simple
- --medium
- --complex
- --adaptive
- --bench

Example with benchmark:

```bash
./push_swap --adaptive --bench 5 1 4 2 3
```

### Checker Usage
Pipe the output of push_swap into checker:

```bash
ARG="3 2 1"; ./push_swap $ARG | ./checker $ARG
```

Expected output:
- OK if sorted correctly and stack B is empty.
- KO otherwise.

## Algorithms: Detailed Explanation and Justification
The project uses a hybrid architecture. Very small inputs are handled with dedicated optimal logic, while larger inputs are solved by strategy-based methods.

### 1) Indexing and Normalization
Before sorting, each node receives an index (rank) representing its position in sorted order.
- Smallest value gets index 0, next gets 1, and so on.

Why this choice:
- Makes comparisons independent from original value magnitude.
- Simplifies target search and cost computation.
- Avoids edge-case complexity tied to negative or large integer values.

### 2) Tiny Input Strategy (2 to 5 numbers)
For tiny sizes, specialized routines are used:
- 2 numbers: single conditional swap.
- 3 numbers: finite decision tree over known permutations.
- 4 and 5 numbers: push minimum(s) to B, sort remaining 3, then push back.

Why this choice:
- For very small n, handcrafted logic is both minimal and reliable.
- Better operation counts than generic strategies.

### 3) Simple Strategy
Simple mode repeatedly:
1. Rotates stack A to bring current minimum to the top (using shortest direction).
2. Pushes it to B.
3. Restores all numbers back to A.

Why this choice:
- Easy to reason about and robust for nearly sorted or small-medium inputs.
- Good fallback baseline and debugging reference.

Complexity profile:
- Roughly quadratic behavior in the worst case.

### 4) Medium Strategy (Chunk-Based)
Medium mode splits index space into chunks of size around sqrt(n) with an adjustment factor.
Process:
1. Push numbers from A to B chunk by chunk.
2. While pushing, rotate B for better distribution of lower-half values.
3. Push back from B to A by repeatedly extracting the current maximum in B.

Why this choice:
- Chunking reduces random movement compared to naive selection-based passes.
- Good compromise between implementation simplicity and operation count.

Complexity profile:
- Practical performance is significantly better than simple mode on larger sets.

### 5) Complex Strategy (Cost-Based / Turk-Style)
Complex mode is the most advanced strategy:
1. Keep 3 elements in A (to sort with tiny logic) and move the rest considering move costs.
2. For each candidate in A, compute:
   - target position in B
   - rotation cost in A and B
3. Select the cheapest node using a combined cost function.
4. Use synchronized rotations (rr or rrr) whenever both stacks rotate in the same direction.
5. Push selected node to B.
6. After A is reduced and sorted, push back from B to A with target-aware insertion.
7. Final rotate A so the minimum index is on top.

Why this choice:
- Cost-driven moves usually reduce total operations compared to simple heuristics.
- Shared rotations exploit operation set effectively.
- Widely used and proven practical approach for push_swap constraints.

Complexity profile:
- Not strictly asymptotically optimal in theory, but highly effective in operation count practice.

### 6) Adaptive Strategy Selection
Adaptive mode estimates disorder using inversion ratio:
- disorder = inversions / total_pairs

Then selects:
- low disorder -> simple
- medium disorder -> chunk-based
- high disorder -> complex

Why this choice:
- No single strategy is best for every input distribution.
- Adaptive choice improves average behavior across varied datasets.

## Technical Choices
- Singly linked list for stacks:
  - Natural fit for push and pop at top.
  - Clear and memory-efficient node management.
- Explicit operation layer:
  - Each allowed operation is implemented as an isolated function.
  - Easier verification and benchmarking.
- Shared utilities and clean error handling:
  - Unified input validation and free paths.

## Resources
### Classic References
- 42 Subject and intra documentation for push_swap and checker requirements.
- C Language Reference: cppreference C pages and man pages for standard/POSIX calls.
- Algorithm references:
  - Inversion counting and disorder metrics.
  - Selection-sort-like extraction logic.
  - Chunk-based partition ideas.
  - Cost-based insertion and Turk-style push_swap community write-ups.

### How AI Was Used
AI was used as an assistant for:
- Structuring documentation and improving README clarity.
- Reviewing wording quality and readability of explanations.
- Providing high-level comparisons between strategy families.

AI was not used to bypass project understanding. The algorithmic design, implementation decisions, and code-level integration were validated and adjusted through manual development, testing, and iteration within the project codebase.

## Notes
- The benchmark flag prints strategy, disorder estimate, total operations, and per-operation counts.
- checker is intended for validation, not operation generation.
