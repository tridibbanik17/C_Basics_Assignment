<div align="center">

<h3 align="center">Base Conversion Utility</h3>

  <p align="center">
    A C program to convert decimal numbers to a specified base (2-36).
    <br />
     <a href="https://github.com/tridibbanik17/c_basics_assignment">tridibbanik17/c_basics_assignment</a>
  </p>
</div>

## Table of Contents

<details>
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
      <ul>
        <li><a href="#key-features">Key Features</a></li>
      </ul>
    </li>
    <li><a href="#architecture">Architecture</a></li>
    <li>
      <a href="#getting-started">Getting Started</a>
      <ul>
        <li><a href="#prerequisites">Prerequisites</a></li>
        <li><a href="#installation">Installation</a></li>
      </ul>
    </li>
    <li><a href="#acknowledgments">Acknowledgments</a></li>
  </ol>
</details>

## About The Project

This C project provides a utility to convert decimal numbers into numbers of a different base, ranging from base 2 to base 36. It supports converting individual numbers read from standard input or converting a range of numbers specified via command-line arguments. The program also includes robust error handling and input validation.

### Key Features

- **Base Conversion:** Converts decimal numbers to any base between 2 and 36.
- **Range Conversion:** Converts a range of numbers between a specified start and finish value.
- **Command-Line Options:** Supports command-line arguments for specifying the base and range.
- **Error Handling:** Provides error messages for invalid input and base values.
- **Input Validation:** Validates input to ensure it is a valid long integer.

## Architecture

The project is structured into three main C files:

-   `main.c`: Handles program entry, command-line argument parsing, and overall control flow. It reads input from stdin or uses the range specified by command-line arguments.
-   `convert.c`: Contains the core conversion logic, including functions to convert a single number and a range of numbers to the specified base. It uses recursion for the conversion process.
-   `parse_options.c`: Responsible for parsing command-line arguments, validating them, and setting the base, start, and finish values accordingly.

The `convert.h` header file defines the function prototypes and constants used across the project.

The project uses standard C libraries such as `stdio.h`, `stdlib.h`, and `string.h`. The `makefile` facilitates the compilation process using `gcc`. The project also includes CI workflows for building and testing the code on every push to the `main` branch.

## Getting Started

To get started with the project, follow these steps:

### Prerequisites

-   **GCC:**  You need a C compiler such as GCC to compile the code.
    ```sh
    sudo apt-get update
    sudo apt-get install gcc
    ```

### Installation

1.  **Clone the repository:**
    ```sh
    git clone https://github.com/tridibbanik17/c_basics_assignment.git
    cd c_basics_assignment
    ```
2.  **Compile the code:**
    ```sh
    make ctest
    ```
3.  **Run the program:**

    -   To convert numbers from standard input:
        ```sh
        ./ctest
        ```
        Then, enter the numbers you want to convert, one per line. Press `Ctrl+D` to exit.
    -   To convert a range of numbers:
        ```sh
        ./ctest -b <base> -r <start> <finish>
        ```
        Replace `<base>` with the desired base, `<start>` with the starting number, and `<finish>` with the ending number.
    -   To view the help message:
        ```sh
        ./ctest --help
        ```

## Acknowledgments

-   This project uses a `makefile` to simplify the build process.
