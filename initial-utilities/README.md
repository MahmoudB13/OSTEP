# Initial Utilities

## Overview
The `initial-utilities` directory contains implementations of basic Unix utilities as part of the OSTEP projects. These utilities help in understanding fundamental system calls, file I/O operations, and process management.

## Included Utilities
- **wcat** – Displays the contents of a file (similar to `cat`).
- **wgrep** – Searches for a pattern in a file (similar to `grep`).
- **wzip** – Compresses a file using run-length encoding.
- **wunzip** – Decompresses a file compressed by `wzip`.

## Setup & Compilation
Each utility has its own `Makefile`. To compile a specific utility, navigate to its directory and run:
```sh
make
```
For example, to compile `wcat`:
```sh
cd wcat && make
```

## Usage
Each utility has a dedicated `README.md` explaining its functionality, usage, and examples. You can refer to them for more details.

## Testing
To run tests for a specific utility, navigate to its directory and run:
```sh
make test
```
This will execute test scripts and validate the functionality.

## Cleaning Up
To remove compiled binaries and test outputs, run:
```sh
make clean
```
This will delete the binary files and the `tests-out` directory if it exists.
