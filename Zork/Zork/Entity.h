#pragma once
#include <string>
#include <list>

enum class EntityType {
    ENTITY,
    ROOM,
    EXIT,
    ITEM,
    CREATURE,
    PLAYER,
    NPC
};

class Entity {
public:
    Entity(EntityType type, const std::string& name, const std::string& description);
    virtual ~Entity();

    virtual void Update();

    EntityType GetType() const;
    const std::string& GetName() const;
    const std::string& GetDescription() const;

    void Add(Entity* entity);
    void Remove(Entity* entity);
    const std::list<Entity*>& GetContents() const;

protected:
    EntityType type;
    std::string name;
    std::string description;

    std::list<Entity*> contents;
};

