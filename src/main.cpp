#include "includes.h"
#include "Chip8.h"

Chip8 myChip8;

//Chip-8 variables
const int SCREEN_WIDTH = 1024, SCREEN_HEIGHT = 512, CHIP8_WIDTH = 64, CHIP8_HEIGHT = 32;
const int PIXEL_SIZE = SCREEN_WIDTH / CHIP8_WIDTH;
unsigned char* graphicsArray;
bool quitFlag = false;
std::string romPath;

SDL_Window* Window = nullptr;
SDL_Renderer* Renderer = nullptr;

//Initialize SDL2
void initializeSDL() {
    SDL_Init(SDL_INIT_VIDEO);

    Window = SDL_CreateWindow("Chip-8 Emulator", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    Renderer = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED);

    SDL_SetRenderDrawColor(Renderer, 0, 0, 0, 255);
    SDL_RenderClear(Renderer);
    SDL_RenderPresent(Renderer);
}

//Draw to screen method
void Draw(unsigned char* graphicsArray)
{
    //Scae factor for pixels
    const int pixelSize = SCREEN_HEIGHT / CHIP8_HEIGHT;

    //Background color
    SDL_SetRenderDrawColor(Renderer, 0, 0, 0, 255);
    SDL_RenderClear(Renderer);
    //Pixel color
    SDL_SetRenderDrawColor(Renderer, 0, 255, 0, 255);
    for (int y = 0; y < CHIP8_HEIGHT; ++y)
    {
        for (int x = 0; x < CHIP8_WIDTH; ++x)
        {
            if (graphicsArray[(y * CHIP8_WIDTH) + x] != 0)
            {
                int scaledX = x * pixelSize;
                int scaledY = y * pixelSize;

                // Draw a rectangle for the scaled pixel
                SDL_Rect pixelRect = {scaledX, scaledY, pixelSize, pixelSize};
                SDL_RenderFillRect(Renderer, &pixelRect);
            }

        }
    }
    SDL_RenderPresent(Renderer);
}


int main(int, char**){

    //Prompt the user for rom path, it has to be absolute
    std::cout << "Full rom path: \n";
    std::cin >> romPath;

    //Prepare SDL2 and Chip-8 state
    initializeSDL();
    myChip8.initMem();

    //Load game
    myChip8.loadRom(romPath);

    //Start emulation cycle
    while(!quitFlag)
    {
        myChip8.emulateCycle();

        //Draw if drawflag is set
        if(myChip8.getDrawFlag() == 1)
        {
            graphicsArray = myChip8.getGfx();
            Draw(graphicsArray);
        }

        //Get key state and update key array
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            switch (event.type) 
            {
                case SDL_QUIT:
                    quitFlag = true;
                break;
                case SDL_KEYDOWN:
                    // Map SDL key to CHIP-8 key
                    switch (event.key.keysym.sym) {
                        case SDLK_x: myChip8.setKey(0, 1); break;
                        case SDLK_1: myChip8.setKey(1, 1); break;
                        case SDLK_2: myChip8.setKey(2, 1); break;
                        case SDLK_3: myChip8.setKey(3, 1); break;
                        case SDLK_q: myChip8.setKey(4, 1); break;
                        case SDLK_w: myChip8.setKey(5, 1); break;
                        case SDLK_e: myChip8.setKey(6, 1); break;
                        case SDLK_a: myChip8.setKey(7, 1); break;
                        case SDLK_s: myChip8.setKey(8, 1); break;
                        case SDLK_d: myChip8.setKey(9, 1); break;
                        case SDLK_z: myChip8.setKey(10, 1); break;
                        case SDLK_c: myChip8.setKey(11, 1); break;
                        case SDLK_4: myChip8.setKey(12, 1); break;
                        case SDLK_r: myChip8.setKey(13, 1); break;
                        case SDLK_f: myChip8.setKey(14, 1); break;
                        case SDLK_v: myChip8.setKey(15, 1); break;
                    }
                    break;
                case SDL_KEYUP:
                    // Map SDL key to CHIP-8 key
                    switch (event.key.keysym.sym) {
                        case SDLK_x: myChip8.setKey(0, 0); break;
                        case SDLK_1: myChip8.setKey(1, 0); break;
                        case SDLK_2: myChip8.setKey(2, 0); break;
                        case SDLK_3: myChip8.setKey(3, 0); break;
                        case SDLK_q: myChip8.setKey(4, 0); break;
                        case SDLK_w: myChip8.setKey(5, 0); break;
                        case SDLK_e: myChip8.setKey(6, 0); break;
                        case SDLK_a: myChip8.setKey(7, 0); break;
                        case SDLK_s: myChip8.setKey(8, 0); break;
                        case SDLK_d: myChip8.setKey(9, 0); break;
                        case SDLK_z: myChip8.setKey(10, 0); break;
                        case SDLK_c: myChip8.setKey(11, 0); break;
                        case SDLK_4: myChip8.setKey(12, 0); break;
                        case SDLK_r: myChip8.setKey(13, 0); break;
                        case SDLK_f: myChip8.setKey(14, 0); break;
                        case SDLK_v: myChip8.setKey(15, 0); break;
                    }
                break;
            }
        }
        //Sleep to slow emulation sleep
        std::this_thread::sleep_for(std::chrono::microseconds(1850));
    }
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Quit();
}
