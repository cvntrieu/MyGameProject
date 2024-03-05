

#include "BaseObject.h"
#include "MainObject.h"
#include "ThreatObject.h"

using namespace std;


void waitUntilKeyPressed()
{
    SDL_Event e;
    while (true) {
        if (SDL_PollEvent(&e) != 0 &&
            (e.type == SDL_KEYDOWN || e.type == SDL_QUIT))
            return;
        SDL_Delay(10);
    }
}


int main(int argc, char* argv[])
{
        
    SDL_Window* window = initWin();
    SDL_Renderer* renderer = initRen(window);

    SDL_Texture* background = loadTexture("C:\\Users\\ADMIN\\source\\repos\\MyGameProject\\vecteezy_cartoon-colorful-panorama-of-spring-summer-beautiful-nature_7633071-1.jpg", renderer);
    SDL_RenderCopy(renderer, background, NULL, NULL);
    SDL_RenderPresent(renderer);
    waitUntilKeyPressed();

    MainObject player;
    player.texture = loadTexture("C:\\Users\\ADMIN\\source\\repos\\MyGameProject\\medium.png", renderer);
    render(renderer, player.texture, player.rect);
    SDL_RenderPresent(renderer);
    waitUntilKeyPressed();

    bool quit = false;
    SDL_Event event;
    ThreatObject* threat = new ThreatObject();
    threat->texture = loadTexture("C:\\Users\\ADMIN\\source\\repos\\MyGameProject\\Threat.png", renderer);

    while (!quit)
    {

        while (SDL_PollEvent(&event)) {

            if (event.type == SDL_QUIT) {

                quit = true;
                break;
            }
            else if (event.type == SDL_KEYDOWN) {


                SDL_RenderCopy(renderer, background, NULL, NULL);
                SDL_RenderPresent(renderer);

                player.HandleInputAction(event);
                render(renderer, player.texture, player.rect);
                SDL_RenderPresent(renderer);
                cout << player.rect.x << " " << player.rect.y << endl;
            }
        }
        render(renderer, threat->texture, threat->rect);
        SDL_RenderPresent(renderer);
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



