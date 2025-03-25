#include "Item.h"
#include <iostream>

Item::Item(const std::string& name, const std::string& description)
    : Entity(EntityType::ITEM, name, description) {
}

void Item::Update() {
    std::cout << "Item: " << GetName() << " - " << GetDescription() << "\n";

    if (!contents.empty()) {
        std::cout << "Contains:\n";
        for (Entity* e : contents) {
            std::cout << " - " << e->GetName() << ": " << e->GetDescription() << "\n";
        }
    }
}