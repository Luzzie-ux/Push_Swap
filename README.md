*This project has been created as part of the 42 curriculum by rodrpere, diferrei.*

# push_swap

A highly optimized data sorting project using two stacks and a limited set of instructions.

## 📋 Table of Contents
- [Description](#-description)
- [Instructions](#-instructions)
- [Algorithm Selection and Justification](#-algorithm-selection-and-justification)
- [Available Instruction Set](#-available-instruction-set)
- [Resources and AI Disclosure](#-resources-and-ai-disclosure)

---

## 💡 Description

The `push_swap` project challenges you to sort a specific stack of random integers in ascending order using two stacks (**Stack A** and **Stack B**) and a heavily restricted set of operations. 

The primary goal is to produce the absolute shortest sequence of instructions possible. This project serves as a practical introduction to data structures (such as Linked Lists or Arrays), algorithmic complexity (Big O notation), and performance optimization under strict memory and instruction constraints.

### Key Rules
- **Stack A** initially contains a random amount of negative and/or positive integers without duplicates.
- **Stack B** starts empty.
- The sorting is complete when Stack B is empty and Stack A is sorted in ascending order.
- Any invalid input (non-integers, duplicates, or numbers exceeding `int` limits) immediately triggers an `Error` message on *stderr*.

---

## 🚀 Instructions

### Prerequisites
You need a C compiler (`cc` or `gcc`) and `make` installed on a Unix-like system.

### Compilation
To compile the mandatory program, run the following command in the root directory:
```bash
make
```
This compilation generates the executable named `push_swap`.

### Execution
Run the program by passing a list of space-separated integers as arguments:
```bash
./push_swap 2 1 3 6 5 8
```
The program will output the exact sequence of instructions required to sort the stack, with one instruction per line.

## 📊 Benchmarking Engine & Custom Flags

By passing explicit execution or metric tracking flags, you can override the internal routing mechanics:

| Flag | Description |
| :--- | :--- |
| `--adaptive` | Default routing behavior. Evaluates data layout and picks the best algorithm according to the disorder at hand. |
| `--simple` | Explicitly forces the simple algorithm regardless of array size. |
| `--medium` | Explicitly forces the medium algorihtm regardless of array size. |
| `--complex` | Explicitly forces the complex algorihtm regardless of array size. |
| `--bench` | Initializes and outputs the operation tracking engine that contains detailed efficiency metrics to `stderr`. |

## 🧠 Algorithm Selection and Justification

### 1. Simple Disorder - < 0.2
- **Selection:** *Pivot-Split with Insertion-Sort*
- **Justification:** For highly presorted stacks, we use a selection sort of $O(n^2)$ complexity. Instead of spending operations repeatedly searching for the absolute minimum element as would a usual selection sort, this approach optimizes the process by partitioning the stack. Elements smaller than a dynamically calculated midpoint (`pivot`) are pushed to stack b, while larger ones remain in stack a. Once stack a is reduced to three elements and sorted, elements from b are inserted back via the shortest path (`ra or rra`) into their exact sorted positions (`find_push_pos`), followed by a final rotation to align the stack.

### 2. Medium Disorder - > 0.2, < 0.5
- **Selection:** *Chunk-sort/K-sort*
- **Justification:** If the stack is moderately deorganized, a pure selection sort spends too many operations rotating the stack. Instead, we yse a Chunk-sort that pushes elements to stack b in continuous blocks based on a dynamic window size ($\approx \sqrt{n}$). Elements below the index threshold are sent to the bottom of b (rb), and elements within the current window stay at the top, creating an hourglass shape. The elements are then efficiently pulled back to stack a by isolating the maximums.

### 3. Complex Disorder - > 0.5
- **Selection:** *Radix Sort*
- **Justification:** For chaotic and heavely shuffled datasets, we use a Radix Sort adaptation that processes numbers in $O(n \log n)$ time complexity. Because standard Radix Sort is highly inefficient at sorting numbers with wide value gaps and requires complex shifting to handle negative integers, we pre-process the elements by Pre-indexing them according to their values. Thanks to this the elements are safely represented by valuesranging from $0$ to $N-1$ without altering the physical order of the stack nodes. The algorithm checks the Least Significant Bit of each element, pushing 0s to stack b and rotating 1s back to the top of a, unrolling b back into a after every bit pass.

---

## 🔄 Swap Instruction Set


| Command | Operation | Description |
| :--- | :--- | :--- |
| **sa** / **sb** | Swap | Swap the first 2 elements at the top of stack A / B. |
| **ss** | Swap Both | Execute `sa` and `sb` at the same time. |
| **pa** / **pb** | Push | Take the first element at the top of one stack and put it on the other. |
| **ra** / **rb** | Rotate | Shift up all elements of stack A / B by 1. The first element becomes the last. |
| **rr** | Rotate Both | Execute `ra` and `rb` at the same time. |
| **rra** / **rrb**| Rev Rotate | Shift down all elements of stack A / B by 1. The last element becomes the first. |
| **rrr** | Rev Rotate Both | Execute `rra` and `rrb` at the same time. |

---

## 📚 Resources and AI Disclosure

### References & Documentation
- **Algorithm Concepts:** [(https://www.youtube.com/@PortfolioCourses), "Explaining of concepts for general C language and usage for algorithms"]
- **Understanding Radix sort:** [(https://www.youtube.com/watch?v=Y95a-8oNqps), Explaining of Radix sort, comparison to a few other algorihtms and also giving context to it's historic use"]

### AI Use Disclosure
In compliance with the 42 curriculum requirements, Artificial Intelligence (AI) was utilized during the development of this project under the following scope:
- **Tasks Assist:** Used to brainstorm edge-case scenarios (such as dealing with integer overflows and handling empty string inputs).
- **Code Optimization:** Assisted in formatting and structuring the project's documentation (`README.md`).
- **Parts Affected:** No core algorithmic logic was generated by AI; its usage was strictly confined to conceptual code analysis, text drafting, and debugging assistance for input parsing.


### Work Division

### Diferrei;

Diferrei was tasked with implementing the algorithmic sorting functions, the internal stack operation mechanics`(ra, rb, rr, rra, rrb, rrr, sa, sb, ss, pa, pb)`, and the data-tracking benchmark system. Specifically, he developed the `sort_simple` pivot-split insertion sort,`sort_medium` chunk-sorting, and the `sort_complex` Radix sort. He also built the instruction counting router `(count_op)` used to track operation metrics.
### Rodrpere;

Rodrpere was tasked with the main function, headerfile, parsing related functions (such as `create_list` `setup` and `execute`) plus structures such as `t_flag` and `t_strat` aswell as the error/disorder handling functions (e.g. `check_errors`, `validate_args`, `compute_disorder` and their respective helpers) and Makefile. 
