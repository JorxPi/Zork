#include "NPC.h"
#include "Player.h"
#include <iostream>

NPC::NPC(const std::string& name, const std::string& description, const std::string& dialogue, Room* location)
    : Creature(name, description, location), dialogue(dialogue) {
    type = EntityType::NPC;
}

void NPC::Talk(Player* player) {
    if (!dialogue_changed && !trigger_item.empty() && player->HasItem(trigger_item)) {
        dialogue = alternate_dialogue;
        dialogue_changed = true;
        player->RemoveItem(trigger_item);
    }

    std::cout << name << " says: \"" << dialogue << "\"\n";
}

void NPC::SetAlternateDialogueTrigger(const std::string& item_name, const std::string& new_dialogue) {
    trigger_item = item_name;
    alternate_dialogue = new_dialogue;
}