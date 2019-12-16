#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

#include "BlockBuilder.h"
#include "FileWriter.h"
#include "ConsoleWriter.h"

#include <algorithm>
#include <iterator>

int main(int argc, char *argv[])
{
    /*
    BlockBuilder blockBuilder;
    if (argc == 2) {
        std::stringstream convert(argv[1]);
        int i;
        if ( (convert >> i) ) {
            std::cout << argv[1] << std::endl;
            blockBuilder = BlockBuilder(i);
        }
    }

    FileWriter fileWriter;
    blockBuilder.subscribe( &fileWriter );

    ConsoleWriter consoleWriter;
    blockBuilder.subscribe( &consoleWriter);

    std::ifstream is("D:/Qt/build-bulk-Desktop_Qt_5_8_0_MinGW_32bit-Default/test2.txt");
    string line;
    while ( getline(is, line) ) {
        blockBuilder.insertCommand( line );
    }
    */

    std::ifstream is("D:/Qt/build-bulk-Desktop_Qt_5_8_0_MinGW_32bit-Default/test2.txt");
    std::copy(std::istream_iterator<char>(is), istream_iterator<char>(),
              std::ostream_iterator<char>(std::cout, " "));

    return 0;
}
