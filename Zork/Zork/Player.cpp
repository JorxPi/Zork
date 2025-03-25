#include "Player.h"
#include "Room.h"
#include "Exit.h"
#include <iostream>
#include <sstream>

Player::Player(const std::string& name, const std::string& description, Room* starting_room)
    : Creature(name, description, starting_room) {
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