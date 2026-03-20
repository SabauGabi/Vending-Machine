//
// Created by Gabi on 4/29/2025.
//

#include "Entity.h"

#include <string.h>

Entity::Entity() {
    this->cod = 0;
    this->name = nullptr;
    this->price = 0;
}
Entity& Entity::operator=(const Entity& other) {
    if (this != &other) {
        delete[] name;
        cod = other.cod;
        price = other.price;
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
    }
    return *this;
}
Entity::Entity(int cod, char *name, int price) {
    this->cod = cod;
    this->price = price;
    if (name) {
        this->name = new char[strlen(name)+1];
        strcpy(this->name, name);
    } else {
        this->name = new char[1];
        this->name[0] = '\0';
    }
}

Entity::Entity(Entity &entity) {
    this->cod = entity.cod;
    this->name = new char[strlen(entity.name)+1];
    strcpy(this->name, entity.name);
    this->price = entity.price;
}

Entity::~Entity() {
    if (name != nullptr) {
        delete[] name;
        name = nullptr;
    }
}

int Entity::getCod() const {
    return cod;
}

void Entity::setCod(int cod) {
    this->cod = cod;
}

int Entity::getPrice() const {
    return price;
}

void Entity::setPrice(int price) {
    this->price = price;
}

const char * Entity::getName() const {
    return name;
}

void Entity::setName(const char *name) {
    delete[] this->name;
    this->name = new char[strlen(name)+1];
    strcpy(this->name, name);
}
