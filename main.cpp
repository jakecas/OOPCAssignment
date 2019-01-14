#include <iostream>

#include "objects/binstree.h"
#include "objects/animal.h"
#include "utilities/lineutils.h"
#include "utilities/commandutils.h"

using namespace std;

void finalPrint(Node<Animal*> *root);

int main(int argc, char **argv) {
    // Set to the text file passed as a command line argument if one was specified, and the default test file if not.
    string file = (argc == 2) ? argv[1] : DEFAULT_TEST_FILE;
    // A vector of the lines in the file
    vector<string> lines = lineReader(file);

    unsigned int lineNum = 0;

    // The root node of the binary search tree
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
    delete root;
    return 0;
}

// Prints an INORDER traversal of the list, called at the end of the program.
void finalPrint(Node<Animal*> *root){
    cout << "\nFinal contents of binary search tree of animals (INORDER):" << endl;
    printAll(lineTokenizer("PRINT INORDER"), root);
}
