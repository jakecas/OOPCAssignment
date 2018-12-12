//
// Created by Jake on 05/12/2018.
//

#ifndef OOPCASSIGNMENT_BINSTREE_H
#define OOPCASSIGNMENT_BINSTREE_H

#include <exception>

#define PREORDER -1
#define INORDER 0
#define POSTORDER 1


struct DuplicateObjectException : public std::exception {
    const char *message () const throw () {
        return "The new object is already in the tree.";
    }
};

struct InvalidTraversalOrderException : public std::exception {
    const char *message () const throw() {
        return "Invalid traversal order, please use one of the predefined constants: PREORDER, INORDER, POSTORDER";
    }
};

template <class T> class Node{
public:
    Node(){
        this->right = nullptr;
        this->left = nullptr;
        this->curr = nullptr;
    }
    ~Node(){
        delete this->left;
        delete this->right;
        delete this->curr;
    }

    void insert(T obj){
        if (this->curr == nullptr){
            this->curr = obj;
            std::cout << "Inserted here" << std::endl;
        } else if (*obj < *this->curr){
            if(this->left == nullptr) {
                this->left = new Node<T>();
            }
            this->left->insert(obj);
            std::cout << "Inserted left" << std::endl;
        } else if (*obj > *this->curr){
            if(this->right == nullptr) {
                this->right = new Node<T>();
            }
            this->right->insert(obj);
            std::cout << "Inserted right" << std::endl;
        } else if (*obj == *this->curr){
            throw new DuplicateObjectException();
        }
    }
    void remove(){

    }
    void find(T){}
    void print(int order){
        if (order == PREORDER){
            this->preorder();
        } else if (order == INORDER){
            this->inorder();
        } else if (order == POSTORDER){
            this->postorder();
        } else {
            throw new InvalidTraversalOrderException;
        }
    }

private:
    void preorder(){
        if(this->curr != nullptr){
            std::cout << *curr << std::endl;
        }

        if (this->left != nullptr){
            this->left->preorder();
        }

        if (this->right != nullptr){
            this->right->preorder();
        }
    }

    void inorder() {
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

    void postorder(){
        if (this->left != nullptr){
            this->left->postorder();
        }

        if (this->right != nullptr){
            this->right->postorder();
        }

        if(this->curr != nullptr){
            std::cout << *curr << std::endl;
        }
    }

    Node<T> *right;
    Node<T> *left;
    T curr;
};


//template <class T>
//void Node<T>::print(int order) {
//    if (order == PREORDER){
////        this->preorder();
//    } else if (order == INORDER){
//        this->inorder();
//    } else if (order == POSTORDER){
////        this->postorder();
//    } else {
//        throw "Invalid traversal order, please use one of the predefined constants: PREORDER, INORDER, POSTORDER";
//    }
//}

//template <class T>
//void Node<T>::inorder() {
//    if (this->left != nullptr){
//        this->left->inorder();
//    }
//
//    if(this->curr != nullptr){
//        std::cout << this->curr << std::endl;
//    }
//
//    if (this->right != nullptr){
//        this->right->inorder();
//    }
//}


#endif //OOPCASSIGNMENT_BINSTREE_H
