#include "World.h"
#include "Room.h"
#include "Item.h"
#include "Exit.h"
#include "Player.h"
#include "Creature.h"
#include "Npc.h"
#include <iostream>

World::World() {
    CreateWorld();
}

World::~World() {
    for (Entity* e : entities)
        delete e;
}

void World::Start() {
    if (player && player->GetCurrentRoom()) {
        player->GetCurrentRoom()->Update();
    }

    while (true) {
        player->Update();
    }
}

void World::UnlockHiddenGrove() {
    stone_wall->Add(toGrove);
    hidden_grove->Add(toWall2);

    stone_wall->SetDescription("The remains of a mossy stone wall lie scattered on the ground. A path now leads west into the hidden grove.");

    std::cout << "You can now go west.\n";
}

void World::UnlockCloset() {
    bedroom->Add(toCloset);

    bedroom->SetDescription("A modest bedroom with a wooden bed, a candlelit nightstand, and an massive open closet door leading north.");

    std::cout << "You unlocked the closet. You can now go north.\n";
}

void World::CreateWorld() {
    // Rooms
    Room* hall = new Room("Hall", "A large, echoing stone hall with torches on the walls.");
    Room* garden = new Room("Garden", "A peaceful garden with trimmed hedges, blooming flowers, and a stone fountain gently trickling water in the center.");
    bedroom = new Room("Bedroom", "A modest bedroom with a wooden bed, a candlelit nightstand, and a massive locked closet.");
    closet = new Room("Closet", "A cramped, dusty closet filled with hanging cloaks and the faint scent of old cedar. Something feels... off.");
    Room* magical_forest = new Room("Magical Forest", "An ethereal forest with glowing trees, soft purple mist, and creatures watching from the shadows.");
    Room* greenhouse = new Room("Greenhouse", "A humid glasshouse filled with exotic plants, tangled vines, and the buzzing of tiny insects.");
    stone_wall = new Room("Stone Wall", "A moss-covered stone wall blocks your way. It looks old and unstable — maybe it could fall.");
    hidden_grove = new Room("Hidden Grove", "A quiet, untouched grove hidden behind the fallen wall. The air feels different here.");

    // NPC
    NPC* npc = new NPC("Old Man", "He looks wise and carries a walking stick.", "Welcome, traveler. The owners of this estate vanished long ago... yet their presence lingers.", hall);
    NPC* unicorn = new NPC("Unicorn", "A serene white unicorn with silver eyes. It nods at you in greeting.", "*Elah'thar shil'anth veilum... qiros'na melithil.*", magical_forest);
    NPC* goblin = new NPC("Goblin", "A mischievous green goblin crouches in the shadows, grinning with sharp teeth and clutching a satchel full of who-knows-what.", "Got any shinies?", magical_forest);

    // Items
    Item* box = new Item("Wooden Box", "An old wooden box with a rusty latch.");
    Item* brick = new Item("Brick", "A solid, weathered brick. It's probably not very useful, but you never know.");
    Item* small_key = new Item("Small Key", "A tiny key with delicate engravings. It looks like it could open something important.");

    // Exits
    Exit* toGarden = new Exit("south", hall, garden);
    Exit* toHall = new Exit("north", garden, hall);
    Exit* toBedroom = new Exit("east", hall, bedroom);
    Exit* toHall2 = new Exit("west", bedroom, hall);
    toCloset = new Exit("north", bedroom, closet);
    Exit* toBedroom2 = new Exit("south", closet, bedroom);
    Exit* toMagic = new Exit("north", closet, magical_forest);
    Exit* toCloset2 = new Exit("south", magical_forest, closet);
    Exit* toGreenhouse = new Exit("east", garden, greenhouse);
    Exit* toGarden2 = new Exit("west", greenhouse, garden);
    Exit* toWall = new Exit("west", garden, stone_wall);
    Exit* toGarden3 = new Exit("east", stone_wall, garden);
    toGrove = new Exit("west", stone_wall, hidden_grove);
    toWall2 = new Exit("east", hidden_grove, stone_wall);

    hall->Add(npc);
    magical_forest->Add(unicorn);
    magical_forest->Add(goblin);
    hall->Add(box);
    hall->Add(toGarden);
    hall->Add(toBedroom);
    garden->Add(brick);
    garden->Add(toHall);
    garden->Add(toGreenhouse);
    garden->Add(toWall);
    bedroom->Add(toHall2);
    //bedroom->Add(toCloset);
    closet->Add(toBedroom2);
    closet->Add(toMagic);
    magical_forest->Add(toCloset2);
    greenhouse->Add(toGarden2);
    stone_wall->Add(toGarden3);
    box->Add(small_key);

    player = new Player("You", "Just an adventurer trying to explore.", hall, this);

    entities.push_back(hall);
    entities.push_back(garden);
    entities.push_back(bedroom);
    entities.push_back(closet);
    entities.push_back(greenhouse);
    entities.push_back(stone_wall);
    entities.push_back(hidden_grove);
    entities.push_back(toGarden);
    entities.push_back(toHall);
    entities.push_back(toBedroom);
    entities.push_back(toHall2);
    entities.push_back(toCloset);
    entities.push_back(toBedroom2);
    entities.push_back(toGreenhouse);
    entities.push_back(toGarden2);
    entities.push_back(toWall);
    entities.push_back(toGrove);
    entities.push_back(toWall2);
    entities.push_back(toGarden3);
    entities.push_back(npc);
    entities.push_back(box);
    entities.push_back(small_key);
    entities.push_back(brick);
    entities.push_back(unicorn);
    entities.push_back(goblin);
    entities.push_back(player);
}