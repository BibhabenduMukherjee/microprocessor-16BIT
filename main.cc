/*
ALL HAPPENS FOR THE BEST IF WE OBSERVED EVERYTHING IN TREMS FOR ENERGY
@2023
initial main.cc startup for the simulation

*/
 using Byte = unsigned char;
 using Word = unsigned short;
 using u32 = unsigned int;

struct Mem{
    static constexpr u32 MAX_MEM = 1024*64;
    Byte  Data[MAX_MEM];
    void Init(){
        for( u32 i=0; i < MAX_MEM; i++ ){
            Data[i] = 0;
        }
    }
};

struct CPU
{
    /* data */
   
    Word PC;
    Word SP;
    Byte A;

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
};


int main(){
  Mem mem;
  CPU cpu;
  cpu.Reset(mem);
}