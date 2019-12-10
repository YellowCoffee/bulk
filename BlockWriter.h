#ifndef BLOCKWRITER_H
#define BLOCKWRITER_H

#include "Block.h"

class BlockWriter
{
public:
    BlockWriter();

    virtual void write(const Block& block) = 0;
};

#endif // BLOCKWRITER_H
