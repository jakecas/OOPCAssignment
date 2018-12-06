//
// Created by Jake on 05/12/2018.
//

#ifndef OOPCASSIGNMENT_BINSTREE_H
#define OOPCASSIGNMENT_BINSTREE_H

#define INORDER 0
#define POSTORDER 1
#define PREORDER 1


template <class T> class Node{
public:
    Node<T> *right;
    Node<T> *left;
    T curr;

    Node(T root){
        this->right = nullptr;
        this->left = nullptr;
        this->curr = root;
    }


    void insert(T obj){
        if (this->curr == obj){
            std::cout << "The new object is already in the tree." << std::endl;
        } else if (*obj < *this->curr){
            std::cout << "left" << std::endl;
            this->left = new Node<T>(obj);
        } else if (*obj > *this->curr){
            std::cout << "right" << std::endl;
            this->right = new Node<T>(obj);
            std::cout << this->right->curr << std::endl;
        }
    }
    void remove(){}
    void find(T){}
    void print(int order){}
};


#endif //OOPCASSIGNMENT_BINSTREE_H
