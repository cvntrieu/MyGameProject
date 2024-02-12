

#include<iostream>  
#include "Painter.h"
#include "graphics.h"
#include<SDL.h>       
#include<SDL_image.h> 
#include<SDL_mixer.h> 
#include<SDL_ttf.h>   

using namespace std;

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const string WINDOW_TITLE = "An Implementation of Code.org Painter";

void initSDL(SDL_Window*& window, SDL_Renderer*& renderer);
void quitSDL(SDL_Window* window, SDL_Renderer* renderer);
void logSDLError(std::ostream& os,
    const std::string& msg, bool fatal = false);
void waitUntilKeyPressed();
SDL_Texture* loadTexture(string path, SDL_Renderer* renderer);
void renderTexture(SDL_Texture* texture, int x, int y, SDL_Renderer* renderer); // PH?I ??NH NGH?A HÀM LÊN ?ÂY!!!

int main(int argc, char* argv[])
{
    SDL_Window* window;
    SDL_Renderer* renderer;
    initSDL(window, renderer);
    Painter painter(window, renderer);

    SDL_SetRenderDrawColor(renderer, 255, 165, 0, 255);

   // painter.clearWithBgColor(BLUE_COLOR);

  //  SDL_Texture* background = loadTexture("C:\\Users\\ADMIN\\source\\repos\\MyGameProject\\vecteezy_cartoon-colorful-panorama-of-spring-summer-beautiful-nature_7633071-1.jpg", renderer);
    // D?u m?i tên thay vì ch?m v?i "expression must have class type but it has type * "
   // NULL1- Toàn b? txxture ?c sao chép
   // NULL2-  v? trí và kích th??c c?a texture trên renderer. 
   // N?u là NULL, texture s? ???c sao chép ??n v? trí (0,0) trên renderer
  //  SDL_Texture* player = loadTexture("C:\\Users\\ADMIN\\source\\repos\\MyGameProject\\medium.png", renderer);
    // V? hình ?nh nh? lên trung tâm ?nh n?n
  //  SDL_RenderCopy(renderer, background, NULL, NULL);
    //SDL_RenderPresent(renderer);
    //waitUntilKeyPressed();

  //  renderTexture(player, 100, 100, renderer);

    //SDL_RenderPresent(renderer);
   // waitUntilKeyPressed();
   
    Graphics graphics(renderer); // Buoc phai khoi tao renderer

    // Nap texture truoc vong lap
    SDL_Texture* target = graphics.loadTexture("C:\\Users\\ADMIN\\source\\repos\\MyGameProject\\medium.png");
    SDL_Event event;
    bool quit = false;
    while (!quit) {
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                exit(0);
                break;
            }
        }
        waitUntilKeyPressed();


        //SDL_DestroyTexture(player);
        //player = NULL;
        //SDL_DestroyTexture(background);
        //background = NULL;
        SDL_RenderClear(renderer); // Xoa man hinh
        int x, y;
        SDL_GetMouseState(&x, &y);
        cerr << x << ", " << y << endl;
        graphics.renderTexture(target, x, y);
        SDL_RenderPresent(renderer); // Cap nhat man hinh moi theo target tren
        SDL_Delay(3);
    }

    SDL_DestroyTexture(target);
    target = NULL;
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();
    quitSDL(window, renderer);
    return 0;
}


void initSDL(SDL_Window*& window, SDL_Renderer*& renderer)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
        logSDLError(std::cout, "SDL_Init", true);

    window = SDL_CreateWindow(WINDOW_TITLE.c_str(), SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == nullptr) logSDLError(std::cout, "CreateWindow", true);

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED |
        SDL_RENDERER_PRESENTVSYNC);

    if (renderer == nullptr) logSDLError(std::cout, "CreateRenderer", true);

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
 //   SDL_ShowCursor(0); // De ko hien con tro chuot
}

void logSDLError(ostream& os,
    const string& msg, bool fatal)
{
    os << msg << " Error: " << SDL_GetError() << endl;
    if (fatal) {
        SDL_Quit();
        exit(1);
    }
}


void quitSDL(SDL_Window* window, SDL_Renderer* renderer)
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void waitUntilKeyPressed()
{
    SDL_Event e;
    while (true) {
        if (SDL_WaitEvent(&e) != 0 &&
            (e.type == SDL_KEYDOWN || e.type == SDL_QUIT))
            return;
        SDL_Delay(100);
    }
}

SDL_Texture* loadTexture(string path, SDL_Renderer* renderer)
{
    SDL_Texture* newTexture = NULL;
    SDL_Surface* loadedSurface = IMG_Load(path.c_str());
    if (loadedSurface == NULL)
        cout << "Unable to load image " << path << " SDL_image Error: "
        << IMG_GetError() << endl;
    else {
        newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
        if (newTexture == NULL)
            cout << "Unable to create texture from " << path << " SDL Error: "
            << SDL_GetError() << endl;
        SDL_FreeSurface(loadedSurface);
    }
    return newTexture;
}

void renderTexture(SDL_Texture* texture, int x, int y, SDL_Renderer* renderer) {

    SDL_Rect dest;
    dest.x = x;
    dest.y = y;
    SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);

    SDL_RenderCopy(renderer, texture, NULL, &dest);
}
