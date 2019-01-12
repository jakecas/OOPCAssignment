#include "commandutils.h"

void lineRunner(vector<string> line, Node<Animal*> *root){
    if(line.size() == 0) {
        return;
    }

    if(line[0].compare("Insert") == 0){
        insertAnimal(line, root);
    } else if(line[0].compare("Find") == 0){
        findAnimal(line, root);
    } else if(line[0].compare("Remove") == 0){
        removeAnimal(line, root);
    } else if(line[0].compare("Print") == 0){
        printAll(line, root);
    } else {
        throw new MalformedCommandException("Command '" + line[0] + "' does not exist.");
    }
}

void insertAnimal(vector<string> line, Node<Animal*> *root){
    try {
        root->insert(constructAnimal(line, root));
    } catch(DuplicateObjectException* e){
        cout << "Insertion Error: " << e->message() << endl;
        return;
    }
}

void findAnimal(vector<string> line, Node<Animal*> *root){
    checkArgumentNumber(line.size(), 2, "find");

    Animal* found = root->find(new Mammal(line[1], 0.0, 0));
    if(found == nullptr){
        cout << "Animal '" << line[1] << "' not found in tree." << endl;
    } else {
        cout << *found << endl;
    }
}

void removeAnimal(vector<string> line, Node<Animal*> *root){
    checkArgumentNumber(line.size(), 2, "remove");

    if(root->remove(new Mammal(line[1], 0.0, 0))){
        cout << "Animal '" << line[1] << "' deleted." << endl;
    } else {
        cout << "Animal '" << line[1] << "' not found in tree." << endl;
    }
}

void printAll(vector<string> line, Node<Animal*> *root){
    if(line.size() == 2) {
        if(line[1].compare("PREORDER") == 0){
            root->print(POSTORDER);
        } else if(line[1].compare("INORDER") == 0){
            root->print(INORDER);
        } else if(line[1].compare("POSTORDER") == 0){
            root->print(PREORDER);
        }
        return;
    } else if (line.size() == 1){
        root->print(INORDER);
        return;
    }

    throw new ArgumentNumberException("Incorrect number of arguments to print tree: ", line.size());
}

Animal* constructAnimal(vector<string> line, Node<Animal*> *root){
    checkArgumentNumber(line.size(), 5, "construct");

    Animal* animal;
    try {
        if (line[1].compare("Mammal") == 0 || line[1].compare("mammal") == 0) {
            animal = new Mammal(line[2], stod(line[3]), stoi(line[4]));
        } else if (line[1].compare("Reptile") == 0 || line[1].compare("reptile") == 0) {
            animal = new Reptile(line[2], stod(line[3]), venomousToBool(line[4]));
        } else if (line[1].compare("Bird") == 0 || line[1].compare("bird") == 0) {
            animal = new Bird(line[2], stod(line[3]), canflyToBool(line[4]));
        } else {
            throw new MalformedCommandException("Invalid animal type '" + line[1] + "'.");
        }
    } catch(invalid_argument ia){
        if(string(ia.what()).compare("stod") == 0){
            throw new MalformedCommandException("Invalid length '" + line[3] + "', needs to be a double.");
        } else if(string(ia.what()).compare("stoi") == 0){
            throw new MalformedCommandException("Invalid litter size '" + line[4] + "', needs to be an int.");
        } else {
            throw new MalformedCommandException("Invalid_argument thrown, unknown reason: " + string(ia.what()));
        }
    }
    return animal;
}

bool venomousToBool(string venomous){
    if(venomous.compare("venomous") == 0) {
        return true;
    } else if(venomous.compare("non-venomous") == 0){
        return false;
    } else{
        throw new MalformedCommandException("Invalid venomous declaration for reptile '" + venomous + "'.");
    }
}

bool canflyToBool(string canfly){
    if(canfly.compare("can-fly") == 0) {
        return true;
    } else if(canfly.compare("cannot-fly") == 0){
        return false;
    } else{
        throw new MalformedCommandException("Invalid can-fly declaration for bird '" + canfly + "'.");
    }
}

void checkArgumentNumber(int actual, int expected, string action){
    if(actual != expected){
        throw new ArgumentNumberException("Incorrect number of arguments to " + action + " animal: ", actual);
    }
}
