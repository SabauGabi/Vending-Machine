#include "UI.h"
#include <iostream>
#include <cstring>
#include "../MyException.h"
using namespace std;

UI::UI() : service(Service("shop.txt")) {}

void UI::menu() {
    cout << "1. Adaugare produs\n";
    cout << "2. Stergere produs\n";
    cout << "3. Modificare produs\n";
    cout << "4. Afisare produse\n";
    cout << "5. Adaugare monede (1/5/10 lei)\n";
    cout << "6. Cumpara produs\n";
    cout << "0. Exit\n";
}

void UI::run() {
    bool running = true;
    while (running) {
        menu();
        int cmd;
        cout << "Comanda: ";
        cin >> cmd;

        try {
            if (cmd == 1) {
                int cod, pret;
                char nume[50];
                cout << "Cod: "; cin >> cod;
                cin.ignore();
                cout << "Nume: ";
                cin.getline(nume, 50);
                cout << "Pret: "; cin >> pret;
                service.addProduct(cod, nume, pret);
            } else if (cmd == 2) {
                int cod;
                cout << "Cod de sters: ";
                cin >> cod;
                service.deleteProduct(cod);
            } else if (cmd == 3) {
                int cod, pret;
                char nume[50];
                cout << "Cod: "; cin >> cod;
                cin.ignore();
                cout << "Nume nou: ";
                cin.getline(nume, 50);
                cout << "Pret nou: "; cin >> pret;
                service.updateProduct(cod, nume, pret);
            } else if (cmd == 4) {
                Entity* products = service.getAll();
                int size = service.getSize();
                if (size == 0) {
                    cout << "Nu exista produse in magazin.\n";
                } else {
                    cout << "\nLista produse:\n";
                    for (int i = 0; i < size; i++) {
                        cout << products[i].getCod() << " | "
                             << products[i].getName() << " | "
                             << products[i].getPrice() << " lei\n";
                    }
                }
            } else if (cmd == 5) {
                cout << "Moneda (1 = 10 lei, 2 = 5 lei, 3 = 1 leu): ";
                int valIndex, count;
                cin >> valIndex;
                cout << "Numar bucati: ";
                cin >> count;
                service.addBani(valIndex - 1, count);
            } else if (cmd == 6) {
                int cod, suma;
                cout << "Cod produs: ";
                cin >> cod;
                cout << "Suma introdusa (lei): ";
                cin >> suma;
                int rest, monede[3];
                if (service.buyProduct(cod, suma, rest, monede)) {
                    cout << "Achizitie reusita. Rest: " << rest << " lei\n";
                    if (rest > 0) {
                        cout << "Monede rest: ";
                        if (monede[0]) cout << monede[0] << " x 10 lei ";
                        if (monede[1]) cout << monede[1] << " x 5 lei ";
                        if (monede[2]) cout << monede[2] << " x 1 leu ";
                        cout << "\n";
                    }
                } else {
                    cout << "Nu se poate oferi rest sau produsul nu exista.\n";
                }
            } else if (cmd == 0) {
                running = false;
            } else {
                cout << "Comanda invalida!\n";
            }
        } catch (const MyException& ex) {
            cout << "Eroare: " << ex.what() << "\n";
        }
    }
}

















