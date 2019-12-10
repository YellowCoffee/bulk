#include "BlockBuilder.h"

BlockBuilder::BlockBuilder()
{

}

void BlockBuilder::insertCommand(const Command &command)
{
    m_commands.push_back( command );
    ++m_commandCount;

    if (m_commandCount == m_commandSize) {
        Block block( m_commands );
        for(const auto& blockWriter : m_blockWriters) {
            blockWriter->write(block);
        }
        m_commandCount = 0;
        m_commands.clear();
    }

}

void BlockBuilder::subscribe(BlockWriter *blockWriter)
{
    m_blockWriters.push_back( blockWriter );
}
