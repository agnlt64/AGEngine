#pragma once

#include "Engine.hpp"

class TextureManager
{
public:
    TextureManager();
    ~TextureManager();

    static SDL_Texture* loadTexture(const char* texture);
    static void draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest);

};
