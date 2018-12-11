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
    Node(){
        this->right = nullptr;
        this->left = nullptr;
        this->curr = nullptr;
    }


    void insert(T obj){
        if (this->curr == nullptr){
            std::cout << "here" << std::endl;
            this->curr = obj;
        } else if (*obj < *this->curr){
            std::cout << "left" << std::endl;
            this->left = new Node<T>();
            this->left->insert(obj);
        } else if (*obj > *this->curr){
            std::cout << "right" << std::endl;
            this->right = new Node<T>();
            this->right->insert(obj);
        } else if (*obj == *this->curr){
            std::cout << "The new object is already in the tree." << std::endl;
        }
    }
    void remove(){}
    void find(T){}
    void print(int order){}

private:
    Node<T> *right;
    Node<T> *left;
    T curr;
};


#endif //OOPCASSIGNMENT_BINSTREE_H
