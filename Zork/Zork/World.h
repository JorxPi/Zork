#pragma once
#include <list>
#include "Entity.h"

class Player;

class World {
public:
    World();
    ~World();

    void Start();

private:
    std::list<Entity*> entities;
    Player* player = nullptr;

    void CreateWorld();
};
