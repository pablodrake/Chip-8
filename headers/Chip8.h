#include "includes.h"

class Chip8
{   
    private:
    // Add member variables to represent the state of the Chip8 emulator
    bool drawFlag = 0;
    bool keyPressed;
    unsigned short opcode;
    unsigned char memory[4096]; //Ram
    unsigned char V[16]; // General purpose registers
    unsigned short I;    // Index register
    unsigned short pc;   // Program counter
    unsigned char gfx[64 * 32]; // Display
    unsigned char delay_timer;
    unsigned char sound_timer;
    unsigned short stack[16];
    unsigned short sp;   // Stack pointer
    bool key[16]; // Keypad
    unsigned char font[80] =
    {
        0xF0, 0x90, 0x90, 0x90, 0xF0, // 0
        0x20, 0x60, 0x20, 0x20, 0x70, // 1
        0xF0, 0x10, 0xF0, 0x80, 0xF0, // 2
        0xF0, 0x10, 0xF0, 0x10, 0xF0, // 3
        0x90, 0x90, 0xF0, 0x10, 0x10, // 4
        0xF0, 0x80, 0xF0, 0x10, 0xF0, // 5
        0xF0, 0x80, 0xF0, 0x90, 0xF0, // 6
        0xF0, 0x10, 0x20, 0x40, 0x40, // 7
        0xF0, 0x90, 0xF0, 0x90, 0xF0, // 8
        0xF0, 0x90, 0xF0, 0x10, 0xF0, // 9
        0xF0, 0x90, 0xF0, 0x90, 0x90, // A
        0xE0, 0x90, 0xE0, 0x90, 0xE0, // B
        0xF0, 0x80, 0x80, 0x80, 0xF0, // C
        0xE0, 0x90, 0x90, 0x90, 0xE0, // D
        0xF0, 0x80, 0xF0, 0x80, 0xF0, // E
        0xF0, 0x80, 0xF0, 0x80, 0x80  // F
    };

    public:
        /*
        void setOpcode(unsigned short opcode);
        void setMemory(int index, unsigned char value);
        void setRegisters(int index, unsigned char value);
        void setIRegister(unsigned char value);
        void setPc(unsigned char value);
        void setDelay_timer(unsigned char value);
        void setSound_timer(unsigned char value);
        void setStack(int index, unsigned short value);
        void setSp(unsigned short value);

        unsigned short getOpcode();
        unsigned char getMemory(int index);
        unsigned char getRegisters(int index);
        unsigned char getIRegister();
        unsigned char getPc();
        unsigned char getDelay_timer();
        unsigned char getSound_timer();
        unsigned short getStack(int index);
        unsigned short getSp();
        */
        unsigned char* getGfx();
        bool getDrawFlag();

        void setKey(int index, bool value);

        void initMem();
        void loadGame(std::string gamePath);
        void emulateCycle();

};