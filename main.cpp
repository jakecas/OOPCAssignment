#include <iostream>
#include "binstree.h"
#include "animal.h"
#include "commands.h"

using namespace std;

void lineRunner(vector<string> line, Node<Animal*> *root);
Animal* constructAnimal(vector<string> line, Node<Animal*> *root);
bool venomousToBool(string venomous);
bool canflyToBool(string canfly);
void printAll(vector<string> line, Node<Animal*> *root);

int main() {
    vector<string> lines = lineReader(DEFAULT_TEST_FILE);

    unsigned int lineNum = 0;
    Node<Animal*> *root = new Node<Animal*>();

    while(lineNum < lines.size()){
        try {
            lineRunner(lineTokenizer(lines[lineNum++]), root);
        } catch(MalformedCommandException* e) {
            cout << e->message() << endl;
        }
    }
    return 0;
}

void lineRunner(vector<string> line, Node<Animal*> *root){
    if(line.size() == 0) {
        return;
    }

    if(line[0].compare("Insert") == 0){
        root->insert(constructAnimal(line, root));
    } else if(line[0].compare("Find") == 0){
        cout << root->find(new Animal(line[1])) << endl;
    } else if(line[0].compare("Remove") == 0){
        root->remove(new Animal(line[1]));
    } else if(line[0].compare("Print") == 0){
        printAll(line, root);
    } else {
        throw new MalformedCommandException("Command '" + line[0] + "' does not exist.");
    }
}

Animal* constructAnimal(vector<string> line, Node<Animal*> *root){
    if(line.size() != 5){
        throw new MalformedCommandException("Incorrect number of arguments to construct animal: " + to_string(line.size()));
    }

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

void printAll(vector<string> line, Node<Animal*> *root){
    if(line.size() >= 2) {
        if(line[1].compare("PREORDER") == 0){
            root->print(POSTORDER);
        } else if(line[1].compare("INORDER") == 0){
            root->print(INORDER);
        } else if(line[1].compare("POSTORDER") == 0){
            root->print(PREORDER);
        }
    } else {
        root->print(INORDER);
    }
}