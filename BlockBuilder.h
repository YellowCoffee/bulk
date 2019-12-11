#ifndef BLOCKBUILDER_H
#define BLOCKBUILDER_H

#include "Block.h"
#include "BlockWriter.h"

class Terminator;

class BlockBuilder
{
public:
    BlockBuilder();

    void insertCommand(const Command& command);
    Block getBlock();
    void subscribe(BlockWriter* blockWriter);

private:
    std::vector<Command> m_commands;
    std::vector<BlockWriter*> m_blockWriters;
    Terminator *m_terminator;

};

class Terminator {
public:
    Terminator (BlockBuilder* builder);
    virtual bool checkFinish(const Command& command) = 0;

protected:
    BlockBuilder* m_builder;
};

class RegularTerminator : public Terminator {
public:
    bool checkFinish(const Command &command) override {
        ++commandCount;
        if (commandCount == commandSize) {
            commandCount = 0;
            return true;
        }
        return false;
    }

    static void setCommandSize(int value) {
        commandSize = value;
    }
private:
    static int commandSize = 3;
    int commandCount = 0;
};

class DynamicTerminator : public Terminator {
public:
    bool checkFinish(const Command &command) override {
        if ( command.compare("{") ) {
            ++m_counter;
            return false;
        } else if (command.compare("}")) {
            --counter;
            if ( !counter )
                return true;
        }
    }
private:
    int m_counter = 0;
};

#endif // BLOCKBUILDER_H
