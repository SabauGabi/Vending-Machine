//
// Created by Gabi on 4/29/2025.
//

#ifndef ENTITY_H
#define ENTITY_H



class Entity {
private:
    int cod;
    char* name;
    int price;
public:
    Entity();
    Entity(int cod, char* name,int price);
    Entity(Entity& entity);
    Entity& operator=(const Entity& other);
    ~Entity();
    int getCod() const;
    void setCod(int cod);
    int getPrice() const;
    void setPrice(int price);
    const char* getName() const;
    void setName(const char* name);

};



#endif //ENTITY_H
