#include <iostream>
#include <sstream>
#include "Player.h"
#include "World.h"
#include "Room.h"
#include "Exit.h"
#include "Item.h"
#include "Utils.h"

Player::Player(const std::string& name, const std::string& description, Room* starting_room, World* world)
    : Creature(name, description, starting_room), world(world) {
    type = EntityType::PLAYER;
}

void Player::Update() {
    std::string input;
    std::cout << "\n> ";
    std::getline(std::cin, input);

    ProcessCommand(input);
}

void Player::ProcessCommand(const std::string& command) {
    std::istringstream iss(command);
    std::string action;
    iss >> action;

    if (action == "go") {
        std::string direction;
        iss >> direction;
        Go(direction);
    }
    else if (action == "take") {
        std::string item;
        iss >> std::ws;
        std::getline(iss, item);
        Take(item);
    }
    else if (action == "drop") {
        std::string item;
        iss >> std::ws;
        std::getline(iss, item);
        Drop(item);
    }
    else if (action == "throw") {
        std::string item;
        iss >> std::ws;
        std::getline(iss, item);
        Throw(item);
    }
    else {
        std::cout << "I don't understand that command.\n";
    }
}

void Player::Go(const std::string& direction) {
    if (!current_room) return;

    for (Entity* e : current_room->GetContents()) {
        if (e->GetType() == EntityType::EXIT) {
            Exit* exit = static_cast<Exit*>(e);
            if (exit->GetDirection() == direction) {
                Room* dest = exit->GetDestination();
                SetCurrentRoom(dest);
                std::cout << "You go " << direction << ".\n";
                dest->Update();
                return;
            }
        }
    }

    std::cout << "You can't go that way.\n";
}

void Player::Take(const std::string& item_name) {
    if (inventory.size() >= MAX_ITEMS) {
        std::cout << "You can't carry more than " << MAX_ITEMS << " items.\n";
        return;
    }

    //Take from room
    for (Entity* e : current_room->GetContents()) {
        if (e->GetType() == EntityType::ITEM && CompareIgnoreCase(e->GetName(), item_name)) {
            Item* item = static_cast<Item*>(e);
            inventory.push_back(item);
            current_room->Remove(item);
            std::cout << "You picked up the " << item_name << ".\n";

            if (!item->GetContents().empty()) {
                item->Update();
            }
            return;
        }
    }

    //Take from item in inventory
    for (Item* container : inventory) {
        for (Entity* e : container->GetContents()) {
            if (e->GetType() == EntityType::ITEM && CompareIgnoreCase(e->GetName(), item_name)) {
                Item* inner = static_cast<Item*>(e);
                if (inventory.size() >= MAX_ITEMS) {
                    std::cout << "You can't carry more than " << MAX_ITEMS << " items.\n";
                    return;
                }

                container->Remove(inner);
                inventory.push_back(inner);
                std::cout << "You take the " << item_name << " from inside the " << container->GetName() << ".\n";

                if (!inner->GetContents().empty()) {
                    inner->Update();
                }
                return;
            }
        }
    }

    std::cout << "There's no item named '" << item_name << "' here.\n";
}

void Player::Drop(const std::string& item_name) {
    for (Item* item : inventory) {
        if (CompareIgnoreCase(item->GetName(), item_name)) {
            inventory.remove(item);
            current_room->Add(item);
            std::cout << "You dropped the " << item_name << ".\n";
            return;
        }
    }

    std::cout << "You're not carrying an item called '" << item_name << "'.\n";
}

void Player::Throw(const std::string& item_name) {
    if (!current_room) return;

    for (Item* item : inventory) {
        if (CompareIgnoreCase(item->GetName(), item_name)) {
            if (CompareIgnoreCase(item_name, "Brick") &&
                CompareIgnoreCase(current_room->GetName(), "Stone Wall")) {

                inventory.remove(item);
                delete item;

                std::cout << "You hurl the brick at the moss-covered wall...\n";
                std::cout << "With a heavy crash, the wall collapses, revealing a hidden path!\n";

                world->UnlockHiddenGrove();
                return;
            }

            std::cout << "Throwing that won't do anything useful here.\n";
            return;
        }
    }

    std::cout << "You don't have that item.\n";
}