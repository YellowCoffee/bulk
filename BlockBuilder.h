#ifndef BLOCKBUILDER_H
#define BLOCKBUILDER_H

#include "Block.h"
#include "BlockWriter.h"

class BlockBuilder
{
public:
    BlockBuilder();

    void insertCommand(const Command& command);
    Block getBlock();
    void subscribe(BlockWriter* blockWriter);

private:
    int m_commandSize = 3;
    int m_commandCount = 0;
    std::vector<Command> m_commands;
    std::vector<BlockWriter*> m_blockWriters;
};

#endif // BLOCKBUILDER_H
