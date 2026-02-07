# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project

42 School C++ Module 03 — Inheritance. Exercises progressively build a class hierarchy: ClapTrap → ScavTrap → FragTrap → DiamondTrap.

## Build Commands

Each exercise is self-contained in its own directory with its own Makefile:

```bash
make -C ex00        # Build ex00 (ClapTrap)
make -C ex01        # Build ex01 (ScavTrap)
make -C ex02        # Build ex02 (FragTrap)
make clean -C ex00  # Remove object files
make fclean -C ex00 # Remove objects + binary
make re -C ex00     # Full rebuild
```

Binaries are named after the main derived class: `ClapTrap`, `ScavTrap`, `FragTrap`.

## Compiler Constraints

- Compiler: `c++` (or `g++`)
- Flags: `-Wall -Wextra -Werror -std=c++98`
- Must compile under C++98 — no C++11 features, no Boost, no STL containers/algorithms

## Architecture

- **ex00**: Base `ClapTrap` class with private attributes (_name, _hp, _ep, _damage) and attack/takeDamage/beRepaired methods
- **ex01**: `ScavTrap` inherits from `ClapTrap`. Attributes become `protected` in ClapTrap. ClapTrap gains a parameterized constructor `(name, hp, ep, damage)` so derived classes can set their own stats
- **ex02**: Adds `FragTrap` inheriting from `ClapTrap`, same pattern as ScavTrap
- **ex03** (TODO): `DiamondTrap` — multiple inheritance from both ScavTrap and FragTrap, requiring virtual inheritance to solve the diamond problem

Each exercise copies and extends the files from the previous one.

## 42 Coding Rules

- All classes must follow **Orthodox Canonical Form** (default constructor, copy constructor, copy assignment operator, destructor)
- No function implementations in headers (except templates)
- Headers use `#pragma once` for include guards
- Attributes are prefixed with `_` (e.g., `_name`, `_hp`)
- Constructors/destructors must print messages showing construction/destruction chaining order
- Forbidden: `using namespace`, `friend` keyword, `printf`, `alloc`/`free`
