#include <iostream>
#include "binstree.h"
#include "animal.h"

using namespace std;



int main() {
//     GOOD
//    int *p = new int(5);
//    Node<int*> *root = new Node<int*>();
//    root->insert(p);
//
//    int *q = new int(6);
//    root->insert(q);
//
//    int *r = new int(3);
//    root->insert(r);
//
//    root->print(INORDER);
//    delete root;


    //Testing Animals

    Animal *cat = new Mammal("cat", 50, 2);
    Animal *dog = new Mammal("dog", 60, 1);
    Animal *snek = new Reptile("snek", 40, true);
    Animal *bird = new Bird("bird", 10, true);
//
//    bool test = *cat==*dog;
//    bool test2 = *snek==*dog;
//    cout << test << endl;
//    cout << test2 << endl;

    Node<Animal*> *animes = new Node<Animal*>();
    animes->insert(cat);
    animes->insert(dog);
    animes->insert(snek);
    animes->insert(bird);
    animes->print(INORDER);
    animes->print(PREORDER);
    animes->print(POSTORDER);

    cout << *animes->find(new Bird("bird", 0, false)) << endl;
    animes->remove(new Bird("bird", 0, false));
    cout << *animes->find(new Bird("bird", 0, false)) << endl;

    delete animes;
//    delete bird;
    return 0;
}