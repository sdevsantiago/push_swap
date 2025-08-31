<div align="center">

  <!-- Project badge -->
  <a href=".">
    <img src="assets/README/push_swape.png">
  </a>

  <!-- Project name -->
  <h1>push_swap</h1>

  <!-- Short description -->
  <p>A sorting algorithm using two stacks.</p>

  <!-- Info badges -->
  <img src="https://img.shields.io/badge/Score-98%2F100-brightgreen?style=for-the-badge&labelColor=black" alt="Score">
  <img src="https://img.shields.io/badge/Language-C-blue?style=for-the-badge&labelColor=black" alt="Language">
  <br>
  <img src="https://img.shields.io/github/last-commit/sdevsantiago/push_swap?display_timestamp=committer&style=for-the-badge&labelColor=black" alt="Last commit">
  <br>
  <img src="https://github.com/sdevsantiago/push_swap/actions/workflows/norminette.yml/badge.svg">
  <img src="https://github.com/sdevsantiago/push_swap/actions/workflows/makefile.yml/badge.svg">

</div>

---

## ℹ️ About Project

> The purpose of this project is to build a program that sorts a set of numbers using two stacks and the lowest possible number of actions.

**push_swap** is a project that challenges you to create an efficient sorting algorithm using only two stacks and a limited set of operations. The goal is to sort a list of integers in ascending order using the minimum number of moves possible.

Only the following actions are allowed:
| Action | Description |
|--------|-------------|
| `sa/sb` | Swap the first two elements of stack a/b |
| `ss` | Swap the first two elements of both stacks |
| `pa/pb` | Push the first element from one stack to the other |
| `ra/rb` | Rotate stack a/b (first element becomes last) |
| `rr` | Rotate both stacks |
| `rra/rrb` | Reverse rotate stack a/b (last element becomes first) |
| `rrr` | Reverse rotate both stacks |

### Features

- **Two-stack sorting algorithm**: Uses stack a (initially containing all numbers) and stack b (initially empty)
- **Optimized move count**: Implements algorithms to minimize the number of operations
- **Comprehensive validation**: Handles edge cases, duplicates, and invalid inputs
- **Bonus checker program**: Includes a program to verify if a sequence of operations correctly sorts the stack

### Algorithm Overview

The program receives a list of integers as arguments and outputs a sequence of operations that will sort them. The challenge lies in developing an algorithm that can sort any permutation of numbers efficiently, with different strategies for different input sizes.

#### Small Stack Optimizations (2-5 elements)

- **2 elements**: Direct swap if needed (max 1 operation)
- **3 elements**: Optimized algorithm ensuring max 2 operations
- **4 elements**: Move smallest to top, then 3-sort (optimized rotations)
- **5 elements**: Move smallest to stack_b, 4-sort remainder, merge back

#### Large Stack Algorithm (>5 elements)

**Timsort-inspired approach:**
1. **Run Assignment**: Divide stack into runs of THRESHOLD size (110 elements)
2. **Run Expansion**: Extend runs by detecting natural ordered sequences
3. **Insertion Sort**: Move run elements to stack_b in optimal order
4. **Merge Sort**: Merge sorted runs back to stack_a
5. **Iteration**: Alternate between ascending/descending processing until sorted

For detailed info, refer to this project [subject](docs/en.subject.pdf).

## 🚀 Getting Started

### Prerequisites

- GCC compiler
- Make utility
- Unix-like system (Linux, macOS, WSL)

### Install prerequisites

- Debian/Ubuntu

  ```bash
  sudo apt install build-essential
  ```

## 🔧 Build

1. **Clone the repository:**
    ```bash
    git clone https://github.com/sdevsantiago/push_swap.git
    cd Libft
    ```

2. **Compile the project:**
    ```bash
    make
    ```

3. **Clean build files:**
    ```bash
    make clean
    ```

#### Available Make Targets

| Command | Description |
|---------|-------------|
| `make` | Compiles all |
| `make all` | Same as `make` |
| `make mandatory` | Builds the `push_swap` program |
| `make bonus` | Builds the `checker` program |
| `make clean` | Remove object files (*.o) |
| `make fclean` | Remove object files and binaries |
| `make re` | Clean and rebuild everything |

## 👨‍💻 Usage

### Basic Usage

```bash
./push_swap <numbers>
./push_swap $NUMS | ./checker $NUMS
```

> [!TIP]
> Use the following command to generate a, ready to use, random set of unsorted numbers:
> ```bash
> shuf -i 500 -n 500 | tr '\n' ' '
> ```
> *The `shuf` command is included in the `coreutils` package.*

## 📏 Norminette

The code strictly complies with 42's **Norminette v4**:

```bash
norminette *.c *.h
```

More info in the official [Norminette](https://github.com/42school/norminette) repository.

## 🙇‍♂️ Special thanks

- [lrcouto](https://github.com/lrcouto) and [ayogun](https://github.com/ayogun) for creating and publishing, respectively, the [42-project-badges](https://github.com/ayogun/42-project-badges) repository.
- [gcamerli](https://github.com/gcamerli) for creating the [42unlicense](https://github.com/gcamerli/42unlicense) repository.

## ⚖️ License

<div align="center">

<a href="./LICENSE">
<img src="https://img.shields.io/badge/License-42_Unlicense-red?style=for-the-badge&labelColor=black">
</a>

</div>

**This work is published under the terms of [42 Unlicense](LICENSE).** This means you are free to use, modify, and share this software.
