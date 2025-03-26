#include "Item.h"
#include <iostream>

Item::Item(const std::string& name, const std::string& description)
    : Entity(EntityType::ITEM, name, description) {
}

void Item::Update() {
    if (!contents.empty()) {
        std::cout << GetName() <<" contains a ";
        for (Entity* e : contents) {
            std::cout  << e->GetName() << " inside it." << "\n";
            std::cout << " - " << e->GetName() << ": " << e->GetDescription() << "\n";
        }
    }
    else {
        std::cout << GetName() << " has nothing insite it.";
    }
}