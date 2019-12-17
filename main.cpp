#include <iostream>
#include <sstream>

#include "BlockBuilder.h"
#include "FileWriter.h"
#include "ConsoleWriter.h"

using namespace std;

#include <fstream>

int main(int argc, char *argv[])
{
    BlockBuilder blockBuilder;
    if (argc == 2) {
        int i;
        try {
            i = std::stoi( argv[1] );
            blockBuilder = BlockBuilder(i);
        } catch (...) {

        }
    }

    FileWriter fileWriter;
    blockBuilder.subscribe( &fileWriter );

    ConsoleWriter consoleWriter;
    blockBuilder.subscribe( &consoleWriter);

    std::ifstream is("D:/Qt/build-bulk-Desktop_Qt_5_8_0_MinGW_32bit-Default/test2.txt");

    string line;
    while ( getline(/*std::cin*/ is, line) ) {
        blockBuilder.insertCommand( line );
    }
    blockBuilder.insertCommand( Command::CommandType::Eof );

    return 0;
}
