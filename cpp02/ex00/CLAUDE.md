# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Build Commands

```bash
make        # Build the project (produces 'floating_floats' executable)
make clean  # Remove object files
make fclean # Remove object files and executable
make re     # Clean rebuild
```

## Project Overview

This is 42 school's C++ Module 02 exercise 00: implementing a Fixed-point number class in Orthodox Canonical Form.

### Requirements

- **C++98 standard** - Code must compile with `-std=c++98`
- **Strict compilation** - Uses `-Wall -Wextra -Werror`
- **Orthodox Canonical Form** - Every class must have:
  - Default constructor
  - Copy constructor
  - Copy assignment operator
  - Destructor

### Fixed-Point Implementation

The `Fixed` class stores a fixed-point number using:
- `int _x` - Raw integer value storing the fixed-point representation
- `static const int _bits = 8` - Number of fractional bits (fixed at 8)

This exercise focuses on demonstrating proper canonical form implementation with constructor/destructor logging to verify copy semantics.
