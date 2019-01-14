//
// Created by Jake on 05/12/2018.
//

#ifndef OOPCASSIGNMENT_BINSTREE_H
#define OOPCASSIGNMENT_BINSTREE_H

#include <exception>

#define PREORDER -1
#define INORDER 0
#define POSTORDER 1

// Thrown when an object that is already in the tree is inserted into the tree.
struct DuplicateObjectException : public std::exception {
    const char *message () const throw () {
        return "The new object is already in the tree.";
    }
};
// Thrown when print() is called with an undefined traversal order.
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
            // Deleting a leaf.
            toDelete->curr = nullptr;
            return true;
        } else if (toDelete->left != nullptr && toDelete->right == nullptr){
            // Shifting left subtree into the toDelete element.
            Node<T> *tempLeft = toDelete->left;
            toDelete->curr = tempLeft->curr;
            toDelete->left = tempLeft->left;
            toDelete->right = tempLeft->right;
            return true;
        } else if (toDelete->left == nullptr && toDelete->right != nullptr){
            // Shifting right subtree into the toDelete element.
            Node<T> *tempRight = toDelete->right;
            toDelete->curr = tempRight->curr;
            toDelete->left = tempRight->left;
            toDelete->right = tempRight->right;
            return true;
        } else {
            //Find inorder successor and move it instead of this.
            Node<T> *successor = toDelete->right->findSmallest();
            toDelete->curr = successor->curr;
            if(successor->right == nullptr) {
                // Successor had no right subtree, it can safely be deleted.
                successor->curr = nullptr;
            } else {
                // Successor had a right subtree, which must be shifted up to take its place.
                Node<T> *tempRight = successor->right;
                successor->curr = tempRight->curr;
                successor->left = tempRight->left;
                successor->right = tempRight->right;
            }
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
    // Finds and returns the node containing the object being searched for. Used in find() and remove().
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

    // Finds the left-most leaf of the tree.
    // Used to find inorder successor when removing an object with two subtrees.
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
            std::cout << *this->curr << std::endl;
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
            std::cout << *this->curr << std::endl;
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
