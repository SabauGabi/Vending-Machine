//
// Created by Gabi on 5/25/2025.
//

#ifndef VALIDATOR_H
#define VALIDATOR_H
#include <cstring>
#include "MyException.h"

class Validator {
public:
    static void validateProduct(int cod,const char* name, int price) {
        if (cod <= 0)
            throw MyException("Codul produsului trebuie sa fie pozitiv.");
        if (name == nullptr || strlen(name) == 0)
            throw MyException("Numele produsului nu poate fi gol.");
        if (price <= 0)
            throw MyException("Pretul trebuie sa fie pozitiv.");
    }
};
#endif //VALIDATOR_H
