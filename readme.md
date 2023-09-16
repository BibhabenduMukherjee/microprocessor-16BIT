
## PC And SP
In computer architecture, PC stands for "Program Counter." It's a special register that keeps track of the memory address of the next instruction to be executed.

SP stands for "Stack Pointer." It's another register used for managing the program's call stack. It points to the top of the stack, facilitating stack-based operations like function calls and data storage.

## About the PSR
The Processor Status Register (PSR)  holds essential flags and status information about the CPU's state. It includes flags for arithmetic operations, interrupts, and system status. 



## PSR

Process Status Register

```c++
    Byte C : 1; 
    Byte Z : 1; 
    Byte I : 1; 
    Byte D : 1; 
    Byte B : 1; 
    Byte V : 1; 
    Byte N : 1; 
```


## Start with a basic inline program 

```c++
  // start with this 
  mem[0xFFFC] = CPU::INS_LDA_IM;
  mem[0xFFFD] = 0x42;

```
we are able to visualize the main stack and loaded inline instruction

## Authors

- [@Bibhabendu Mukherjee](https://github.com/BibhabenduMukherjee)

