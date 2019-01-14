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
        this->left = nullptr;
        this->right = nullptr;
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
        } else if (*obj < *this->curr){
            if(this->left == nullptr) {
                this->left = new Node<T>();
            }
            this->left->insert(obj);
        } else if (*obj > *this->curr){
            if(this->right == nullptr) {
                this->right = new Node<T>();
            }
            this->right->insert(obj);
        } else if (*obj == *this->curr){
            throw new DuplicateObjectException();
        }

    }


    // Find takes an object of type T and traverses the list to find it.
    // obj does not need to be fully fleshed out,
    // the only thing it needs to contain is the attribute that is used to compare.
    T find(T obj){
        Node<T>* temp = findNode(obj);

        return (temp == nullptr) ? nullptr : temp->curr;
    }

    bool remove(T obj){
        Node<T> *toDelete = findNode(obj);

        if(toDelete == nullptr) {
            return false;
        } else if(toDelete->left == nullptr && toDelete->right == nullptr) {
            // This is incorrect.
            toDelete->curr = nullptr;
            return true;
        } else if (toDelete->left != nullptr && toDelete->right == nullptr){
            Node<T> *tempLeft = toDelete->left;
            *toDelete->curr = *tempLeft->curr;
            toDelete->left = tempLeft->left;
            toDelete->right = tempLeft->right;
            return true;
        } else if (toDelete->left == nullptr && toDelete->right != nullptr){
            Node<T> *tempRight = toDelete->right;
            *toDelete->curr = *tempRight->curr;
            toDelete->left = tempRight->left;
            toDelete->right = tempRight->right;
            return true;
        } else {
            Node<T> *successor = toDelete->right->findSmallest();
            *toDelete->curr = *successor->curr;
            successor->curr = nullptr;
            return true;
        }
    }


    void print(int order){
        switch(order){
            case PREORDER:
                this->preorder();
                break;
            case INORDER:
                this->inorder();
                break;
            case POSTORDER:
                this->postorder();
                break;
            default:
                throw new InvalidTraversalOrderException;
        }
    }

private:
    Node<T>* findNode(T obj){
        if(this->curr == nullptr && this->left == nullptr && this->right == nullptr){
            return nullptr;
        } else if(*obj == *this->curr){
            return this;
        } else if(*obj < *this->curr && this->left != nullptr){
            return this->left->findNode(obj);
        } else if(*obj > *this->curr && this->right != nullptr){
            return this->right->findNode(obj);
        } else {
            return nullptr;
        }
    }

    Node<T>* findSmallest(){
        if(this->left != nullptr){
            if(this->left->curr != nullptr){
                return this->left->findSmallest();
            }
        }

        return this;
    }

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

    Node<T> *left;
    Node<T> *right;
    T curr;
};


#endif //OOPCASSIGNMENT_BINSTREE_H
