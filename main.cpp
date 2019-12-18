#include <iostream>
#include <sstream>

#include "BlockBuilder.h"
#include "FileWriter.h"
#include "ConsoleWriter.h"

using namespace std;

int main(int argc, char *argv[])
{
    BlockBuilder blockBuilder;
    if (argc == 2) {
        int i;
        try {
            i = std::stoi( argv[1] );
            blockBuilder.setBlockSize(i);
        } catch (...) {

        }
    }

    auto fileWriter = std::make_shared<FileWriter>();
    blockBuilder.subscribe( fileWriter );

    auto consoleWriter = std::make_shared<ConsoleWriter>();
    blockBuilder.subscribe( consoleWriter );

    string line;
    while ( getline(std::cin, line) ) {
        blockBuilder.insertCommand( line );
    }
    blockBuilder.insertCommand( Command::CommandType::Eof );

    return 0;
}
