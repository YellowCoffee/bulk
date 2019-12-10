#ifndef BLOCK_H
#define BLOCK_H

#include <vector>
#include <string>

typedef std::string Command;

class Block
{
public:
    Block( const std::vector<Command>& commandVector );
    std::vector<Command> commandVector() const;

private:
    std::vector<Command> m_commandVector;
};

#endif // BLOCK_H
