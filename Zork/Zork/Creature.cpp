#include "Creature.h"
#include "Room.h"
#include <iostream>

Creature::Creature(const std::string& name, const std::string& description, Room* starting_room)
    : Entity(EntityType::CREATURE, name, description), current_room(starting_room) {
}

void Creature::Update() {
    std::cout << GetName() << " is here. " << GetDescription() << "\n";
}

Room* Creature::GetCurrentRoom() const {
    return current_room;
}

void Creature::SetCurrentRoom(Room* room) {
    current_room = room;
}