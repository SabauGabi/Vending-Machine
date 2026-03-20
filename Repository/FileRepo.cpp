#include "FileRepo.h"
#include <fstream>
#include <sstream>

FileRepo::FileRepo(const std::string& filename) : filename(filename) {
    loadFromFile();
}

Entity * FileRepo::getAll() {
    return Repo::getAll();
}

int FileRepo::getSize() const {
    return Repo::getSize();
}

void FileRepo::loadFromFile() {
    std::ifstream in(filename);
    if (!in.is_open()) return;

    int cod, price;
    std::string name;

    while (in >> cod >> price) {
        std::getline(in >> std::ws, name);
        Entity e(cod, const_cast<char*>(name.c_str()), price);
        Repo::addElement(e);
    }

    in.close();
}

void FileRepo::saveToFile() {
    std::ofstream out(filename);
    Entity* entities = Repo::getAll();
    int size = Repo::getSize();

    for (int i = 0; i < size; i++) {
        out << entities[i].getCod() << " " 
            << entities[i].getPrice() << " "
            << entities[i].getName() << "\n";
    }
    out.close();
}

void FileRepo::addElement(const Entity& e) {
    Repo::addElement(e);
    saveToFile();
}

bool FileRepo::deleteElement(int cod) {
    bool result = Repo::deleteElement(cod);
    if (result) saveToFile();
    return result;
}

bool FileRepo::updateElement(int cod, const Entity& newEntity) {
    bool result = Repo::updateElement(cod, newEntity);
    if (result) saveToFile();
    return result;
}