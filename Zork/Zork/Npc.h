#pragma once
#include "Creature.h"
#include <string>

class NPC : public Creature {
public:
    NPC(const std::string& name, const std::string& description, const std::string& dialogue, Room* location);

    void Talk() const;

private:
    std::string dialogue;
};
