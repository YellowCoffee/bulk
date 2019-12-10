#include <iostream>

using namespace std;

#include "BlockBuilder.h"
#include "FileWriter.h"
#include "ConsoleWriter.h"

int main()
{
    BlockBuilder blockBuilder;

    FileWriter fileWriter;
    blockBuilder.subscribe( &fileWriter );

    ConsoleWriter consoleWriter;
    blockBuilder.subscribe( &consoleWriter);

    string line;
    while ( getline(cin, line) ) {
        blockBuilder.insertCommand( line );
    }

    cout << "Hello World!" << endl;
    return 0;
}
