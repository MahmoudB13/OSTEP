# Wish Shell

## Overview
Wish is a simple Unix shell that executes user commands, supports parallel execution (`&`), handles output redirection (`>`), and provides built-in commands like `cd`, `path`, and `exit`. It is inspired by the [OSTEP projects](https://github.com/remzi-arpacidusseau/ostep-projects/tree/master/processes-shell).

## Features
### 1. Interactive and Batch Mode
- **Interactive Mode:** Provides a command prompt (`wish> `) to accept and execute user commands.
- **Batch Mode:** Reads and executes commands from a specified file.

### 2. Command Execution
- Runs external programs using `fork()` and `execv()`.
- Searches for executables in directories set by the `path` command.
- Commands run sequentially unless specified for parallel execution.

### 3. Parallel Execution (`&`)
- Commands separated by `&` execute concurrently.
- The shell does not wait for one command to finish before starting another in parallel mode.

### 4. Built-in Commands
- `exit`: Terminates the shell.
- `cd <directory>`: Changes the working directory (prints an error if invalid or no arguments).
- `path <dir1> <dir2> ...`: Updates the search path for executables.
  - If no directories are provided, external commands cannot be found.

### 5. I/O Redirection (`>`)
- Redirects command output to a specified file.
- If more than one `>` is used, or if no valid filename is provided, an error is displayed.
- The redirection overwrites the file (append mode is not supported).

### 6. Error Handling
- Displays an error message (`An error has occurred`) when a command fails.
- Invalid syntax, incorrect built-in command usage, or missing files trigger errors.

## Installation
### Prerequisites
- A Unix-based system (Linux/macOS)
- A C compiler (e.g., `gcc`)

### Compilation
```sh
make
```

### Testing
```sh
make test
```

### Clean
```sh
make clean
```

## Usage
### Interactive Mode
Run the shell interactively:
```sh
./wish
```
Example commands:
```sh
wish> ls -l
wish> echo "Hello, world!" > output.txt
wish> cat output.txt
wish> cd /usr/bin
wish> path /bin /usr/bin
wish> exit
```

### Batch Mode
Run commands from a file:
```sh
./wish batchfile.txt
```
Example `batchfile.txt`:
```sh
ls -l
echo "Batch mode" > output.txt
cd /usr/bin
pwd
```
