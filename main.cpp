#include <iostream>
#include "binstree.h"


int main() {
    int p = 5;
    int *temp = &p;
    Node<int*> *root = new Node<int*>(temp);
    int q = 6;
    temp = &q;
    root->insert(temp);

    int r = 3;
    temp = &r;
    root->insert(temp);


    std::cout << *root->curr << std::endl;

    std::cout << "before" << std::endl;
    std::cout << *root->right->curr << std::endl;
    std::cout << "after" << std::endl;
    return 0;
}