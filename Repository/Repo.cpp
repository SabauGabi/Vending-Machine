#include "Repo.h"

void Repo::addElement(const Entity& e) {
    if (size < 50) {
        entity[size++] = e;
    }
}

bool Repo::deleteElement(int cod) {
    for (int i = 0; i < size; ++i) {
        if (entity[i].getCod() == cod) {
            for (int j = i; j < size - 1; ++j)
                entity[j] = entity[j + 1];
            size--;
            return true;
        }
    }
    return false;
}

bool Repo::updateElement(int cod, const Entity& newEntity) {
    for (int i = 0; i < size; ++i) {
        if (entity[i].getCod() == cod) {
            entity[i] = newEntity;
            return true;
        }
    }
    return false;
}

Entity& Repo::getElement(int index) {
    return entity[index];
}

Entity* Repo::getAll() {
    return entity;
}

int Repo::getSize() const {
    return size;
}
