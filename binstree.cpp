#include "binstree.h"

template <class T>
void Node<T>::print(int order) {
    if (order == PREORDER){
        this->preorder();
    } else if (order == INORDER){
        this->inorder();
    } else if (order == POSTORDER){
        this->postorder();
    } else {
        throw "Invalid traversal order, please use one of the predefined constants: PREORDER, INORDER, POSTORDER";
    }
}

template <class T>
void Node<T>::inorder() {
    if (this->left != nullptr){
        this->left->inorder();
    }

    if(this->curr != nullptr){
        std::cout << *curr << std::endl;
    }

    if (this->right != nullptr){
        this->right->inorder();
    }
}

