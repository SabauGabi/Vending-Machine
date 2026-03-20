#ifndef FILE_REPO_H
#define FILE_REPO_H

#include "Repo.h"
#include <string>

class FileRepo : public Repo {
private:
    std::string filename;
    void loadFromFile();
    void saveToFile();

public:
    FileRepo(const std::string& filename);
    Entity* getAll();
    int getSize() const;
    void addElement(const Entity& e);
    bool deleteElement(int cod);
    bool updateElement(int cod, const Entity& newEntity);
};

#endif