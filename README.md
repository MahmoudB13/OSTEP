
# OSTEP Projects  

This repository contains my implementations of projects from the [OSTEP Projects](https://github.com/remzi-arpacidusseau/ostep-projects), based on the book *Operating Systems: Three Easy Pieces* by Remzi H. Arpaci-Dusseau and Andrea C. Arpaci-Dusseau.  

These projects focus on core operating system concepts, including process management, file I/O, memory management, and shell scripting. Each project provides hands-on experience in implementing fundamental OS functionalities.  

---

## Projects Included  

### **Initial Utilities** ([`initial-utilities/`](./initial-utilities/))  
This project involves implementing a set of basic Unix-like utilities from scratch, mimicking core system commands such as:  
- `wcat` – A simplified version of `cat` for reading and displaying file contents.  
- `wgrep` – A basic implementation of `grep` for searching within files.  
- `wzip` & `wunzip` – Custom compression and decompression utilities using run-length encoding.  

---

### **Initial xv6** ([`initial-xv6/`](./initial-xv6/))  
This project involves modifying and extending the [xv6 operating system](https://pdos.csail.mit.edu/6.828/2021/xv6.html), a minimalistic reimplementation of Unix Version 6 used for educational purposes.  

🔹 **Tasks Implemented:**  
- Adding a custom system call to the xv6 kernel.  

---

### **Processes Shell** ([`processes-shell/`](./processes-shell/))  
This project involves building a simple shell that can execute commands, handle process creation, and support basic shell functionalities.  

🔹 **Features Implemented:**  
- **Executing commands**: Running both built-in and external commands.  
- **Process handling**: Creating child processes using `fork()` and executing them with `execv()`.  
- **Parallel execution**: Running parallel commands using `&`.  
- **Redirection**: Implementing file output redirection `>`.  

---

## Setup & Usage  

Each project contains a dedicated `README.md` with specific setup instructions. Below is a general guideline for compiling and running the projects:  

### **Cloning the Repository**  
```sh
git clone https://github.com/MahmoudB13/OSTEP.git  
cd OSTEP  
```

### **Compiling & Running**  

Navigate to a specific project directory and run:  

```sh
make  # Compile the project
./program-name [arguments]  # Run the program
```

For xv6, use:  
```sh
make qemu  # Run xv6 in QEMU emulator
```

---

## Testing  

To test the implementations, you can use the provided test scripts from the [OSTEP projects repository](https://github.com/remzi-arpacidusseau/ostep-projects/tree/master/tester).  

Example:  
```sh
./test-wcat.sh  
./test-wgrep.sh  
```

---
