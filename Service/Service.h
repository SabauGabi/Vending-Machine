#ifndef SERVICE_H
#define SERVICE_H

#include "../Repository/FileRepo.h"

class Service {
private:
    FileRepo repo;
    int bani[3];

public:
    Service(const std::string& filename = "shop.txt");
    void addProduct(int cod, const char* name, int price);
    void deleteProduct(int cod);
    void updateProduct(int cod, const char* newName, int newPrice);
    Entity* getAll();
    int getSize();
    void addBani(int valIndex, int count);
    bool buyProduct(int cod, int moneyInserted, int& changeDue, int changeBani[3]);
};

#endif