#include <iostream>
#include "Room.h"
#include "Exit.h"


Room::Room(const std::string& name, const std::string& description)
    : Entity(EntityType::ROOM, name, description) {
}

void Room::Update() {
    std::cout << "You are in: " << GetName() << "\n";
    std::cout << GetDescription() << "\n";

    if (!contents.empty()) {
        std::cout << "You see:\n";
        for (Entity* e : contents) {
            switch (e->GetType()) {
            case EntityType::ITEM:
                std::cout << " - An item: " << e->GetName() << /*" — " << e->GetDescription() <<*/ "\n";
                break;

            case EntityType::EXIT: {
                Exit* exit = static_cast<Exit*>(e);
                std::cout << " - An exit to the " << exit->GetDirection() << " which leads to a " << exit->GetDestination()->GetName() << "\n";
                break;
            }
            default:

                break;
            }
        }
    }
}