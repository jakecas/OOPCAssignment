#include <iostream>

#include "objects/binstree.h"
#include "objects/animal.h"
#include "utilities/lineutils.h"
#include "utilities/commandutils.h"

using namespace std;

void finalPrint(Node<Animal*> *root);

int main(int argc, char **argv) {
    string file = (argc == 2) ? argv[1] : DEFAULT_TEST_FILE;
    vector<string> lines = lineReader(file);

    unsigned int lineNum = 0;
    Node<Animal*> *root = new Node<Animal*>();

    while(lineNum < lines.size()){
        try {
            cout << lines[lineNum] << endl;
            lineRunner(lineTokenizer(lines[lineNum++]), root);
        } catch(MalformedCommandException* e) {
            cout << e->message() << endl;
        }
    }

    finalPrint(root);
    return 0;
}

void finalPrint(Node<Animal*> *root){
    cout << "\nFinal contents of binary search tree of animals (INORDER):" << endl;
    printAll(lineTokenizer("PRINT INORDER"), root);
}
