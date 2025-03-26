#pragma once
#include "Creature.h"
#include <string>

class Item;

class Player : public Creature {
public:
    Player(const std::string& name, const std::string& description, Room* starting_room);

    void Update() override;
    void ProcessCommand(const std::string& command);

private:
    void Go(const std::string& direction);
    void Take(const std::string& item_name);
    void Drop(const std::string& item_name);

    static const int MAX_ITEMS = 3;
    std::list<Item*> inventory;
};