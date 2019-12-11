#include "BlockBuilder.h"

BlockBuilder::BlockBuilder()
{
    m_terminator = RegularTerminator(this);
}

void BlockBuilder::insertCommand(const Command &command)
{
    if ( m_terminator->checkFinish(command) ) {
        Block block( m_commands );
        for(const auto& blockWriter : m_blockWriters) {
            blockWriter->write(block);
        }
        m_commandCount = 0;
        m_commands.clear();
    } else {
        m_commands.push_back( command );
    }
}

void BlockBuilder::subscribe(BlockWriter *blockWriter)
{
    m_blockWriters.push_back( blockWriter );
}

bool BlockBuilder::needFinish(const Command &command)
{
    ++m_commandCount;
    if (m_commandCount == m_commandSize) {
        return true;
    }
    return false;
}