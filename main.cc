/*
ALL HAPPENS FOR THE BEST IF WE OBSERVED EVERYTHING IN TREMS FOR ENERGY
@2023
initial main.cc startup for the simulation

*/
#include <iostream>
 using Byte = unsigned char;
 using Word = unsigned short;
 using u32 = unsigned int;

struct Mem{
    static const  u32 MAX_MEM = 1024*64;
    Byte  Data[MAX_MEM];
    void Init(){
        for( ::u32 i=0; i < MAX_MEM; i++ ){
            Data[i] = 0;
        }
    }
    //an overloaded operator->[] returns readonly access to the data Of Data[address]
    Byte operator[]( const ::u32 Address) const {
      return Data[Address];
    }

    Byte& operator[](u32 Address){
      return Data[Address];
    }
};

struct CPU
{
    /* data */
   
    Word PC;
    Word SP;
    

    // PSR 
    Byte  A, X, Y  ; // GP registers
    Byte C : 1; // status flg for carry
    Byte Z : 1; // zero flg
    Byte I : 1; // IRQ disable (interruption disable)
    Byte D : 1; // decimal mode
    Byte B : 1; // Break instruction-  pause PC 
    Byte V : 1; // overflow
    Byte N : 1; // negative

    void Reset(Mem& memory){
      // initial address for starting vector 
      PC = 0xFFFC;
      SP = 0x0100;
      C = Z = I = D = B = V = N = 0;
      A = X = Y = 0;
      memory.Init();

    }
    Byte Fetch(u32 &Cycles , Mem& mem){
     Byte Data =  mem[PC];
     PC++;
     Cycles--;
     
    }
    // register immediate mode opcode
    static const Byte INS_LDA_IM = 0xA9;

    // instruction opcode and the data(operand)
    void Execute(u32 Cycles,Mem &mem){
       while(Cycles > 0){
      // fetch the ins from pointed by PC
       Byte Ins =  Fetch(Cycles , mem);
       
       switch (Ins)
       {
        case INS_LDA_IM:
        
        {
          // value (LDA) operation 
          Byte Value = Fetch(Cycles , mem);
          A = Value;
          Z = (A == 0);
          N = (A & 0b10000000 > 0 );
        }
          default : break;
       }
       }
    }
};


int main(){

  Mem mem;
  CPU cpu;
  cpu.Reset(mem);
  // manual load
  mem[0xFFFC] = CPU::INS_LDA_IM;
  mem[0xFFFD] = 0x42;
  cpu.Execute(2 , mem);
}