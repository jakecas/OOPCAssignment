#include <iostream>
#include "binstree.h"


int main() {
    int p = 5;
    int *temp = &p;
    Node<int*> *root = new Node<int*>();
    root->insert(temp);
    p = 6;
    temp = &p;
    root->insert(temp);

    p = 3;
    temp = &p;
    root->insert(temp);


    std::cout << *root->curr << std::endl;

    Node<int*> *tl = root->left;
    std::cout << "before" << std::endl;
    std::cout << tl->curr << std::endl;
    std::cout << "after" << std::endl;

    Node<int*> *tr = root->right;
    std::cout << tr->curr << std::endl;
    return 0;
}