#include "BlockBuilder.h"

#include <iostream>

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
    if (command.commandType() == Command::CommandType::Line)
        m_commands.push_back( command );

    if ( m_terminator->checkFinish(command) ) {
        if (m_commands.empty())
            return;

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

void BlockBuilder::setTerminator(Terminator *terminator)
{
    m_terminator = terminator;
}

bool RegularTerminator::checkFinish(const Command &command)
{
    switch (command.commandType()) {
    case Command::CommandType::OpenBrace: {
        auto terminator = new DynamicTerminator(m_builder);
        m_builder->setTerminator( terminator );
        terminator->checkFinish(command);
        return true;
    }
    case Command::CommandType::Eof:
        return true;
    default:
        break;
    }

    if (++commandCount == commandSize) {
        commandCount = 0;
        return true;
    }
    return false;
}

bool DynamicTerminator::checkFinish(const Command &command)
{
    switch (command.commandType()) {
    case Command::CommandType::OpenBrace:
        ++m_counter;
        return false;
    case Command::CommandType::CloseBrace:
        --m_counter;
        if ( m_counter == 0 ) {
            auto terminator = new RegularTerminator(m_builder);
            m_builder->setTerminator( terminator );
            return true;
        }
    default:
        break;
    }
    return false;
}
