#include "World.h"
#include "Room.h"
#include "Item.h"
#include "Exit.h"
#include "Player.h"
#include "Creature.h"
#include <iostream>

World::World() {
    CreateWorld();
}

World::~World() {
    for (Entity* e : entities)
        delete e;
}

void World::Start() {
    // Show the first room just like in main()
    if (player && player->GetCurrentRoom()) {
        player->GetCurrentRoom()->Update();
    }

    while (true) {
        player->Update();
    }
}

void World::CreateWorld() {
    // Rooms
    Room* hall = new Room("Hall", "A large, echoing stone hall with torches on the walls.");
    Room* garden = new Room("Garden", "A peaceful garden with trimmed hedges, blooming flowers, and a stone fountain gently trickling water in the center.");

    // NPC
    Creature* npc = new Creature("Old Man", "He looks wise and carries a walking stick.", hall);

    // Items
    Item* box = new Item("Wooden Box", "An old wooden box with a rusty latch.");
    Item* brick = new Item("Brick", "A solid, weathered brick. It's probably not very useful, but you never know.");

    // Exits
    Exit* toGarden = new Exit("south", hall, garden);
    Exit* toHall = new Exit("north", garden, hall);

    // Add contents to rooms
    hall->Add(npc);
    hall->Add(box);
    hall->Add(toGarden);
    garden->Add(brick);
    garden->Add(toHall);

    // Player
    player = new Player("You", "Just an adventurer trying to explore.", hall);

    // Track all entities
    entities.push_back(hall);
    entities.push_back(garden);
    entities.push_back(toGarden);
    entities.push_back(toHall);
    entities.push_back(npc);
    entities.push_back(box);
    entities.push_back(brick);
    entities.push_back(player);
}