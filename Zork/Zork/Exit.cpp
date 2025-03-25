#include "Exit.h"
#include "Room.h"
#include <iostream>

Exit::Exit(const std::string& direction, Room* origin, Room* destination)
    : Entity(EntityType::EXIT, "Exit", "A passage leading " + direction + " to the " + destination->GetName()),
    direction(direction), origin(origin), destination(destination) {
}

void Exit::Update() {
    std::cout << "There's an exit to the " << direction;
    if (destination) {
        std::cout << " that leads to " << destination->GetName();
    }
    std::cout << ".\n";
}

Room* Exit::GetDestination() const {
    return destination;
}

const std::string& Exit::GetDirection() const {
    return direction;
}