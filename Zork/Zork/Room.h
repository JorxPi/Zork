#pragma once
#include "Entity.h"

class Room : public Entity {
public:
    Room(const std::string& name, const std::string& description);

    void Update() override;
};

