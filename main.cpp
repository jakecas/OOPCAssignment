#include <iostream>
#include "binstree.h"
#include "animal.h"

using namespace std;



int main() {
//     GOOD
    int p = 5;
    int *temp = &p;
    Node<int*> *root = new Node<int*>();
    root->insert(temp);
    int q = 6;
    temp = &q;
    root->insert(temp);

    int r = 3;
    temp = &r;
    root->insert(temp);

    root->print(INORDER);
    delete root;


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
    delete animes;

    return 0;
}