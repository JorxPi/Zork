#include "NPC.h"
#include <iostream>

NPC::NPC(const std::string& name, const std::string& description, const std::string& dialogue, Room* location)
    : Creature(name, description, location), dialogue(dialogue) {
    type = EntityType::NPC;
}

void NPC::Talk() const {
    std::cout << name << " says: \"" << dialogue << "\"\n";
}