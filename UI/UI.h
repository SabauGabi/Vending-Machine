#ifndef UI_H
#define UI_H

#include "Service/Service.h"

class UI {
private:
    Service service;
public:
    UI();
    void menu();
    void run();
};

#endif