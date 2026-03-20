#ifndef REPO_H
#define REPO_H

#include "../Entity/Entity.h"

class Repo {
private:
    Entity entity[50];
    int size = 0;

public:
    void addElement(const Entity& e);
    bool deleteElement(int cod);
    bool updateElement(int cod, const Entity& newEntity);

    Entity& getElement(int index);
    Entity* getAll();
    int getSize() const;
};

#endif // REPO_H
