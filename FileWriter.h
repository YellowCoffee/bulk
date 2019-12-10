#ifndef FILEWRITER_H
#define FILEWRITER_H

#include "BlockWriter.h"

class FileWriter : public BlockWriter
{
public:
    FileWriter();
    void write(const Block &block) override;
};

#endif // FILEWRITER_H
