#pragma once
#include "Creature.h"
#include <string>

class Item;

class Player;

class NPC : public Creature {
public:
    NPC(const std::string& name, const std::string& description, const std::string& dialogue, Room* location);

    void Talk(Player* player);
    void SetAlternateDialogueTrigger(const std::string& item_name, const std::string& new_dialogue);

private:
    std::string dialogue;
    std::string alternate_dialogue;
    std::string trigger_item;
    bool dialogue_changed = false;

};
