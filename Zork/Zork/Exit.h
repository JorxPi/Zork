#pragma once
#include "Entity.h"

class Room;

class Exit : public Entity {
public:
    Exit(const std::string& direction, Room* origin, Room* destination);

    void Update() override;

    Room* GetDestination() const;
    const std::string& GetDirection() const;

private:
    std::string direction;
    Room* origin;
    Room* destination;
};