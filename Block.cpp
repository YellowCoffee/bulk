#include "Block.h"

Block::Block(const std::vector<Command> &commandVector)
    : m_commandVector(commandVector)
{

}

std::vector<Command>::const_iterator Block::begin() const
{
    return m_commandVector.cbegin();
}

std::vector<Command>::const_iterator Block::end() const
{
    return m_commandVector.cend();
}

std::time_t Block::timeStamp() const
{
    return m_commandVector.front().timeStamp();
}