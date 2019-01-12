#include <iostream>

#include "binstree.h"
#include "animal.h"
#include "lineutils.h"
#include "commandutils.h"

using namespace std;

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
    return 0;
}
