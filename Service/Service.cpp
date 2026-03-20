#include "Service.h"
#include <string.h>
#include "Validator.h"
Service::Service(const std::string& filename) : repo(filename) {
    for (int i = 0; i < 3; i++) {
        bani[i] = 0;
    }
}

void Service::addProduct(int cod, const char* name, int price) {
    Validator::validateProduct(cod, name, price);
    Entity e(cod, const_cast<char*>(name), price);
    repo.addElement(e);
}

void Service::deleteProduct(int cod) {
    repo.deleteElement(cod);
}

void Service::updateProduct(int cod, const char* newName, int newPrice) {
    Validator::validateProduct(cod,newName, newPrice);

    bool found = false;
    for (int i = 0; i < repo.getSize(); i++) {
        if (repo.getElement(i).getCod() == cod) {
            Entity updated = repo.getElement(i);
            updated.setName(newName);
            updated.setPrice(newPrice);
            repo.updateElement(cod, updated);
            found = true;
            break;
        }
    }

    if (!found) {
        throw MyException("Produsul cu codul dat nu exista.");
    }
}

Entity* Service::getAll() {
    return repo.getAll();
}

int Service::getSize() {
    return repo.getSize();
}

void Service::addBani(int valIndex, int count) {
    if (valIndex >= 0 && valIndex < 3) {
        bani[valIndex] += count;
    }
}

bool Service::buyProduct(int cod, int moneyInserted, int& changeDue, int changeBani[3]) {
    Entity* product = nullptr;
    for (int i = 0; i < repo.getSize(); i++) {
        if (repo.getElement(i).getCod() == cod) {
            product = &repo.getElement(i);
            break;
        }
    }

    if (!product || moneyInserted < product->getPrice()) {
        return false;
    }

    changeDue = moneyInserted - product->getPrice();

    if (changeDue == 0) {
        return true;
    }

    const int coinValues[3] = {10, 5, 1};
    int tempBani[3];
    memcpy(tempBani, bani, sizeof(bani));

    int remaining = changeDue;
    memset(changeBani, 0, sizeof(int) * 3);

    for (int i = 0; i < 3; i++) {
        while (remaining >= coinValues[i] && tempBani[i] > 0) {
            remaining -= coinValues[i];
            tempBani[i]--;
            changeBani[i]++;
        }
    }

    if (remaining == 0) {
        memcpy(bani, tempBani, sizeof(bani));
        return true;
    }

    return false;
}