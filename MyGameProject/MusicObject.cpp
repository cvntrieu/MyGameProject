
#include "MusicObject.h"


void initMusic() {

    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        logErrorAndExit("SDL_mixer could not initialize! SDL_mixer Error: %s\n",
            Mix_GetError());
    }
}

// Background Music
Mix_Music* loadMusic(const char* path) {

    Mix_Music* music = Mix_LoadMUS(path); // mp3
    if (music == nullptr) {

        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION,
            SDL_LOG_PRIORITY_ERROR,
            "Could not load music! SDL_mixer Error: %s", Mix_GetError());
    }
    return music;
}

void playMusic(Mix_Music* music) {

    if (music == nullptr) return; // Ham ko lam gi them

    if (Mix_PlayingMusic() == 0) Mix_PlayMusic(music, -1);
    // Neu chua phat nhac thi phat tu dau va lap vo han (-1)
    else if (Mix_PausedMusic() == 1) Mix_ResumeMusic();
    // Neu nhac bi tam dung, ResumeMusic tiep tuc phat tu vi tri hien tai
}

// Abrupt Music (Short Sound and Collision)

Mix_Chunk* loadSound(const char* path) {

    Mix_Chunk* chunk = Mix_LoadWAV(path);
    if (chunk == nullptr) {

        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION,
            SDL_LOG_PRIORITY_ERROR,
            "Could not load sound! SDL_mixer Error: %s", Mix_GetError());
    }
    return chunk;
}

void playChunk(Mix_Chunk* chunk) {

    if (chunk != nullptr) Mix_PlayChannel(-1, chunk, 0); // 0 = one time
}
