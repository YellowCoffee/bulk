#include "ConsoleWriter.h"

#include <iostream>

ConsoleWriter::ConsoleWriter()
    : BlockWriter()
{

}

void ConsoleWriter::write(const Block &block)
{
    std::cout << "bulk: ";
    for( const auto& command : block.commandVector() ) {
        std::cout << command << ", ";
    }
    std::cout << std::endl;
}
