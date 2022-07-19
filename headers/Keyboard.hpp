#pragma once

#include "Engine.hpp"
#include "ECS.hpp"
#include "Components.hpp"
#include <iostream>

class Keyboard : public Component
{
public:
    Keyboard(const char* languageCode)
    {
        keycode = languageCode;
    }

    Keyboard()
    {
        keycode = "fr";
    }

    ~Keyboard() {}

    const char* keycode;
    TransformComponent* transform;
    
    void init() override
    {
        transform = &entity->getComponent<TransformComponent>();
    }

    void update() override
    {
        if(Engine::event.type == SDL_KEYDOWN)
        {
            if(keycode == "fr")
            {
                switch (Engine::event.key.keysym.sym)
                {
                case SDLK_z:
                    transform->velocity.y = -1;
                    break;
                case SDLK_s:
                    transform->velocity.y = 1;
                    break;
                case SDLK_q:
                    transform->velocity.x = -1;
                    break;
                case SDLK_d:
                    transform->velocity.x = 1;
                    break;
                default:
                    break;
                }
            }
        }
        else if(keycode == "us")
        {
            switch (Engine::event.key.keysym.sym)
            {
            case SDLK_w:
                transform->velocity.y = -1;
                break;
            case SDLK_a:
                transform->velocity.x = 1;
                break;
            case SDLK_d:
                transform->velocity.x = 1;
                break;
            case SDLK_s:
                transform->velocity.y = -1;
                break;
            default:
                break;
            }
        }
        else if(keycode == "universal")
        {
            switch (Engine::event.key.keysym.sym)
            {
            case SDLK_UP:
                transform->velocity.y = -1;
                break;
            case SDLK_DOWN:
                transform->velocity.y = 1;
                 break;
            case SDLK_LEFT:
                transform->velocity.x = -1;
                break;
            case SDLK_RIGHT:
                transform->velocity.x = 1;
                break;
            default:
                break;
            }
        }
        
        if(Engine::event.type == SDL_KEYUP)
        {
            if(keycode == "fr")
            {
                switch (Engine::event.key.keysym.sym)
                {
                case SDLK_z:
                    transform->velocity.y = 0;
                    break;
                case SDLK_s:
                    transform->velocity.y = 0;
                    break;
                case SDLK_q:
                    transform->velocity.x = 0;
                    break;
                case SDLK_d:
                    transform->velocity.x = 0;
                    break;
                default:
                    break;
                }
            }
        }
        else if(keycode == "us")
        {
            switch (Engine::event.key.keysym.sym)
            {
            case SDLK_w:
                transform->velocity.y = 0;
                break;
            case SDLK_a:
                transform->velocity.x = 0;
                break;
            case SDLK_d:
                transform->velocity.x = 0;
                break;
            case SDLK_s:
                transform->velocity.y = 0;
                break;
            default:
                break;
            }
        }
        else if(keycode == "universal")
        {
            switch (Engine::event.key.keysym.sym)
            {
            case SDLK_UP:
                transform->velocity.y = 0;
                break;
            case SDLK_DOWN:
                transform->velocity.y = 0;
                 break;
            case SDLK_LEFT:
                transform->velocity.x = 0;
                break;
            case SDLK_RIGHT:
                transform->velocity.x = 0;
                break;
            default:
                break;
            }
        }
    }
};