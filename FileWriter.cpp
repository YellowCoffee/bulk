#include "FileWriter.h"

#include <algorithm>
#include <fstream>

FileWriter::FileWriter()
    : BlockWriter()
{

}

void FileWriter::write(const Block &block)
{
    auto timeStamp = static_cast<int>( block.begin()->timeStamp() );
    char fileName[50];
    std::sprintf( fileName, "bulk%i.log", timeStamp );
    std::ofstream out(fileName);
    std::for_each( block.begin(), block.end(), [&out](const auto& command){
        out << command << "\n";
    });
}
