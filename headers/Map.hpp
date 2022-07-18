#pragma once

#include "Engine.hpp"
#include "TextureManager.hpp"

class Map
{
public:
    Map();
    ~Map();

    void loadMap(int arr[27][32]);
    void drawMap();

private:
    SDL_Rect src, dest;

    SDL_Texture* dirt;
    SDL_Texture* grass; 
    SDL_Texture* water;

    int map[27][32];
};

