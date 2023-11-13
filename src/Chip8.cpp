#include "Chip8.h"
void Chip8::initMem()
{
    keyPressed = false;
    drawFlag = false;
    delay_timer = 0;
    sound_timer = 0;
    pc = 0x200;
    sp = 0;
    I = 0;
    opcode = 0;

    //Clear stack
    std::fill_n(stack, 16, 0);

    //Put font in ram
    for(int i = 0; i < sizeof(font)/sizeof(font[0]); i++)
    {
        memory[80 + i] = font[i];
    }

};

void Chip8::loadGame(std::string gamePath)
{
    std::ifstream inputFile(gamePath, std::ios::binary);
    if(inputFile.is_open())
    {
        std::vector<unsigned char> buffer(std::istreambuf_iterator<char>(inputFile), {});
        // Copy the contents of the buffer to the memory starting at address 512
        for(int i = 0; i < buffer.size(); i++)
        {
            memory[512 + i] = buffer[i];
        }
    }
    else
    {
        std::cout << "Coul not load the file\n";
    }


};
void Chip8::emulateCycle()
{
    drawFlag = false;
    opcode = (memory[pc] << 8 | memory[pc + 1]);
    //std::cout << "Fetched opcode: 0x" << std::hex << std::setw(4) << std::setfill('0') << opcode << std::dec << std::endl;
    //std::cout << (opcode & 0xF000) << std::endl;

    switch(opcode & 0xF000)
    {   
        case 0x0000:
            switch(opcode & 0x00FF)
            {

                case 0x00E0: //Clear the display
                    std::fill_n(gfx, 64*32, 0);
                    pc += 2;
                break;

                case 0x00EE: //RET
                    sp--;
                    pc = stack[sp];
                    pc += 2;
                break;

                default:
                    pc += 2;
                    std::cout << "Unknown opcode 0x00FF\n";
                break;
            }
        break;

        case 0x1000: //JP addr
            pc = (opcode & 0x0FFF);
        break;

        case 0x2000: //CALL addr
            stack[sp] = pc;
            sp ++;
            pc = (opcode & 0x0FFF);
        break;

        case 0x3000: //SE Vx, byte
            if(V[(opcode & 0x0F00) >> 8] == (opcode & 0x00FF))
                pc += 4;
            else pc += 2;
        break;

        case 0x4000: //SNE Vx, byte
            if(V[(opcode & 0x0F00) >> 8] != (opcode & 0x00FF))
                pc += 4;
            else pc += 2;
        break;

        case 0x5000: //SE Vx, Vy
            if(V[(opcode & 0x0F00) >> 8] == V[(opcode & 0x00F0) >> 4])
                pc += 4;
            else pc += 2;
        break;

        case 0x6000: //LD Vx, byte
            V[(opcode & 0x0F00) >> 8] = (opcode & 0x00FF);
            pc += 2;
        break;

        case 0x7000: //ADD Vx, byte
            V[(opcode & 0x0F00) >> 8] += (opcode & 0x00FF);
            pc += 2;
        break;

        case 0x8000:
            switch(opcode & 0x000F)
            {
                case 0x0000: //LD Vx, Vy
                    V[(opcode & 0x0F00) >> 8] = V[(opcode & 0x00F0) >> 4];
                    pc += 2;
                break;

                case 0x0001: //OR Vx, Vy
                    V[(opcode & 0x0F00) >> 8] |= V[(opcode & 0x00F0) >> 4];
                    pc += 2;
                break;

                case 0x0002: //AND Vx, Vy
                    V[(opcode & 0x0F00) >> 8] &= V[(opcode & 0x00F0) >> 4];
                    pc += 2;
                break;

                case 0x0003: //XOR Vx, Vy
                    V[(opcode & 0x0F00) >> 8] ^= V[(opcode & 0x00F0) >> 4];
                    pc += 2;
                break;

                case 0x0004: //ADD Vx, vY
                {
                    V[(opcode & 0x0F00) >> 8] += V[(opcode & 0x00F0) >> 4];
                    if(V[(opcode & 0x00F0) >> 4] > (0xFF - V[(opcode & 0x0F00) >> 8]))
                        V[0xF] = 1;
                    else V[0xF] = 0;
                    pc += 2;
                break;
                }

                case 0x0005: //SUB Vx, Vy
                    if(V[(opcode & 0x00F0) >> 4] > V[(opcode & 0x0F00) >> 8])
                        V[0xF] = 0;
                    else V[0xF] = 1;
                    V[(opcode & 0x0F00) >> 8] -= V[(opcode & 0x00F0) >> 4];
                    pc += 2;
                break;
                case 0x0006: //SHR Vx {,Vy}
                    V[0xF] = V[(opcode & 0x0F00) >> 8] & 0x1;
                    V[(opcode & 0x0F00) >> 8] >>= 1;
                    pc += 2;
                break;
                case 0x0007: //SUBN Vx, Vy
                    if(V[(opcode & 0x00F0) >> 4] > V[(opcode & 0x0F00) >> 8])
                        V[0xF] = 1;
                    else V[0xF] = 0;
                    V[(opcode & 0x0F00) >> 8] = V[(opcode & 0x00F0) >> 4] - V[(opcode & 0x0F00) >> 8];
                    pc += 2;
                break;
                case 0x000E: //SHL Vx, {, Vy}
                    V[0xF] = V[(opcode & 0x0F00) >> 8] >> 7;
                    V[(opcode & 0x0F00) >> 8] <<= 1;
                    pc += 2;
                break;



                default:
                    std::cout << "Unknowm opcode 0x8FFF\n";
                break;
                
            }
        break;

        case 0x9000: //SNE Vx, Vy 
            if(V[(opcode & 0x0F00) >> 8] != V[(opcode & 0x00F0) >> 4])
                pc += 4;
            else pc += 2;
        break;

        case 0xA000: //LD I, addr
            I = (opcode & 0x0FFF);
            pc += 2;
        break;

        case 0xB000: //JP V0, addr
            pc = (opcode & 0x0FFF) + V[0];
        break;

        case 0xC000: //RND Vx, byte
            V[(opcode & 0x0F00) >> 8] = static_cast<unsigned char>(std::rand() % 256) & (opcode & 0x00FF);
            pc += 2;
        break;

        case 0xD000:
        {
            unsigned short x = V[(opcode & 0x0F00) >> 8];
            unsigned short y = V[(opcode & 0x00F0) >> 4];
            unsigned short height = opcode & 0x000F;

            V[0xF] = 0;  // Reset collision flag

            for (int row = 0; row < height; row++)
            {
                unsigned short spriteByte = memory[I + row];

                for (int col = 0; col < 8; col++)
                {
                    // Check each pixel in the sprite
                    if ((spriteByte & (0x80 >> col)) != 0)
                    {
                        if(gfx[((x + col) + ((y + row ) * 64)) % 2048] == 1)
                            V[0xF] = 1;
                        gfx[(x + col) + ((y + row) * 64) % 2048] ^= 1;
                    }
                }
            }

            drawFlag = true;
            pc += 2;
        }
        break;


        case 0xE000: 
            switch(opcode & 0x000F)
            {
                case 0x000E: //SKP Vx
                    if(key[V[(opcode & 0x0F00) >> 8]] != 0)
                        pc += 4;
                    else pc += 2;
                break;

                case 0x0001: //SKNP Vx
                    if(key[V[(opcode & 0x0F00) >> 8]] == 0)
                        pc += 4;
                    else pc += 2;
                break;

            }
        break;
    
        case 0xF000: 
            switch(opcode & 0x00FF)
            {
                case 0x0007: //LD Vx DT
                    V[(opcode & 0x0F00) >> 8] = delay_timer;
                    pc += 2;
                break;
                case 0x000A:
                {
                    keyPressed = false;

                    for (int i = 0; i < 16; ++i)
                    {
                        if (key[i] != 0)
                        {
                            // Key i is pressed
                            V[(opcode & 0x0F00) >> 8] = i;
                            keyPressed = true;
                        }
                    }

                    // If no key is pressed, skip the instruction and try again
                    if (!keyPressed)
                        return;

                    pc += 2;
                }
                break;

                case 0x0015: //LD DT, Vx
                    delay_timer = V[(opcode & 0x0F00) >> 8];
                    pc += 2;
                break;

                case 0x0018: //LD ST, Vx
                    sound_timer = V[(opcode & 0x0F00) >> 8];
                    pc += 2;
                break;

                case 0x001E: //ADD I, Vx
                    I = V[(opcode & 0x0F00) >> 8] + I;
                    pc += 2;
                break;

                case 0x0029: //LD F, Vx
                    if((I + V[(opcode & 0x0F00) >> 8]) > 255)
                        V[0xF] = 1;
                    else V[0xF] = 0;
                    I += V[(opcode & 0x0F00) >> 8];
                    pc *= 2;
                break;

                case 0x0033: //LD B, Vx
                    memory[I] = V[(opcode & 0x0F00) >> 8] / 100;
                    memory[I + 1]= (V[(opcode & 0x0F00) >> 8] / 10) % 10;
                    memory[I + 2] = V[(opcode & 0x0F00) >> 8] % 10;
                    pc += 2;
                break;

                case 0x0055: //LD [I], Vx
                    for(int i = 0; i <= ((opcode  & 0x0F00) >> 8); i++)
                    {
                        memory[I + i] = V[i];
                    }
                    I += ((opcode & 0x0F00) >> 8) + 1;
                    pc += 2;
                break;

                case 0x0065: //LD Vx, [I]
                    for(int i = 0; i <= ((opcode & 0x0F00) >> 8); i++)
                    {
                        V[i] = memory[I + i];
                    }
                    I += ((opcode & 0x0F00) >> 8) + 1;
                    pc += 2;
            }
        break;

    }

    if(delay_timer > 0)
        --delay_timer; 

    if(sound_timer > 0)
    {
        if(sound_timer == 1)
        {
            std::cout << "\a" << std::endl;
            --sound_timer;
        }

    }
};

unsigned char* Chip8::getGfx()
{
    return gfx;
};
bool Chip8::getDrawFlag()
{
    return drawFlag;
};
void Chip8::setKey(int index, bool value)
{
    if(index < 16)
        key[index] = value ? 1 : 0;
};
