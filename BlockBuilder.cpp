#include "BlockBuilder.h"

int RegularTerminator::commandSize = 3;

BlockBuilder::BlockBuilder()
{
    m_terminator = new RegularTerminator(this);
}

BlockBuilder::BlockBuilder(int blockSize)
    : BlockBuilder()
{
    RegularTerminator::setCommandSize( blockSize );
}

void BlockBuilder::insertCommand(const Command &command)
{
    m_commands.push_back( command );
    if ( m_terminator->checkFinish(command) ) {
        Block block( m_commands );
        for(const auto& blockWriter : m_blockWriters) {
            blockWriter->write(block);
        }
        m_commands.clear();
    }
}

void BlockBuilder::subscribe(BlockWriter *blockWriter)
{
    m_blockWriters.push_back( blockWriter );
}