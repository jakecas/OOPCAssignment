//
// Created by Jake on 05/12/2018.
//

#ifndef OOPCASSIGNMENT_BINSTREE_H
#define OOPCASSIGNMENT_BINSTREE_H

#define PREORDER -1
#define INORDER 0
#define POSTORDER 1


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
    void print(int order);

private:
    void preorder();
    void inorder();
    void postorder();

    Node<T> *right;
    Node<T> *left;
    T curr;
};


template <class T>
void Node<T>::print(int order) {
    if (order == PREORDER){
//        this->preorder();
    } else if (order == INORDER){
        this->inorder();
    } else if (order == POSTORDER){
//        this->postorder();
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
        std::cout << this->curr << std::endl;
    }

    if (this->right != nullptr){
        this->right->inorder();
    }
}


#endif //OOPCASSIGNMENT_BINSTREE_H
