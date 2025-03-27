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

    bool HasItem(const std::string& item_name) const;
    void RemoveItem(const std::string& item_name);

private:
    World* world = nullptr;

    void Go(const std::string& direction);
    void Look();
    void Take(const std::string& item_name);
    void Drop(const std::string& item_name);
    void Throw(const std::string& item_name);
    void Open(const std::string& target);
    void Talk(const std::string& npc_name);
    void ShowInventory();
    void Attack(const std::string& target);

    static const int MAX_ITEMS = 3;
    std::list<Item*> inventory;
};