
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


## Just like INS_LDA_IM mainly we have focused on 5-6 addressing mode
INS_LDA_IM , INS_LDA_ZP  (3 cycles), INS_LDA_ZPX (4 cycles)


## Format of Byte Ordering

   ### Big-Endian (BE):

In big-endian systems, the most significant byte (MSB) is stored at the lowest memory address.
The subsequent bytes are stored at higher memory addresses, with the least significant byte (LSB) at the highest address.
   ### Little-Endian (LE):

In little-endian systems, the least significant byte (LSB) is stored at the lowest memory address.
The subsequent bytes are stored at higher memory addresses, with the most significant byte (MSB) at the highest address. 


## Diagram Of CPU and Mem Struct

<img src="https://cdn.sanity.io/images/l2tpt56d/production/83a8c8b7f77f4c4b7a358e27fa1f5f6458dfbff2-2074x1100.png" alt="Alt Text">

## Authors

- [@Bibhabendu Mukherjee](https://github.com/BibhabenduMukherjee)

