

#include "Painter.h"

using namespace std;


void waitUntilKeyPressed();


int main(int argc, char* argv[])
{
    
    Graphics graphics;
    graphics.init();

    SDL_Texture* background = graphics.loadTexture("C:\\Users\\ADMIN\\source\\repos\\MyGameProject\\vecteezy_cartoon-colorful-panorama-of-spring-summer-beautiful-nature_7633071-1.jpg");
    graphics.prepareScene(background);
    graphics.presentScene();
    waitUntilKeyPressed();

    SDL_Texture* spongeBob = graphics.loadTexture("C:\\Users\\ADMIN\\source\\repos\\MyGameProject\\medium.png");
    graphics.renderTexture(spongeBob, 200, 200);
    graphics.presentScene();
    waitUntilKeyPressed();

    SDL_DestroyTexture(spongeBob);
    spongeBob = NULL;
    SDL_DestroyTexture(background);
    background = NULL;

    graphics.quit();
    return 0;
}


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
