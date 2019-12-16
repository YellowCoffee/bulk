#ifndef BLOCK_H
#define BLOCK_H

#include <vector>
#include <string>

#include "Command.h"

class Block
{
public:
    Block( const std::vector<Command>& commandVector );
    std::vector<Command>::const_iterator begin() const;
    std::vector<Command>::const_iterator end() const;

    time_t timeStamp() const;

private:
    std::vector<Command> m_commandVector;
};

#endif // BLOCK_H
