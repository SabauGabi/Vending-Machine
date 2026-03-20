//
// Created by Gabi on 4/29/2025.
//

#include "tests.h"

#include <cassert>
#include <iostream>
#include <string.h>
#include "Repository/FileRepo.h"
#include "Entity/Entity.h"
#include "Repository/Repo.h"
#include "Service/Service.h"

void test_entity() {
    Entity e1;
    assert(e1.getCod()==0);
    assert(e1.getPrice()==0);
    assert(e1.getName() == nullptr || strcmp(e1.getName(), "") == 0);
    Entity e2(1,"suc",5);
    assert(e2.getCod()==1);
    assert(e2.getPrice()==5);
    assert(strcmp(e2.getName(),"suc")==0);

}

void test_repo() {
    Repo r;
    assert(r.getSize() == 0);

    Entity e1(1, (char*)"cola", 7);
    Entity e2(2, (char*)"fanta", 8);

    r.addElement(e1);
    r.addElement(e2);

    assert(r.getSize() == 2);
    assert(strcmp(r.getElement(0).getName(), "cola") == 0);
    assert(r.getElement(1).getPrice() == 8);

}
void test_service() {
    Service s3;

    s3.addProduct(1, "Cola", 5);
    s3.addProduct(2, "Fanta", 6);
    std::cout << s3.getSize();
    assert(s3.getSize() == 2);

    Entity* products = s3.getAll();
    assert(strcmp(products[0].getName(), "Cola") == 0);
    assert(products[1].getPrice() == 6);

    s3.deleteProduct(1);
    assert(s3.getSize() == 1);
    assert(strcmp(products[0].getName(), "Fanta") == 0);

    s3.updateProduct(2, "Fanta Zero", 7);
    assert(strcmp(products[0].getName(), "Fanta Zero") == 0);
    assert(products[0].getPrice() == 7);

    s3.addBani(0, 2);
    s3.addBani(1, 3);
    s3.addBani(2, 4);

    int change;
    int changeCoins[3];
    assert(s3.buyProduct(2, 10, change, changeCoins) == true);
    assert(change == 3);
    assert(changeCoins[1] == 1);
    assert(changeCoins[2] == 2);
}
void test_buyProduct() {
    Service s;
    s.addProduct(1, "apa", 11);
    s.addProduct(2, "cola", 7);
    s.addBani(2, 5);

    int change, coins[3];

    assert(s.buyProduct(1, 11, change, coins) == true);
    assert(change == 0);

    assert(s.buyProduct(2, 10, change, coins) == true);
    assert(change == 3);
    assert(coins[2] == 3);

    assert(s.buyProduct(1, 10, change, coins) == false);
    assert(s.buyProduct(99, 20, change, coins) == false);

    s.addProduct(3, "suc", 8);
    assert(s.buyProduct(3, 10, change, coins) == false);

    s.addBani(1, 2);
    s.addBani(0, 1);
    assert(s.buyProduct(1, 20, change, coins) == true);
    assert(change == 9);
    assert(coins[1] == 1);
    assert(coins[2] == 4);
}



    void test_filerepo(){
        const char* testFilename = "test_shop.txt";
        std::remove(testFilename);

        FileRepo repo(testFilename);
        Entity p1(101, (char*)"Suc portocale", 7);
        repo.addElement(p1);

        assert(repo.getSize() == 1);
        Entity* list = repo.getAll();
        assert(list[0].getCod() == 101);
        assert(list[0].getPrice() == 7);
        assert(std::string(list[0].getName()) == "Suc portocale");

        FileRepo repo2(testFilename);
        assert(repo2.getSize() == 1);
        Entity* list2 = repo2.getAll();
        assert(list2[0].getCod() == 101);
        assert(list2[0].getPrice() == 7);
        assert(std::string(list2[0].getName()) == "Suc portocale");

        std::cout << "Test FileRepo passed.\n";

        std::remove(testFilename);
    }


void test_All() {
   // test_entity();
   //   test_repo();
   //   test_service();
   //  test_buyProduct();
   //   test_filerepo();
}
