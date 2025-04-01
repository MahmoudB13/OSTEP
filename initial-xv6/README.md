# Initial xv6

## Overview
The `initial-xv6` project is an introduction to xv6, a simple Unix-like operating system used for teaching OS concepts. This project involves modifying the xv6 source code to understand process management, system calls, and kernel internals.

## Project Structure
- **`src/`** – Contains the xv6 source code.
- **`test-getreadcount.sh`** – A script to test the implementation of a new system call.
- **`Makefile`** – Used to build xv6 and run tests.

## Setup & Compilation
To compile xv6, run:
```sh
make
```
This will build the xv6 kernel and necessary binaries.

## Modifications
- Added a system calls that returns the value of a counter called `readcount` which is incremented every time any process calls the read() system call.

## Testing
To test the modified xv6, run:
```sh
make test
```
This will execute `test-getreadcount.sh` to validate the system call modifications.

## Cleaning Up
To remove compiled binaries and test outputs, run:
```sh
make clean
```
This will also invoke `make clean` inside the `src/` directory to ensure a full cleanup.
