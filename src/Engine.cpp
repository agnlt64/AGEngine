#include "../headers/Engine.hpp"
#include "../headers/TextureManager.hpp"
#include "../headers/GameObject.hpp"
#include "../headers/Map.hpp"
#include "../headers/Components.hpp"

GameObject* player;
Map* map;

SDL_Renderer* Engine::renderer = nullptr;

Manager manager;
auto& newPlayer(manager.addEntity());

Engine::Engine()
{}

Engine::~Engine()
{}

void Engine::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
    Uint32 flags = SDL_WINDOW_SHOWN;

    if(fullscreen)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        renderer = SDL_CreateRenderer(window, -1, 0);
        if(renderer)
        {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        }

        isRunning = true;
    }
    else
    {
        isRunning = false;
    }

    player = new GameObject("../assets/player.png", 0, 0);
    map = new Map();
    
    newPlayer.addComponent<PositionComponent>();

}

void Engine::render()
{
    SDL_RenderClear(renderer);
    map->drawMap();
    player->render();
    SDL_RenderPresent(renderer);
}

void Engine::handleEvents()
{
    SDL_Event event;
    SDL_PollEvent(&event);

    switch (event.type)
    {
    case SDL_QUIT:
        isRunning = false;
        break;
    
    default:
        break;
    }
}

void Engine::update()
{
    player->update();
    manager.update();
}

void Engine::clean()
{
    delete map;
    delete player;
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}

bool Engine::running()
{
    return isRunning;
}
