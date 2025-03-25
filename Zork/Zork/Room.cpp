#include <iostream>
#include "Room.h"

Room::Room(const std::string& name, const std::string& description)
    : Entity(EntityType::ROOM, name, description) {
}

void Room::Update() {
    std::cout << "You are in: " << GetName() << "\n";
    std::cout << GetDescription() << "\n";

    if (!contents.empty()) {
        std::cout << "You see:\n";
        for (Entity* e : contents) {
            std::cout << " - " << e->GetName() << ": " << e->GetDescription() << "\n";
        }
    }
}