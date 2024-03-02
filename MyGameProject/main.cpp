
#include "Graphics.h"
//nclude "move.cpp"

using namespace std;

void waitUntilKeyPressed()
{
    SDL_Event e;
    while (true) {
        if (SDL_PollEvent(&e) != 0 &&
            (e.type == SDL_KEYDOWN || e.type == SDL_QUIT))
            return;
        SDL_Delay(100);
    }
}


int main(int argc, char* argv[])
{
    
    SDL_Window* window = initWindows();
    SDL_Renderer* renderer = initRenderer(window);
   // Graphics graphics;

    SDL_Texture* background = loadTexture("C:\\Users\\ADMIN\\Documents\\GitHub\\SdlNew\\vecteezy_beautiful-seasonal-nature-mountain-landscape-illustration_9155728-1.jpg", renderer);
    prepareScene(background, renderer);
    presentScene(renderer);
    waitUntilKeyPressed();
    
    SDL_Texture* player = loadTexture("C:\\Users\\ADMIN\\source\\repos\\MyGameProject\\medium.png", renderer);
    renderTexture(player, renderer, 100, 100);
    presentScene(renderer);

    waitUntilKeyPressed();

    SDL_Event e;
    bool quit = false;
    

    while (!quit) {

        while (SDL_PollEvent(&e)) {

            int a, b;
          //  SDL_GetKeyboardState
            
            switch (e.type) {
            case SDL_QUIT:
                exit(0);
                break;
            case SDL_KEYDOWN:
                if (e.key.keysym.scancode == SDL_SCANCODE_UP);
                if (e.key.keysym.scancode == SDL_SCANCODE_DOWN);
                if (e.key.keysym.scancode == SDL_SCANCODE_LEFT);
                if (e.key.keysym.scancode == SDL_SCANCODE_RIGHT) {
                }
                break;
            case SDL_KEYUP:
                cerr << "\nUp: " << e.key.keysym.scancode;
                break;
            default: cerr << "\n.";
            }

        }
        SDL_Delay(100);
    }


    SDL_DestroyTexture(player);
    player = NULL;
    SDL_DestroyTexture(background);
    background = NULL;

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    SDL_Quit();
    return 0;
}


