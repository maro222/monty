# 0x19. C - Stacks, Queues - LIFO, FIFO

## Monty Bytecode Interpreter

### Description

The **Monty Bytecode Interpreter** is a simple program designed to execute Monty bytecode files. Bytecode is a low-level, stack-based programming language. This interpreter processes Monty bytecode line by line, performing stack operations such as pushing, popping, and manipulating data.

Monty is used for learning and exploring stack-based operations, making it a great tool for understanding how interpreters and virtual machines function.

### Features

- **Stack Operations**: Supports fundamental stack operations like `push`, `pall`, `pint`, `pop`, `swap`, and more.
- **Error Handling**: Provides comprehensive error messages for various issues such as invalid instructions, file access errors, and memory allocation failures.
- **Line-by-Line Execution**: Reads and executes bytecode instructions line by line.
  
The interpreter halts execution upon encountering an error or successfully processing all instructions in the file.



**The monty program**

- If the user does not give any file or more than one argument to your program, print the error message USAGE: monty file,
 followed by a new line, and exit with the status EXIT_FAILURE
- If, for any reason, it’s not possible to open the file, print the error message Error: Can't open file <file>,
    followed by a new line, and exit with the status EXIT_FAILURE
  - where <file> is the name of the file
- If the file contains an invalid instruction, print the error message L<line_number>: unknown instruction <opcode>,
  followed by a new line, and exit with the status EXIT_FAILURE
  - where is the line number where the instruction appears.
  - Line numbers always start at 1
- The monty program runs the bytecodes line by line and stop if either:
  - it executed properly every line of the file
  - it finds an error in the file
  - an error occured
- If you can’t malloc anymore, print the error message Error: malloc failed, followed by a new line, and exit with status EXIT_FAILURE.


### ALX Team project
## Contributers:

- Omar Farouk
- Amal Dahshan

## Purpose:

The goal of this project is to create an interpreter for Monty ByteCodes files.

## **Usage:** monty file
  - where file is the path to the file containing Monty byte code
