#include "Entity.h"

Entity::Entity(EntityType type, const std::string& name, const std::string& description)
    : type(type), name(name), description(description) {
}

Entity::~Entity() {}

void Entity::Update() {    
}

EntityType Entity::GetType() const {
    return type;
}

const std::string& Entity::GetName() const {
    return name;
}

const std::string& Entity::GetDescription() const {
    return description;
}

void Entity::SetDescription(const std::string& new_description) {
    description = new_description;
}

void Entity::Add(Entity* entity) {
    contents.push_back(entity);
}

void Entity::Remove(Entity* entity) {
    contents.remove(entity);
}

const std::list<Entity*>& Entity::GetContents() const {
    return contents;
}
