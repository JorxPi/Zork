#pragma once
#include "Creature.h"
#include <string>

class Player : public Creature {
public:
    Player(const std::string& name, const std::string& description, Room* starting_room);

    void Update() override;
    void ProcessCommand(const std::string& command);

private:
    void Go(const std::string& direction);
};