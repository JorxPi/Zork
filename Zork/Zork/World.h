#pragma once
#include <list>
#include "Entity.h"

class Player;

class Room;

class Exit;

class NPC;

class Item;

class World {
public:
    World();
    ~World();

    void Start();
    void UnlockHiddenGrove();
    void UnlockCloset();
    void HollowBeastDefeated(Room* room);

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

    NPC* hollow_beast = nullptr;
    Item* medallion = nullptr;

    void CreateWorld();
};
