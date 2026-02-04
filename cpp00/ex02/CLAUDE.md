# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project Overview

This is 42 School's C++ Module 00, Exercise 02 - a bank account simulation exercise. The task is to implement `Account.cpp` based on the provided `Account.hpp` header and match the expected output in `19920104_091532.log`.

## Build Commands

```bash
# Compile (no Makefile provided)
c++ -Wall -Wextra -Werror -std=c++98 Account.cpp tests.cpp -o account

# Run and compare with expected output
./account
diff <(./account) 19920104_091532.log
```

## Architecture

- **Account.hpp**: Provided header (do not modify) - defines the Account class interface with static tracking of all accounts
- **Account.cpp**: Implementation file - must implement all methods to produce output matching the log file
- **tests.cpp**: Provided test file (do not modify) - creates 8 accounts, performs deposits/withdrawals, displays status
- **19920104_091532.log**: Expected output format reference

## 42 School C++98 Requirements

- Must compile with `-Wall -Wextra -Werror -std=c++98`
- Orthodox Canonical Form when applicable (default constructor, copy constructor, assignment operator, destructor)
- No external libraries beyond STL
- Memory leaks are forbidden
