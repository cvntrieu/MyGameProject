#pragma once
#ifndef MUSIC_OBJECT_H
#define MUSIC_OBJECT_H

#include "BaseObject.h"

void initMusic();

Mix_Music* loadMusic(const char* path);
void playMusic(Mix_Music* music);

Mix_Chunk* loadSound(const char* path);
void playChunk(Mix_Chunk* chunk);

#endif 
