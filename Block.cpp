#include "Block.h"

Block::Block(const std::vector<Command> &commandVector)
    : m_commandVector(commandVector)
{

}

std::vector<Command> Block::commandVector() const
{
    return m_commandVector;
}
