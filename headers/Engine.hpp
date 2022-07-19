#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Engine
{
public:
    Engine();
    ~Engine();

    void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
    void handleEvents();
    void update();
    void render();
    void clean();
    bool running();

    static SDL_Event event;
    static SDL_Renderer* renderer;

private:
    bool isRunning;
    SDL_Window* window;
};