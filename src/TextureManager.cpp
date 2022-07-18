#include "../headers/TextureManager.hpp"

TextureManager::TextureManager()
{}

TextureManager::~TextureManager()
{}

SDL_Texture* TextureManager::loadTexture(const char* texture)
{
    SDL_Surface* tempSurface = IMG_Load(texture);
    SDL_Texture* tex = SDL_CreateTextureFromSurface(Engine::renderer, tempSurface);
    SDL_FreeSurface(tempSurface);

    return tex;
}

void TextureManager::draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest)
{
    SDL_RenderCopy(Engine::renderer, tex, &src, &dest);
}