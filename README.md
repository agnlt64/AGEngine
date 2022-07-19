# AGEngine
This is a game engine that I'm creating using C++ and SDL2.

## Installation process
For now, there are only the build instructions for Linux (Ubuntu).  
First install the SDL2 library:  
```
git clone https://github.com/ABFStudio/AGEngine.git
cd AGEngine/
g++ src/*.cpp -o engine -lSDL2 -lSDL2_image
./engine
```
This will create a window to show you the basic things you can do with this engine.

## How to use it
You must write to write your code in the `Engine.cpp` file.  
There are some functions and classes you can use. 

#
# `ECS.hpp`

This file contains the core of the engine. 
## `Component` class
You can create your own components by creating a class which inherits of the `Component` class: 
```
#include "ECS.hpp"

class MyComponent : public Component
{
    /* Custom code */
};
```
The `Component` class has some funcions that you have to override when you create a custom component.
```
#include "ECS.hpp"

class MyComponent : public Component
{
    // initializes the component
    void init() override
    { 
        /* code */ 
    }

    // update the component
    void update() override 
    { 
        /* code */ 
    }  

    // draw the component (not required)
    void draw() override
    { 
        /* ... */ 
    }

    /* Custom code */
};
```
## `Manager` class
This class is used to manage the entities. It is required to create entities in the game. You can create with the following code:
```
Manager manager;
```
It doesn't need to be initialized to work properly, but you have to update it in the `Engine::update()` function: 
```
void Engine::update()
{
    /* Other updates */
    manager.update();
}
```

## `Entity` class
This class represents all the entities in the game. You can create on like this:  
```
Entity myEntity(manager.addEntity());
```
There are builtins methods in this class to manipulate entities:  
`myEntity.addComponent<MyComponent>();`  
This methods is used to attach a component (custom or not) to an entity.  

`myEntity.getComponent<MyComponent>().doSomething(arg1, arg2, ...);`  
This method is used to get a component that you have already attached to an entity. Once you called this method, you can use a function of the component class that you just got.  
For example:  
`myEntity.getComponent<PositionComponent>().setPosition(500, 200);`  
Here, I set the position of an entity to `x = 500px` to the right and `y = 200px` down.  

`myEntity.hasComponent<MyComponent>();`  
This method is used in conditions to check if an entity  has a given component.  
For example:  
```
if(myEntity.hasComponent<MyComponent>())
{
    /* Do something */
}
```

#
# `Map.hpp`
This file contains the code to manage maps. For now, they are represented by arrays of integers. This will change in the future. But you can edit the map in the `Map.cpp` file by changing the `level1` array. `0` corresponds to water, `1` to dirt and `2` to grass. In the future, you will be able to load and draw maps from external files (`xml`, `tmx`...).  
You can instanciate the `Map` class in the `Engine.cpp` file, in the `Engine::init()` function:  
```
#include "../headers/Map.hpp"
#include "../headers/Engine.hpp"

void Engine::init()
{
    /* Code to init the game */

    Map* myMap = new Map()
}
```
Then you have to draw your map in the `Engine::render()` function:
```
void Engine::render
{
    /* Code to render the game */
   myMmap->drawMap();
}
```
Don't forget to delete your map in the `Engine::clean()` function:  
```
void Engine::clean()
{
    delete myMap;

    /* Code to clean the engine */
}
```

#
# `GameObject.hpp`
This file represents the GameObjects in the engine. You can create one like this:
```
#include "../headers/GameObject.hpp"
#include "../headers/Engine.hpp"

void Engine::init()
{
    /* Code to init the game */

    GameObject* myGameObject = new GameObject("path/to/image", xpos, ypos);
}
```
Next you have to update your `GameObject` in the `Engine::update()` function and render it in the `Engine::render()`:
```
void Engine::render()
{  
    myGameObject->render();
}

void Engine::update()
{
    myGameObject->update();
}
```
As always, don't forget to delete all you GameObjects in the `Engine::clean()`:
```
void Engine::clean()
{
    delete myGameObject;

    /* Code to clean the engine */
}
```

#
# Builtins components
`PositionComponent`
`KeyboardComponent` to move the sprite   
`SpriteComponent` to attach a sprite to an entity  
## Coming soon
Documentation for `Keyboard` and `Sprite` components.  
`TileComponent` to manage tiles  
And better map management.

