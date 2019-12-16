#include "ConsoleWriter.h"

#include <iostream>
#include <iterator>

using namespace std;

ConsoleWriter::ConsoleWriter()
    : BlockWriter()
{

}

void ConsoleWriter::write(const Block &block)
{
    cout << "bulk: ";
    auto it = block.begin();
    cout << *it++;
    while (it != block.end()) {
        cout << ", " << *it++;
    }
    cout << endl;
}
