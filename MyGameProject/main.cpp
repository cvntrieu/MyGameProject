

#include "BaseObject.h"
#include "MainObject.h"
#include "ThreatObject.h"

#define ThreatWidth  200
#define ThreatHeight 131

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

using namespace std;


void waitUntilKeyPressed()
{
    SDL_Event e;
    while (true) {
        if (SDL_PollEvent(&e) != 0 && (e.type == SDL_KEYDOWN || e.type == SDL_QUIT)) return;
        SDL_Delay(1);
    }
}


int main(int argc, char* argv[])
{
        
    SDL_Window* window = initWin();
    SDL_Renderer* renderer = initRen(window);

    SDL_Texture* background = loadTexture("C:\\Users\\ADMIN\\source\\repos\\MyGameProject\\vecteezy_cartoon-colorful-panorama-of-spring-summer-beautiful-nature_7633071-1.jpg", renderer);
    SDL_RenderCopy(renderer, background, NULL, NULL);

    MainObject player;
    player.texture = loadTexture("C:\\Users\\ADMIN\\source\\repos\\MyGameProject\\medium.png", renderer);
    render(renderer, player.texture, player.rect);


    ThreatObject threat;
    threat.texture = loadTexture("C:\\Users\\ADMIN\\source\\repos\\MyGameProject\\Plane2.png", renderer);


    bool quit = false;
    SDL_Event event;

    while (!quit)
    {

        while (SDL_PollEvent(&event)) {

            if (event.type == SDL_QUIT) {

                quit = true;
            }
            else if (event.type == SDL_KEYDOWN) {

                player.HandleInputAction(event);
                cout << player.rect.x << " " << player.rect.y << endl;
            }
        }

        threat.moveControl();

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, background, NULL, NULL);
        render(renderer, player.texture, player.rect);
        render(renderer, threat.texture, threat.rect);
        SDL_RenderPresent(renderer);
     //   SDL_Delay(10);
    }

    SDL_DestroyTexture(player.texture);
    player.texture = NULL;
    SDL_DestroyTexture(background);
    background = NULL;


    IMG_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}



