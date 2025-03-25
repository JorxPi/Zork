#pragma once
#include "Entity.h"

class Room;

class Creature : public Entity {
public:
    Creature(const std::string& name, const std::string& description, Room* starting_room);

    virtual void Update() override;

    Room* GetCurrentRoom() const;
    void SetCurrentRoom(Room* room);

protected:
    Room* current_room;
};