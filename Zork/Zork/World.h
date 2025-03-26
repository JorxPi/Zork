#pragma once
#include <list>
#include "Entity.h"

class Player;

class Room;

class Exit;

class World {
public:
    World();
    ~World();

    void Start();
    void UnlockHiddenGrove();
    void UnlockCloset();

private:
    std::list<Entity*> entities;
    Player* player = nullptr;

    Room* hidden_grove = nullptr;
    Room* stone_wall = nullptr;
    Exit* toGrove = nullptr;
    Exit* toWall2 = nullptr;

    Room* bedroom = nullptr;
    Room* closet = nullptr;
    Exit* toCloset = nullptr;

    void CreateWorld();
};
