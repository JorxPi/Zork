#pragma once
#include "Creature.h"
#include <string>

class World;

class Item;

class Player : public Creature {
public:
    Player(const std::string& name, const std::string& description, Room* starting_room, World* world);

    void Update() override;
    void ProcessCommand(const std::string& command);

private:
    World* world = nullptr;

    void Go(const std::string& direction);
    void Take(const std::string& item_name);
    void Drop(const std::string& item_name);
    void Throw(const std::string& item_name);
    void Open(const std::string& target);

    static const int MAX_ITEMS = 3;
    std::list<Item*> inventory;
};