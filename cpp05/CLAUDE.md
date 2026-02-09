# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project

42 School C++ Module 05 — Exceptions. Exercises build a bureaucracy simulation using custom exception classes, progressing from a simple `Bureaucrat` to abstract forms, concrete form types, and an `Intern` factory.

## Build Commands

Each exercise is self-contained with its own Makefile:

```bash
make -C ex00        # Build ex00 (Bureaucrat only)
make -C ex01        # Build ex01 (Bureaucrat + Form)
make clean -C ex00  # Remove object files
make fclean -C ex00 # Remove objects + binary
make re -C ex00     # Full rebuild
```

All binaries are named `la_excepcion`. Debug symbols are enabled (`-ggdb`).

## Compiler Constraints

- Compiler: `c++`
- Flags: `-Wall -Wextra -Werror -std=c++98 -ggdb`
- Must compile under C++98 — no C++11 features, no Boost, no STL containers/algorithms

## Architecture

- **ex00**: `Bureaucrat` class with const `_name` and `_grade` (1=highest, 150=lowest). Nested exception classes `GradeTooHighException` and `GradeTooLowException` inherit from `std::exception`. Grade validated via static `validateGrade()`.
- **ex01**: Adds `Form` class with const name, sign/exec grade requirements, and a signed boolean. `Bureaucrat::signForm()` calls `Form::beSigned()` which throws on insufficient grade. Both classes have their own `GradeTooHighException`/`GradeTooLowException`.
- **ex02** (TODO): `Form` becomes abstract `AForm`. Three concrete forms: `ShrubberyCreationForm` (sign 145, exec 137), `RobotomyRequestForm` (sign 72, exec 45), `PresidentialPardonForm` (sign 25, exec 5). Adds `execute()` to base and `executeForm()` to `Bureaucrat`.
- **ex03** (TODO): `Intern` class with `makeForm()` factory method — takes form name string + target, returns `AForm*`. Must avoid if/elseif chains (use function pointer array or similar).

Each exercise copies and extends files from the previous one.

## 42 Coding Rules

- All classes must follow **Orthodox Canonical Form** (default ctor, copy ctor, copy assignment, destructor) — exception classes are exempt
- No function implementations in headers (except templates)
- Headers use `#pragma once` for include guards
- Attributes are prefixed with `_` (e.g., `_name`, `_grade`, `_is_signed`)
- Forbidden: `using namespace`, `friend` keyword, `printf`, `alloc`/`free`
- All output to stdout, ending with newline
- `operator<<` overload for every class to print its info
