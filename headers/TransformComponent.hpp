#pragma once

#include "ECS.hpp"
#include "Vector2D.hpp"

class TransformComponent : public Component
{
public:
    TransformComponent()
    {
        position.x = 0.0f;
        position.y = 0.0f;
    }

    TransformComponent(float x, float y)
    {
        position.x = x;
        position.y = y;
    }

    ~TransformComponent() {}

    Vector2D position;
    Vector2D velocity;

    int speed = 3;

    void init() override
    {
        velocity.x = 0;
        velocity.y = 0;
    }

    void update() override
    {
        position.x += velocity.x * speed;
        position.y += velocity.y * speed;
    }
};